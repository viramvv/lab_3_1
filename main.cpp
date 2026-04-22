#include <iostream>
#include "Real.h"

// ФУНКЦІЯ, що одержує і повертає об'єкт базового класу
// Тут демонструється ПРИНЦИП ПІДСТАНОВКИ
Number demoSubstitution(Number n) {
    std::cout << "Функція отримала: " << std::string(n) << std::endl;
    return n.multiply(Number(2.0));
}

int main() {
    Number n1(50.0);           // Звичайний об'єкт
    Real r1(64.0);             // Об'єкт похідного класу
    Number* ptr = new Real(8.0); // Вказівник базового класу на об'єкт похідного

    Real array[2] = { Real(10.0), Real(25.0) };

    std::cout << "--- Вивід через приведення до string ---" << std::endl;
    std::cout << "n1: " << std::string(n1) << std::endl;

    std::cout << "\n--- Використання методів Real ---" << std::endl;
    std::cout << "Корінь кубічний з 64: " << r1.root(3) << std::endl;
    std::cout << "PI в квадраті: " << Real::piPower(2) << std::endl;

    // Передаємо Real там, де очікується Number
    std::cout << "\n--- Принцип підстановки ---" << std::endl;
    Number result = demoSubstitution(r1);
    std::cout << "Результат після функції: " << std::string(result) << std::endl;

    // 5. ДЕМОНСТРАЦІЯ КОНТРОЛЮ АРГУМЕНТІВ (Помилка)
    // Якщо розкоментувати рядок нижче, програма завершиться з повідомленням
    // r1.root(0);

    delete ptr;
    return 0;
}