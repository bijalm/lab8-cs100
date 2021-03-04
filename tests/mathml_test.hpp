#ifndef __MATHML_TEST_HPP__
#define __MATHML_TEST_HPP__

#include "gtest/gtest.h"
#include "../headers/print.hpp"
#include "../headers/add.hpp"
#include "../headers/div.hpp"
#include "../headers/mult.hpp"
#include "../headers/sub.hpp"
#include "../headers/rand.hpp"
#include "../headers/pow.hpp"

TEST(MathMLTest, Sub10and6)
{
	Base* sub = new Sub(new Op(10),new Op(6));
	EXPECT_EQ("<math>\n  <apply>\n    <minus/>\n    <cn>10.000000</cn>\n    <cn>6.000000</cn>\n  </apply>\n</math>", print_mathML(sub)); 
	delete sub;
}

TEST(MathMLTest, Mult7and8)
{
        Base* mult = new Mult(new Op(7),new Op(8));
        EXPECT_EQ("<math>\n  <apply>\n    <times/>\n    <cn>7.000000</cn>\n    <cn>8.000000</cn>\n  </apply>\n</math>" , print_mathML(mult));
        delete mult;
}

TEST(MathMLTest, Add3and4)
{
        Base* add = new Add(new Op(3),new Op(4));
        EXPECT_EQ("<math>\n  <apply>\n    <plus/>\n    <cn>3.000000</cn>\n    <cn>4.000000</cn>\n  </apply>\n</math>",  print_mathML(add));
        delete add;
}

TEST(MathMLTest, Div4and1)
{
        Base* div = new Div(new Op(4),new Op(1));
        EXPECT_EQ("<math>\n  <apply>\n    <divide/>\n    <cn>4.000000</cn>\n    <cn>1.000000</cn>\n  </apply>\n</math>", print_mathML(div));
        delete div;
}


TEST(MathMLTest, Add1andSub5and1)
{
        Base* add1 = new Add(new Op(1),new Sub(new Op(5), new Op(1)));	
        EXPECT_EQ("<math>\n  <apply>\n    <plus/>\n    <cn>1.000000</cn>\n      <apply>\n        <minus/>\n        <cn>5.000000</cn>\n        <cn>1.000000</cn>\n      </apply>\n  </apply>\n</math>", print_mathML(add1));
        delete add1;
}

TEST(MathMLTest, Pow5and2)
{
        Base* pow = new Pow(new Op(5),new Op(2));
        EXPECT_EQ("<math>\n  <apply>\n    <power/>\n    <cn>5.000000</cn>\n    <cn>2.000000</cn>\n<  /apply>\n</math>" , print_mathML(pow));
        delete pow;
}

TEST(MathMLTest, DivMultPow)
{
        Base* divMult = new Div(new Mult(new Op(2),new Op(5)),new Pow(new Op(5), new Op(2)));
        EXPECT_EQ("<math>\n  <apply>\n    <divide/>\n      <apply>\n        <times/>\n        <cn>2.000000</cn>\n        <cn>5.000000</cn>\n      </apply>\n      <apply>\n        <power/>\n        <cn>5.000000</cn>\n        <cn>2.000000</cn>\n    <  /apply>\n  </apply>\n</math>", print_mathML(divMult));
        delete divMult;
}

#endif
