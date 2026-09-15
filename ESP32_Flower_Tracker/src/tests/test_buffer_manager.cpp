#include "/home/muffin/Documents/Projects/ESP32_Flower_Tracker/ESP32_Flower_Tracker/lib/buffer_manager/buffer_manager.h"
#include <array>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

struct sensors {
    std::string index0{"moisture"};
    std::string index1{"light"};
    std::string index2{"temperature"};
    std::string index3{"pressure"};
};

int main() {
    sensors sensors;
    std::vector<std::array<float, 4>> output{};
    std::array<float, 4> arr{};
    buffer_manager<float,16,4>manager{std::array<std::string, 4>{sensors.index0, sensors.index1, sensors.index2, sensors.index3}};
    std::array<float, 4> avg;
    while(true) {

        if(manager.get_item(0).is_full()) {

            if(manager.get_moving_average(avg, 16 / 4)) {
                output.push_back(avg);
            }
            int num{0};
            for(std::array<float, 4> out : output) {
                std::cout << num << ":    "<< "moisture: " << out[0] << " light: " << out[1] << " temperature: " << out[2] << " pressure: " << out[3] << "\n";
                num ++;
            }
            std::cout << '\n';
            std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        }
        
        for (float& v : arr) {
           v = static_cast<float>(rand()) / RAND_MAX * 100.0f; // 0-100
        }

        manager.buffer_add_values(arr);
    }
}