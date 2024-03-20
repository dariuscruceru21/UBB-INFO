//
// Created by Darius on 3/19/2024.
//

#include "Complex.h"
#include <cmath>

//constructor
Complex::Complex(double real, double imaginary) {
    realPart = real;
    imaginaryPart= imaginary;
}

double Complex::getRealPart() {
    return this->realPart;
}
double Complex::getImaginaryPart() {
    return this->imaginaryPart;
}

void Complex::setRealPart(double newRealPart) {
    this->realPart = newRealPart;
}

void Complex::setImaginaryPart(double newImaginaryPart) {
    this->imaginaryPart=newImaginaryPart;
}

Complex Complex::operator+(const Complex &number) const {
    double newRealPart, newImaginaryPart;
    newRealPart=this->realPart + number.realPart;
    newImaginaryPart=this->imaginaryPart + number.imaginaryPart;
    Complex result(newRealPart,newImaginaryPart);
    return result;
}

Complex Complex::operator-(const Complex &number) const {
    double newRealPart, newImaginaryPart;
    newRealPart=this->realPart - number.realPart;
    newImaginaryPart=this->imaginaryPart - number.imaginaryPart;
    Complex result(newRealPart,newImaginaryPart);
    return result;
}

Complex Complex::operator*(const Complex &number) const {//formula for multiplying two complex numbers
    double newRealPart, newImaginaryPart;
    newRealPart=this->realPart * number.realPart - this->imaginaryPart * number.imaginaryPart;
    newImaginaryPart=this->realPart * number.imaginaryPart + this->imaginaryPart * number.realPart;
    Complex result(newRealPart, newImaginaryPart);
    return result;
}

Complex Complex::operator/(const Complex &number) const {//formula for dividing two complex numbers
    double denominator = number.realPart * number.realPart + number.imaginaryPart * number.imaginaryPart;
    double newRealPart = (this->realPart * number.realPart + this->imaginaryPart * number.imaginaryPart) / denominator;
    double newImaginaryPart = (this->imaginaryPart * number.realPart - this->realPart * number.imaginaryPart) / denominator;
    Complex result(newRealPart, newImaginaryPart);
    return result;
}

double Complex::absolute() const{//formula for absolute of a complex number
    return sqrt(this->realPart * this->realPart + this->imaginaryPart * this->imaginaryPart);
}

std::pair<double,double> Complex::computePolar() const{//formula to compute to polar of a complex number
    double absoluteValue = absolute();//absolute value of complex number
    double theta = atan2(this->imaginaryPart, this->realPart);
    return std::make_pair(absoluteValue, theta);
}

std::string Complex::transformToString() const {
    std::string result;
    if (this->realPart == static_cast<int>(this->realPart))//if the real part is an int
        result = std::to_string(static_cast<int>(this->realPart));//converts it to an int
    else
        result = std::to_string(this->realPart);

    if (this->imaginaryPart >= 0)//if the imaginary part is positive we concanate a plus to it
        result += " + ";
    else
        result += " - ";//if its negative a minus

    // Check if the imaginary part is an integer
    if (this->imaginaryPart == static_cast<int>(this->imaginaryPart))//if imaginary part is an int
        result += std::to_string(static_cast<int>(std::abs(this->imaginaryPart))) + "i";//converts it to an int
    else
        result += std::to_string(std::abs(this->imaginaryPart)) + "i";

    return result;
}

