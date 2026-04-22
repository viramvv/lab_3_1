#include "Number.h"
#include <iostream>

Number::Number() : value(0.0) {}

Number::Number(double val) {
    setValue(val); // Використовуємо сетер для перевірки навіть у конструкторі
}

void Number::setValue(double val) {
    // ПЕРЕВІРКА НА КОРЕКТНІСТЬ: Приклад - число не повинно бути "не числом" (NaN)
    if (val != val) { 
        std::cerr << "Помилка: Недопустиме значення (NaN)!" << std::endl;
        exit(1); // Завершення роботи при помилці за умовою завдання
    }
    value = val;
}

double Number::getValue() const {
    return value;
}

// Реалізація віднімання: повертає новий об'єкт Number
Number Number::subtract(const Number& other) const {
    return Number(this->value - other.value);
}

// Реалізація множення: повертає новий об'єкт Number
Number Number::multiply(const Number& other) const {
    return Number(this->value * other.value);
}

Number::operator std::string() const {
    return std::to_string(value);
}