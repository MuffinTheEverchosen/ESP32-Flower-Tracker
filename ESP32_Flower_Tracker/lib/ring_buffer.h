#pragma once

#include <array>
#include <cstddef>

template<typename T, size_t Capacity>
class ring_buffer {
    private:
    std::array<T, Capacity> buffer;
    size_t head{0}; //write index
    size_t tail{0}; //read index
    size_t count{0}; //num of elements in buffer

    public:

    bool add(const T& input) {
        if(is_full()) {
            return false;
        }

        buffer[head] = input;
        head = (head+1) % Capacity;
        count++;

        return true;
    }

    bool get(T& output) {
        if (is_empty()) {
            return false;
        }

        output = buffer[tail];
        tail = (tail+1) % Capacity;
        count--;

        return true;
    }

    bool is_empty() {
        if(count == 0) {
            return true;
        } else {
            return false;
        }
    }

    bool is_full() {
        if(count == Capacity) {
            return true;
        } else {
            return false;
        }
    }

    int num_of_elements_in_buffer() {
        return count;
    }

    float get_average() {
        float sum{};
        for(T value : buffer) {
            sum += value;
        }
        
        return sum / count;
    }
};