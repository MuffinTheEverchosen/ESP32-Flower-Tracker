#include "Arduino.h"
#include "HardwareSerial.h"
#include "Wire.h"
#include "esp32-hal.h"
#include <cstdint>
#include <BH1750.h>
#include <DisplayMenu.h>

BH1750 lightSensor;

ThreadSafeOLED safeOled;
DisplayMenu menu(&safeOled);

constexpr uint8_t ADR_OLED{0x3C};
constexpr uint8_t ADR_BMP280{0x76};
constexpr uint8_t ADR_BH1750{0x23};

float lux{};



void setup() {
    Serial.begin(115200);

    Wire.begin();

    menu.setup();
    menu.setScale(1);
    menu.addItem("Light:", &lux);

    lightSensor.begin(BH1750::ONE_TIME_LOW_RES_MODE,ADR_BH1750);
    Serial.println(F("BH1750 One-Time Test"));
}  

void loop() {
    lightSensor.configure(BH1750::ONE_TIME_HIGH_RES_MODE);
    while (!lightSensor.measurementReady(true)) {
        yield();
    }
    lux = lightSensor.readLightLevel();
    
    Serial.print("Light: ");
    Serial.print(lux);
    Serial.println(" lx");
    menu.repaint();
    delay(100);
}