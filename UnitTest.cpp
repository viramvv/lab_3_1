#include <gtest/gtest.h>
#include "Real.h"

// Тест базового класу Number
TEST(NumberTest, BasicOperations) {
    Number n1(10.0);
    Number n2(4.0);

    Number res_sub = n1.subtract(n2);
    Number res_mul = n1.multiply(n2);

    EXPECT_DOUBLE_EQ(res_sub.getValue(), 6.0);
    EXPECT_DOUBLE_EQ(res_mul.getValue(), 40.0);
}

// Тест приведення до рядка
TEST(NumberTest, StringConversion) {
    Number n(12.34);
    std::string s = (std::string)n;
    // std::to_string може додавати нулі, тому перевіряємо через find або substr
    EXPECT_NE(s.find("12.34"), std::string::npos);
}

// Тест похідного класу Real
TEST(RealTest, RootCalculation) {
    Real r(16.0);
    EXPECT_DOUBLE_EQ(r.root(2), 4.0);
    EXPECT_DOUBLE_EQ(r.root(4), 2.0);
}

// Тест статичного методу PI
TEST(RealTest, PiPower) {
    // PI^1 має бути приблизно 3.14159
    EXPECT_NEAR(Real::piPower(1), 3.14159, 0.0001);
}

// Тест принципу підстановки
TEST(SubstitutionTest, PolyTest) {
    Real r(5.0);
    Number* basePtr = &r; // Базовий вказівник на похідний об'єкт

    Number res = basePtr->multiply(Number(2.0));
    EXPECT_DOUBLE_EQ(res.getValue(), 10.0);
}