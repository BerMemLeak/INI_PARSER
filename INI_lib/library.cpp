#include "library.h"

ini_parser::ini_parser(const std::string& filename) : filename("../" + filename) {
    parse_file();
}

void ini_parser::parse_file() {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Не удалось открыть файл");
    }

    std::string line, current_section;
    int line_number = 0;

    while (std::getline(file, line)) {
        line_number++;
        line = trim(line);
        if (line.empty() || line[0] == ';') {
            continue;
        } else if (line[0] == '[' && line.back() == ']') {
            current_section = line.substr(1, line.size() - 2);
        } else {
            size_t equal_pos = line.find('=');
            if (equal_pos == std::string::npos) {
                throw std::invalid_argument("Ошибка в синтаксисе файла " + std::to_string(line_number));
            }
            std::string key = trim(line.substr(0, equal_pos));
            std::string value = trim(line.substr(equal_pos + 1));
            data[current_section][key] = value;
        }
    }
}

std::string ini_parser::trim(const std::string& str) {
    const std::string whitespace = "\t";
    size_t start = str.find_first_not_of(whitespace);
    if (start == std::string::npos)
        return "";
    size_t comment_pos = str.find(';');
    if (comment_pos != std::string::npos && comment_pos > start) {
        return str.substr(start, comment_pos - start);
    }
    size_t end = str.find_last_not_of(whitespace);
    return (end == std::string::npos) ? "" : str.substr(start, end - start + 1);
}
