//
// Created by Darius on 3/19/2024.
//

#include "Bancnote.h"
#include<stdexcept>


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
}

void Bancnote::subtract(float number) {
    if (this->sold - number < 0)
        throw std::invalid_argument("Dont't have enough money");
    else
        this->sold -= number;
}

float Bancnote::balance() {
    return this->sold;
}