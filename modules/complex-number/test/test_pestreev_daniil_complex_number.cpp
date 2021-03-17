// Copyright 2021 Pestreev Daniil

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Pestreev_Daniil_ComplexNumberTest, Div_by_Zero) {
    double re = 0.0;
    double im = 0.0;

    ComplexNumber c(re, im);
    ASSERT_ANY_THROW(c / c);
}

TEST(Pestreev_Daniil_ComplexNumberTest, Exponentiation_of_two) {
    ComplexNumber c1(3, 3);
    ComplexNumber c2(3, 3);
    ComplexNumber mult = c1 * c2;
    ComplexNumber res(0, 18);
    ASSERT_TRUE(mult == res);
}

TEST(Pestreev_Daniil_ComplexNumberTest, Exponentiation_i) {
    ComplexNumber c1(0, 1);
    ComplexNumber c1_ext2 = c1 * c1;
    ASSERT_EQ(-1, c1_ext2.getRe());
    ASSERT_EQ(0, c1_ext2.getIm());
    ComplexNumber c1_ext5 = c1_ext2 * c1_ext2 * c1;
    ASSERT_EQ(0, c1_ext5.getRe());
    ASSERT_EQ(1, c1_ext5.getIm());
}
