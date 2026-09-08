#include "/home/muffin/Documents/Projects/ESP32_Flower_Tracker/ESP32_Flower_Tracker/lib/buffer_manager/buffer_manager.h"
#include <array>
#include <string>

int main() {
    buffer_manager<float,16,4>manager{std::array<std::string, 4>{"moisture", "light", "temperature", "pressure"}};

    manager.buffer_step(std::array<float, 4>{0.45, 50000, 23.532, 1024.2345});
    manager.buffer_step(std::array<float, 4>{0.43, 50542, 24, 1024.5323});
    manager.buffer_step(std::array<float, 4>{0.41, 54235, 25, 1024.3253});
}