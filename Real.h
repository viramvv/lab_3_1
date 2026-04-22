#ifndef REAL_H
#define REAL_H

#include "Number.h"

// КЛАС Real успадковує Number (Відкрите успадкування)
class Real : public Number {
public:
    Real();
    Real(double val);

    // Метод обчислення кореня довільного степеня
    double root(double degree) const;

    // Метод обчислення PI в заданому степені
    static double piPower(double degree);
};

#endif