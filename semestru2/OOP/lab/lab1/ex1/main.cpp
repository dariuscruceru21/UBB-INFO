#include <iostream>
#include <cassert>
#include "Rational.h"
#include "Rational.cpp"


int main() {


    {//Test case for add function
       Rational number1(13,28);
       Rational number2(5,17);
       Rational sum = number1 + number2;
       assert(sum.getNumerator()==361);
       assert(sum.getDenumerator()==476);
    }

    {//Test case for subtract functions
       Rational number1(13,28);
       Rational number2(5,17);
       Rational subtract = number1 - number2;
       assert(subtract.getNumerator()==81);
       assert(subtract.getDenumerator()==476);}


    {//test case for multiply
        Rational number1(13,28);
        Rational number2(5,15);
        Rational multiplication = number1 * number2;
        assert(multiplication.getNumerator()==13);
        assert(multiplication.getDenumerator()==84);
    }

    {//test case for reduce function
        Rational number1(2,4);
        number1.reduce();
        assert(number1.getNumerator()==1);
        assert(number1.getDenumerator()==2);
    }
    {//test case for inverse function
        Rational number1(2,4);
        number1.inverse();
        assert(number1.getNumerator()==4);
        assert(number1.getDenumerator()==2);
    }


    {//test case for compare
        Rational number1(1,2);
        Rational number2(1,3);
        assert(number1.compare(number2)==1);
    }
    {//test case for division
        Rational number1(1,2);
        Rational number2(1,3);
        Rational division = number1 / number2;
        assert(division.getNumerator()==3);
        assert(division.getDenumerator()==2);
    }

    cout<<"All test run succsesfully"<<std::endl;

    Rational number1(12, 4);
    Rational number2(8,3);
    Rational number3(1,8);
    Rational number4(7,4);
    Rational number5(4,13);
    Rational sum = number1 + number2 + number3 + number4 + number5;
    std::cout<<sum.getNumerator()<<'/'<<sum.getDenumerator();


    return 0;
}
