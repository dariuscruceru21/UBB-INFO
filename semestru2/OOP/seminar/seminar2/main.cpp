#include <iostream>
#include "Bancnote.cpp"
int main() {
    Bancnote money(1000);
    money.add(100);
    money.subtract(500);
    std::cout<<"Current balance is "<<money.balance();

    return 0;
}
