// Copyright 2021 Pestreev Daniil

#include <gtest/gtest.h>
#include <cmath>

#include <limits>
#include "include/complex_number.h"

TEST(Pestreev_Daniil_ComplexNumberTest, Sequence_of_actions) {
    ComplexNumber c1(2, 2);
    ComplexNumber c2(-2, 2);
    ComplexNumber c3(2, 63);
    ComplexNumber c4(0, 10);
    ComplexNumber c = c1 + c2 * c3 * (c4 - c3);
    ASSERT_EQ(c.getRe(), -6204);
    ASSERT_EQ(c.getIm(), 7136);
}

TEST(Pestreev_Daniil_ComplexNumberTest, Modulo_comparison) {
    double m = 1001.0;
    ComplexNumber c1(m, m);
    ComplexNumber c2(m + 1.0, m + 1.0);
    double mod1 = sqrt(c1.getRe() * c1.getRe() + c1.getIm() * c1.getIm());
    double mod2 = sqrt(c2.getRe() * c2.getRe() + c2.getIm() * c2.getIm());
    ASSERT_TRUE(mod1 < mod2);
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
