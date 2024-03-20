//
// Created by Darius on 3/18/2024.
//

#include "Rational.h"
#include <numeric>
#include <stdexcept>

using namespace std;

//constructor
Rational::Rational(int num, int denum) {
    if (denum == 0) {
        throw std::invalid_argument("Denominator cannot be zero.");
    }
    numerator = num;
    denominator = denum;
}

int Rational::getNumerator() const {
    return this->numerator;
}

int Rational::getDenumerator() const {
    return this->denominator;
}


void Rational::setNumerator(int newNumerator) {
    this->numerator = newNumerator;
}

void Rational::setDenumerator(int new_denumerator) {
    this->denominator = new_denumerator;
}

Rational Rational::operator+(const Rational &number) const {
    int new_numerator, new_denominator;

    if (this->denominator == number.denominator) {
        new_numerator = this->numerator + number.numerator;
        new_denominator = this->denominator;
    } else {
        new_numerator = this->numerator * number.denominator + number.numerator * this->denominator;
        new_denominator = this->denominator * number.denominator;
    }
    Rational result(new_numerator, new_denominator);
    result.reduce();
    return result;
}

Rational Rational::operator-(const Rational &number) const {
    int new_numerator, new_denominator;

    if (this->denominator == number.denominator) {
        new_numerator = this->numerator - number.numerator;
        new_denominator = this->denominator;
    } else {
        new_numerator = this->numerator * number.denominator - number.numerator * this->denominator;
        new_denominator = this->denominator * number.denominator;
    }
    Rational result(new_numerator, new_denominator);
    result.reduce();
    return result;
}

Rational Rational::operator*(const Rational &number) const {
    int new_numerator, new_denominator;
    new_numerator = this->numerator * number.numerator;
    new_denominator = this->denominator * number.denominator;
    Rational result(new_numerator, new_denominator);
    result.reduce();
    return result;
}

void Rational::reduce() {
    int gcd_number = gcd(this->numerator, this->denominator);
    this->numerator /= gcd_number;
    this->denominator /= gcd_number;
}

void Rational::inverse() {
    int auxiliar = getNumerator();
    setNumerator(this->denominator);
    setDenumerator(auxiliar);
}


int Rational::compare(Rational number) {
    int cross_product = this->numerator * number.denominator - number.numerator * this->denominator;
    if (cross_product > 0)
        return 1;//first number is bigger
    else if (cross_product < 0)
        return -1;//second number is bigger
    else
        return 0;//they are equal
}

Rational Rational::operator/(const Rational &number) const {
    int new_numerator, new_denominator;
    new_numerator = this->numerator * number.denominator;
    new_denominator = this->denominator * number.numerator;
    Rational result(new_numerator, new_denominator);
    result.reduce();
    return result;

}
//void Rational::add(Rational number) {
//
//    if(this->denominator == number.denominator)//if the denominator is equal we just add the numerators
//    {   Rational result(this->numerator + number.numerator, this->denominator);
//        result.reduce();
//        cout<<result.getNumerator()<<'/'<<result.denominator;
//
//    }
//    else{   //if they are not equal we must multiply both numerators with the others denominator and bot denumerators
//        int new_numerator= this->numerator * number.denominator + number.numerator * this->denominator;
//        int new_denumerator=this->denominator * number.denominator;
//        Rational result(new_numerator, new_denumerator);
//        result.reduce();
//        this->numerator = result.getNumerator();
//        this->denominator = result.getDenumerator();
//        cout<<this->numerator<<'/'<<this->denominator;
//
//    }
//}
//
//void Rational::substrakt(Rational number) {
//    if(this->denominator == number.denominator && this->numerator != number.numerator)//if the denominator is equal we just substract the numerators
//    { Rational result(this->numerator - number.numerator, this->denominator);
//        result.reduce();
//        cout<<result.getNumerator()<<'/'<<result.getDenumerator();
//    }
//    else
//        if(this->denominator != number.denominator){//if they are not equal we must multiply both numerators with the others denominator and both denumerators
//            int new_numerator= this->numerator * number.denominator - number.numerator * this->denominator;
//            int new_denumerator=this->denominator * number.denominator;
//            Rational result(new_numerator, new_denumerator);
//            result.reduce();
//            this->numerator = result.getNumerator();
//            this->denominator = result.getDenumerator();
//            cout<<this->numerator<<'/'<<this->denominator;
//        }
//        else
//            if(this->numerator == number.numerator)//if both numeratrs are 0 it prints a messsage because that does not work
//                cout<<"Division by 0";
//
//}
//
//void Rational::multiply(Rational number) {
//    int new_numerator=this->numerator * number.numerator;
//    int new_denumerator=this->denominator * number.denominator;
//    Rational result(new_numerator,new_denumerator);
//    result.reduce();
//    this->numerator = result.getNumerator();
//    this->denominator = result.getDenumerator();
//    cout<<this->numerator<<'/'<<this->denominator;
//
//}
//
//void Rational::reduce() {
//    int gcd_number = gcd(this->numerator, this->denominator);
//    this->numerator /= gcd_number;
//    this->denominator /=gcd_number;
//}
//
//void Rational::inverse() {
//    int auxiliar = getNumerator();
//    setNumerator(this->denominator);
//    setDenumerator(auxiliar);
//}
//
//int Rational::compare(Rational num) {
//    int cross_product = this->numerator * num.denominator - num.numerator * this->denominator;
//    if(cross_product > 0)
//        return 1;//first number is bigger
//    else
//        if(cross_product < 0)
//            return -1;//second number is bigger
//        else
//            return 0;//they are equal
//}