#include "library.h"
#include <iostream>
#include <string>



int main() {
    try {
        ini_parser parser("ini.txt");
        auto value = parser.get_value<double>("Section1", "var1");
        std::cout << "Значение: " << value << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
    return 0;
}
