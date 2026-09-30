#pragma once

#include <array>
#include <cstddef>
#include "/home/muffin/Documents/Projects/ESP32_Flower_Tracker/ESP32_Flower_Tracker/lib/ring_buffer.h"

template<typename T, size_t Capacity, size_t num_of_buffers>
class buffer_manager {
    private:
        std::array<ring_buffer<T, Capacity>, num_of_buffers> items{};
        using acc_t = std::conditional_t<std::is_floating_point_v<T>, T, std::int32_t>;
    public:
        bool buffer_add_values(const std::array<T, num_of_buffers>& new_values) {      
            for(size_t i{0}; i < num_of_buffers; i++) {
                bool test = this->items[i].add_value(new_values[i]);
                
                if(!test) {
                    return false;
                }
            }

            return true;
        }

        bool get_moving_average(std::array<T, num_of_buffers>& output, const size_t amount_of_data_to_keep) {
            if (amount_of_data_to_keep > Capacity) return false;
            for(ring_buffer<T, Capacity>& buffer : this->items) {
                if(!buffer.is_full()) return false;
            }
            
            size_t tail_steps{Capacity - amount_of_data_to_keep};
            
            for(size_t buffer_index{}; buffer_index < num_of_buffers; buffer_index++) {
                acc_t buffer_sum{};

                for(size_t value_index{}; value_index < Capacity; value_index++) {
                    T value{};
                    if(!this->items[buffer_index].peek(value_index, value)) {
                        return false;
                    }

                    buffer_sum += value;  
                }

                output[buffer_index] = static_cast<T>(buffer_sum / static_cast<acc_t>(Capacity));

                this->items[buffer_index].drop_oldest(tail_steps);
            }

            return true;
        }

        ring_buffer<T, Capacity>& get_item(size_t id) {
            return this->items[id];
        }
};