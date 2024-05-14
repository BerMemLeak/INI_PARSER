# Курсовой проект «Парсер INI-файлов»

Курсовой проект — простой парсер файлов формата INI.

## Содержание

### 1. Введение
INI-файлы — это обычные текстовые файлы, которые можно редактировать и просматривать при помощи любого текстового редактора.
INI-файлы приобрели популярность в Windows, хотя могут использоваться в любой ОС. Несложная структура этого формата позволяет легко обрабатывать их программно и имеет достаточно понятный вид для чтения и изменения человеком.

### 2. Формат INI-файлов
INI-файлы могут содержать типы строк:
* Строка имени секции — обозначает имя новой секции переменных. 
Имеет формат: ` [имя_секции] `. <br/> Пробелы и символы табуляции, стоящие до открывающей и после закрывающей скобки, игнорируются.

* Строка задания переменной — задаёт значение переменной. 
Имеет формат: ` название_переменной = значение_переменной `. <br /> Количество пробелов между символами равенства может быть произвольным.
Для простоты будем считать, что значения могут быть либо строкой, либо числом. Несколько значений не допускается.

* Строка комментариев. 
Имеет формат: ` ; строка комментариев `. <br/> 

### 3. Общая структура INI-файла
Пример структуры INI-файла:
```INI
[Section1]
; комментарий о разделе
var1=5.0 ; иногда допускается комментарий к отдельному параметру
var2=какая-то строка
  
[Section2]
var1=1
var2=значение_2

; Иногда значения отсутствуют, это означает, что в Section3 нет переменных 
[Section3]
[Section4]
Mode=
Vid=

; Секции могут повторяться
[Section1]
var3=значение
var1=1.0 ; переприсваиваем значение
```

### 4. Пример работы парсера
Реализован класс парсера INI-файлов, который предоставляет для пользователя одну шаблонную функцию, позволяющую получить значение переменной в определённой секции. 
 ```C++
#include <iostream>
#include "library.h"

int main() {
    try {
        ini_parser parser("ini.txt");
        auto value = parser.get_value<std::string>("Section1", "var1");
        std::cout << "Значение: " << value << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
    return 0;
}
 ```
