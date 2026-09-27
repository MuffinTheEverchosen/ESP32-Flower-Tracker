#include "Arduino.h"
#include "DisplayMenu.h"
#include "esp32-hal.h"
#include <bmp280_ltsm.hpp>
#include <cstdint>


constexpr uint8_t ADR_BMP280{0x76};
constexpr uint32_t I2C_BUS_SPEED = 100000;

BMP280_Sensor bmp280(ADR_BMP280, &Wire, I2C_BUS_SPEED);

ThreadSafeOLED safeOled;
DisplayMenu menu(&safeOled);

float temperature{};
float pressure{};

void setup() {
    Wire.begin();

    bmp280.InitSensor();
    bmp280.setPowerMode(BMP280_Sensor::PowerMode_e::Forced);

    menu.setup();
    menu.setScale(1);
    menu.addItem("Temperature:", &temperature);
    menu.addItem("Pressure:", &pressure);
}

void loop() {
    if(bmp280.takeForcedMeasurement()) {
        temperature = bmp280.readTemperature();
        pressure = bmp280.readPressure(BMP280_Sensor::PressureUnit_e::hPa);
        menu.repaint();
    }
    delay(100);
}