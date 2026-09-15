#include <array>
#include <cstddef>
#include <string>
#include "/home/muffin/Documents/Projects/ESP32_Flower_Tracker/ESP32_Flower_Tracker/lib/ring_buffer.h"

template<typename T, size_t Capacity, size_t num_of_buffers>
class buffer_manager {
    private:
        std::array<ring_buffer<T, Capacity>, num_of_buffers> items{};
        std::array<std::string, num_of_buffers> buffers_name{};
    public:
        buffer_manager(const std::array<std::string, num_of_buffers> names_of_buffers) {
            this->buffers_name = names_of_buffers;
        }

        bool buffer_add_values(const std::array<T, num_of_buffers>& new_values) {      
            for(int i{0}; i < num_of_buffers; i++) {
                bool test = this->items[i].add_value(new_values[i]);
                
                if(!test) {
                    return false;
                }
            }

            return true;
        } ;

        bool get_moving_average(std::array<T, num_of_buffers>& output, const size_t amount_of_data_to_keep) {
            for(ring_buffer<T, Capacity>& buffer : this->items) {
                if(!buffer.is_full()) {
                    return false;
                }
            }
            
            size_t tail_steps{Capacity - amount_of_data_to_keep};
            
            for(int buffer_index{}; buffer_index < num_of_buffers; buffer_index++) {
                T buffer_sum{};

                for(int value_index{}; value_index < Capacity; value_index++) {
                    T value{};
                    if(!this->items[buffer_index].get_value(value)) {
                        return false;
                    }

                    buffer_sum += value;  
                }
                this->items[buffer_index].reset_tail(tail_steps);

                output[buffer_index] = buffer_sum / Capacity;
            }

            return true;
        }

        ring_buffer<T, Capacity>& get_item(size_t id) {
            return this->items[id];
        }
};