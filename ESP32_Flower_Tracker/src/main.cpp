#include "Arduino.h"
#include "BH1750.h"
#include "bmp280_ltsm.hpp"
#include "esp_attr.h"
#include <cstdint>
#include "/home/muffin/Documents/Projects/ESP32_Flower_Tracker/ESP32_Flower_Tracker/lib/buffer_manager.h"
#include <PY32LowPower.h>

constexpr uint8_t ADR_OLED{0x3C};
constexpr uint8_t ADR_BMP280{0x76};
constexpr uint8_t ADR_BH1750{0x23};

BMP280_Sensor bmp280(ADR_BMP280, &Wire);
BH1750 lightSensor;

RTC_DATA_ATTR buffer_manager<float, 16, 3> readings({"light", "pressure", "temperature"});

void setup() {
    
}  

void loop() {

}