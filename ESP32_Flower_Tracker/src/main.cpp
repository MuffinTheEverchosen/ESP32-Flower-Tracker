#include "Arduino.h"
#include "HardwareSerial.h"
#include "Wire.h"
#include "esp32-hal.h"
#include <cstddef>
#include <cstdint>

constexpr uint8_t ADR_OLED{0x3C};
constexpr uint8_t ADR_BMP280{0x76};
constexpr uint8_t ADR_BH1750{0x23};

constexpr uint8_t BH1750_Power_Down{0b00000000};
constexpr uint8_t BH1750_Power_Up{0b00000001};
constexpr uint8_t BH1750_Reset{0b00000111};
constexpr uint8_t BH1750_High_Resolution_Mode{0b00010000};

void setup() {
    Wire.begin();

    Serial.begin(115200);
    while(!Serial) {
        delay(10);
    }
    Serial.println("Serial communication established!");
}  

void loop() {
    Wire.beginTransmission(ADR_BH1750);
    Wire.write(BH1750_High_Resolution_Mode);
    Wire.endTransmission();
    delay(180);
    Wire.requestFrom(ADR_BH1750, size_t{2});
    uint8_t msb = Wire.read();
    uint8_t lsb = Wire.read();
    float lux = ((msb << 8) | lsb) / 1.2f;

    Serial.println("light: " + String{lux});

    delay(10);
}