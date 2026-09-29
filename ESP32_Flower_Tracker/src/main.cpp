#include "Arduino.h"
#include "BH1750.h"
#include "bmp280_ltsm.hpp"
#include "esp32-hal.h"
#include "esp_attr.h"
#include <cstdint>
#include "/home/muffin/Documents/Projects/ESP32_Flower_Tracker/ESP32_Flower_Tracker/lib/buffer_manager.h"

constexpr uint8_t ADR_OLED{0x3C};
constexpr uint8_t ADR_BMP280{0x76};
constexpr uint8_t ADR_BH1750{0x23};

BMP280_Sensor bmp280(ADR_BMP280, &Wire);
BH1750 lightSensor;

RTC_DATA_ATTR buffer_manager<float, 16, 3> readings({"light", "pressure", "temperature"});

void setup() {
    Wire.begin();

    lightSensor.begin(BH1750::ONE_TIME_LOW_RES_MODE, ADR_BH1750);

    bmp280.InitSensor();
    bmp280.setPowerMode(BMP280_Sensor::PowerMode_e::Forced);
}  

void loop() {
    lightSensor.configure(BH1750::ONE_TIME_LOW_RES_MODE);
    bmp280.takeForcedMeasurement();

    if(!lightSensor.measurementReady() || bmp280.Status)

}