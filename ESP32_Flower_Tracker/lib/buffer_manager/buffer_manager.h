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

        bool buffer_step(const std::array<T, num_of_buffers>& new_values) {
            if(!size_validation(new_values)) {
                return false;
            }
            
            for(int i{0}; i < num_of_buffers; i++) {
                bool test = this->items[i].add(new_values[i]);
                
                if(!test) {
                    return false;
                }
            }

            return true;
        };

        bool size_validation(const std::array<T, num_of_buffers>& item) {
            return item.size() == num_of_buffers;
        }

        ring_buffer<T, Capacity>& get_item(size_t id) {
            return this->items[id];
        }
};