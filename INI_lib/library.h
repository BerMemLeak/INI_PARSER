#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <stdexcept>

class ini_parser {
private:
    std::map<std::string, std::map<std::string, std::string>> data;
    std::string filename;

public:
    explicit ini_parser(const std::string& filename);

    template<typename T>
    T get_value(const std::string& section_name, const std::string& key) const {
        if (data.find(section_name) != data.end()) {
            const auto& section = data.at(section_name);
            if (section.find(key) != section.end()) {
                std::istringstream iss(section.at(key));
                T value;
                std::getline(iss, value);
                if (iss.fail()) {
                    throw std::invalid_argument("Ошибка преобразования значения");
                }
                return value;
            } else {
                std::string suggestions;
                for (const auto& pair : section) {
                    suggestions += pair.first + ", ";
                }
                if (!suggestions.empty()) {
                    suggestions.erase(suggestions.size() - 2); // удаление лишней запятой и пробела в конце
                    throw std::invalid_argument("Нет такой переменные, доступные переменные в этой секции: " + suggestions);
                } else {
                    throw std::invalid_argument("Ключ не найден в секции");
                }
            }
        } else {
            throw std::invalid_argument("Нет такой секции");
        }
    }


private:
    void parse_file();
    [[nodiscard]] static std::string trim(const std::string& str) ;
};

