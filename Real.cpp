#include "Real.h"
#include <cmath>
#include <iostream>

Real::Real() : Number(0.0) {}

Real::Real(double val) : Number(val) {}

double Real::root(double degree) const {
    if (degree == 0) {
        std::cerr << "Помилка: Корінь 0-го степеня не існує!" << std::endl;
        exit(1);
    }
    if (value < 0 && (int)degree % 2 == 0) {
        std::cerr << "Помилка: Корінь парного степеня з від'ємного числа!" << std::endl;
        exit(1);
    }
    // Формула: корінь n-го степеня це число в степені 1/n
    return std::pow(value, 1.0 / degree);
}

double Real::piPower(double degree) {
    const double PI = 3.14159265358979;
    return std::pow(PI, degree);
}