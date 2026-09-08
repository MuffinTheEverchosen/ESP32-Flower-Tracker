#include <cstdlib>
#include <iostream>
#include "/home/muffin/Documents/Projects/ESP32_Flower_Tracker/ESP32_Flower_Tracker/lib/ring_buffer.h"

int main() {
    ring_buffer<int, 4> buffer;
    int num{};

    while(true) {
        std::cout << "Podaj liczbę: ";
        std::cin >> num;

        if(num == 0) {
            int output{};
            if(buffer.get(output)) {
                std::cout << "Wyciągnięta liczba: " << output << '\n';
            } else {
                std::cout << "Błąd! buffer jest pusty!\n";
            }
        } else {
            if(buffer.add(num)) {
                std::cout << "Twoja liczba została dodana\n";
            } else {
                std::cout << "Błąd! buffer jest pełny\n";
            }
        }

        std::cout << "Obecna liczba elementów w buferze: " << buffer.num_of_elements_in_buffer() << '\n';
    }
}