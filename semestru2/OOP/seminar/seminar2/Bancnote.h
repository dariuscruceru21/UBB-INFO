//
// Created by Darius on 3/19/2024.
//

#ifndef SEMINAR2_BANCNOTE_H
#define SEMINAR2_BANCNOTE_H


class Bancnote {
    private:
        float sold;

    public:
        //constructor
        Bancnote (float sold);
        //geter for sold
        float getSold();
        //seter for sold
        void setSold(float newSold);
        //account balance
        float balance();
        //add money to balance
        void add(float number);
        //subtract money from sold
        void subtract(float number);


};


#endif //SEMINAR2_BANCNOTE_H
