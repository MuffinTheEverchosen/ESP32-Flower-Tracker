#include "Arduino.h"
#include "BH1750.h"
#include "HardwareSerial.h"
#include "bmp280_ltsm.hpp"
#include "esp32-hal.h"
#include "esp_attr.h"
#include <cstdint>
#include "buffer_manager.h"

constexpr uint8_t ADR_OLED{0x3C};
constexpr uint8_t ADR_BMP280{0x76};
constexpr uint8_t ADR_BH1750{0x23};

BMP280_Sensor bmp280(ADR_BMP280, &Wire);
BH1750 lightSensor;

bool debug{false};

RTC_DATA_ATTR buffer_manager<float, 16, 3> readings({"light", "pressure", "temperature"});

void setup() {
    if(debug) Serial.begin(115200);

    Wire.begin();

    lightSensor.begin(BH1750::ONE_TIME_LOW_RES_MODE, ADR_BH1750);

    bmp280.InitSensor();
    bmp280.setPowerMode(BMP280_Sensor::PowerMode_e::Forced);
}  

void loop() {
    lightSensor.configure(BH1750::ONE_TIME_LOW_RES_MODE);
    bmp280.takeForcedMeasurement();

    float light{};
    float temperature{};
    float pressure{};

    if(!lightSensor.measurementReady()) {
        yield();
    } else {
        light = lightSensor.readLightLevel();
        temperature = bmp280.readTemperature();
        pressure = bmp280.readPressure(BMP280_Sensor::PressureUnit_e::hPa);


        if(readings.buffer_add_values({light, pressure, temperature})) {
            return;
        } else if (debug) {
            Serial.printf("Reading were not added");
        }
    }
}