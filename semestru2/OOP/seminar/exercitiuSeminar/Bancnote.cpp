//
// Created by Darius on 3/19/2024.
//

#include "Bancnote.h"
#include <fstream>
#include<stdexcept>


std::ofstream out("date.out");

Bancnote::Bancnote(float moneyInAccount) {
    sold = moneyInAccount;
}

float Bancnote::getSold() {
    return this->sold;
}

void Bancnote::setSold(float newSold) {
    this->sold = newSold;
}

void Bancnote::add(float number) {

    this->sold += number;
    out<<"IN";//<<number<<" "<<this->balance();
    out.close();
}

void Bancnote::subtract(float number) {
    std::ofstream out("date.out");

    if (this->sold - number < 0)
        throw std::invalid_argument("Dont't have enough money");
    else{
        this->sold -= number;
        out<<"OUT"<<number<<" "<<this->balance();
    }
    out.close();
}

float Bancnote::balance() {
    return this->sold;
}

;

