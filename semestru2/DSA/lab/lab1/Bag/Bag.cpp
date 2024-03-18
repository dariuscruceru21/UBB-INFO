#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;


Bag::Bag() {
	//TODO - Implementation
    capacity=5;
    lenght=0;
    elements=new std::pair<TElem,int>[capacity];


}


void Bag::add(TElem elem) {//de refacut
	//TODO - Implementation

    this->iterator().first();
    if(isEmpty()){//daca bagul e gol
        elements[lenght]=std::make_pair(elem,1);
        lenght++;
    }
    else{
        if(lenght < capacity && search(elem)){//problemas
            elements[this->iterator().index].second++;
            lenght++;
        }
        else {
            if (lenght == capacity) {
                capacity = capacity * 2;
                pair<TElem, int> *new_elements = new std::pair<TElem,int>[capacity];
                this->iterator().first();
                while (this->iterator().valid())
                    new_elements[this->iterator().index] = elements[this->iterator().index];//copiem elementele din vectorul vechi in cel nou cu capactitatea dublata
                delete[] elements;
                elements = new_elements;
            }
            if(search(elem))
            {   elements[this->iterator().index].second++;
                lenght++;}
            else
            {
                lenght++;
                elements[lenght]= make_pair(elem,1);
            }
        }
    }
}


bool Bag::remove(TElem elem) {
	//TODO - Implementation
    exception excep;
    if(isEmpty())
        throw excep;

    this->iterator().first();//setam iteratorul la incepu
    if(!isEmpty()){
            if(search(elem)){
                if(elements[this->iterator().index].second > 1)
                {
                    elements[this->iterator().index].second--;
                    lenght--;
                    return true;
                }

                else if(elements[this->iterator().index].second==1)
                    {
                        elements[this->iterator().index]=elements[this->iterator().index+1];
                        lenght--;
                        return true;
                    }
            }
    }

    return false;
}


bool Bag::search(TElem elem) const {
	//TODO - Implementation
    this->iterator().first();
    if(!isEmpty()){
        while(this->iterator().valid()){
            if(elements[this->iterator().index].first==elem)
                return true;
            this->iterator().next();
        }
    }
	return false; 
}

int Bag::nrOccurrences(TElem elem) const {
	//TODO - Implementation
    if(search(elem))
        return elements[this->iterator().index].second;
	return 0; 
}


int Bag::size() const {
	//TODO - Implementation
    return lenght;
}


bool Bag::isEmpty() const {
	//TODO - Implementation
    if(lenght==0)
        return true;
	return false;
}

BagIterator Bag::iterator() const {
	return BagIterator(*this);
}


Bag::~Bag() {
    //TODO - Implementation
    delete [] elements;
}

