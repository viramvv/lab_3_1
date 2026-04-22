#ifndef NUMBER_H
#define NUMBER_H

#include <string>

class Number {
protected:
    double value; // Поле для зберігання числа

public:
    // Конструктори
    Number();
    Number(double val);

    // МЕТОДИ ВСТАНОВЛЕННЯ (Сетери) - Контролюють коректність
    void setValue(double val);

    // МЕТОДИ ОТРИМАННЯ (Гетери)
    double getValue() const;

    // Математичні операції за завданням
    Number subtract(const Number& other) const;
    Number multiply(const Number& other) const;

    // ПЕРЕТВОРЕННЯ ДО РЯДКА - реалізовано як оператор приведення типу
    operator std::string() const;
};

#endif