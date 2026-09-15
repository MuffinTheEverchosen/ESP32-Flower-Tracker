#pragma once

#include <array>
#include <cmath>
#include <cstddef>

template<typename T, size_t Capacity>
class ring_buffer {
    private:
    std::array<T, Capacity> buffer;
    size_t head{0}; //write index
    size_t tail{0}; //read index
    size_t count{0}; //num of elements in buffer

    public:

    bool add_value(const T& input, bool move_head = true) {
        if(is_full()) {
            return false;
        }

        buffer[head] = input;

        if(move_head) {
            advance_head();
        }

        return true;
    }

    bool advance_head(const int num_of_steps = 1) {
        for (int i{}; i < num_of_steps; i++) {
            this->head = (this->head + 1) % Capacity;
            count++;
        }

        return true;
    }

    bool get_value(T& output, bool move_tail = true) {
        if (is_empty()) {
            return false;
        }

        output = buffer[tail];

        if(move_tail) {
            advance_tail();
        }

        return true;
    }

    bool advance_tail(const int num_of_steps = 1) {
    for (int i{}; i < num_of_steps; i++) {
        this->tail = (this->tail + 1) % Capacity;
        count--;
        }

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

    void reset_tail(size_t position = 0) {
        this->tail = (this->head + position) % Capacity;
        this->count = Capacity - position;
    }
};