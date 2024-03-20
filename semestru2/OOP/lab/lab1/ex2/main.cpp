#include <iostream>
#include <string>
#include "Complex.cpp"
#include <cassert>

using namespace std;

int main() {
    {//test case for add operation
        Complex number1(3, 4);
        Complex number2(1, -6);
        Complex sum = number1 + number2;
        assert(sum.getRealPart() == 4);
        assert(sum.getImaginaryPart() == -2);
    }

    {//test case for subtraction operation
        Complex number1(3, 4);
        Complex number2(1, -6);
        Complex subtraction = number1 - number2;
        assert(subtraction.getRealPart() == 2);
        assert(subtraction.getImaginaryPart() == 10);
    }

    {//test case for multiply operation
        Complex number1(3, 4);
        Complex number2(1, -6);
        Complex multiplication = number1 * number2;
        assert(multiplication.getRealPart() == 27);
        assert(multiplication.getImaginaryPart() == -14);
    }

    {//test case for division operation
        Complex number1(10, 3);
        Complex number2(2, 1);
        Complex division = number1 / number2;
        assert(division.getRealPart() == 4.6);
        assert(division.getImaginaryPart() == -0.8);
    }

    {//test case for absolute of a complex number
        Complex number(3, 4);
        assert(number.absolute() == 5);
    }

    {//test case for compute polar
        Complex number(3, 4);
        assert(number.computePolar().first == 5);
        assert(number.computePolar().second == 0.92729521800161219);
    }

    {//test case for trasnform to string
        Complex number(3, 4);
        string result = "3 + 4i";
        assert(number.transformToString() == result);
    }

    Complex number1(1, 2);
    Complex number2(3, 12);
    Complex number3(4, 19);
    Complex number4(2, 7);
    Complex number5(7, 2);
    Complex sum = number1 + number2 + number3 + number4 + number5;
    std::cout << sum.transformToString();

    return 0;
}
