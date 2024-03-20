//
// Created by Darius on 3/19/2024.
//

#ifndef EX2_COMPLEX_H
#define EX2_COMPLEX_H
#include <string>

class Complex {
     private:
            double realPart;
            double imaginaryPart;

    public:
            //constructor
            Complex(double real, double imaginary);

            //geter for real Part
            double getRealPart();

            //geter for imaginary Part
            double getImaginaryPart();

            //seter for real Part
            void setRealPart(double newRealPart);

            //seter for imaginary Part
            void setImaginaryPart(double newImaginaryPart);

            //add operation for objects type complex
            Complex operator+(const Complex& number) const;

            //subtract operation for objects type complex
            Complex operator-(const Complex& number) const;

            //multiply operation for objects type complex
            Complex operator*(const Complex& number) const;

            //division operation for objects type complex
            Complex operator/(const Complex& number) const;

            //absolute of an object type complex
            double absolute() const;

            //computes an object type complex to it s polar
            std::pair<double,double> computePolar() const;

            //transform object type complex in a string
            std::string transformToString() const;

};


#endif //EX2_COMPLEX_H
