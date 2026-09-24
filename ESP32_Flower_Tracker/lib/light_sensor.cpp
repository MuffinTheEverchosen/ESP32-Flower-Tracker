#include "Wire.h"
#include <cstdint>

constexpr uint8_t BH1750_Power_Down{0b00000000};
constexpr uint8_t BH1750_Power_Up{0b00000001};
constexpr uint8_t BH1750_Reset{0b00000111};
constexpr uint8_t BH1750_High_Resolution_Mode{0b00010000};

class light_sensor {
    private:
        uint8_t addr;
        TwoWire& wire;
    public:
        light_sensor(const uint8_t addr, TwoWire& wire_bus)
            : addr{addr}, wire{wire_bus} {};
};