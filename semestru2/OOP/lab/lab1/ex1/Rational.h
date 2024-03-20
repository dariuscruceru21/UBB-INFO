//
// Created by Darius on 3/18/2024.
//

#ifndef EX1_RATIONAL_H
#define EX1_RATIONAL_H


class Rational {

private:
    int numerator;
    int denominator;

public:
      //constructor
      Rational(int num, int denum);
      //gets numerator
      int getNumerator() const;
      //gets nominator
      int getDenumerator() const;
      //sets numerator to a value
      void setNumerator(int numerator);
      //sets denominator to a value
      void setDenumerator(int denumerator);
      //reduces an object type Rational
      void reduce();
      //inverse an object type rational
      void inverse();
      //compare two objects type rational number
      int compare(Rational num);
      //function to use + For addition of two objects type Rationa;
      Rational operator+(const Rational& number) const;
      //function to use - For subtraction of two objects type Rational;
      Rational operator-(const Rational& number) const;
      //function to use * For multiplikation of two objects type Rational;
      Rational operator*(const Rational& number) const;
      //function to use / For division of two objects type Rational;
      Rational operator/(const Rational& number) const;

    //    //adds two objects type rational
    //    void add(Rational num);
    //    //substract two objects type rational together
    //    void substrakt(Rational num);
    //    //multiplies two objects type rational toegther
    //    void multiply(Rational num);
    //    //divides two objects type rational together
    //    void divide(Rational num);
    //    //reduces an object type rational

};


#endif //EX1_RATIONAL_H
