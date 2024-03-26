#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;


Bag::Bag() {
	//TODO - Implementation
    this->capacity = 5;
    this->lenght = 0;
    this->nrElemente = 0;
    this->elements = new std::pair<TElem,int>[this->capacity];


}


void Bag::add(TElem elem) {
	//TODO - Implementation
    //Best-Case Complexity:Theta(1)
    //Worst-Case Complexity:O(n)
    //Average-Case Complexity:O(n)
    if(this->isEmpty())//if the bag is empty it makes a pair and sets the length to 1
    {
      this->nrElemente ++;
      this->elements[this->lenght++] = make_pair(elem, 1);
      return;
    }

    for(int index = 0; index < this->lenght; index++) {
        if (this->elements[index].first == elem) {
            if(this->lenght < this->capacity)
            { this->elements[index].second += 1;
                this->nrElemente += 1;
                return;
            }
            else{
                resizeUp();
                this->elements[index].second += 1;
                this->nrElemente += 1;
                return;
            }

        }
    }

    if(this->lenght == this->capacity)
        this->resizeUp();

    this->nrElemente += 1;
    this->elements[lenght] = make_pair(elem,1);//if the element is not found it increments the length and adds the new pair
    this->lenght++;
}


bool Bag::remove(TElem elem) {
	//TODO - Implementation
    //Best-Case Complexity:Theta(1)
    //Worst-Case Complexity:O(n)
    //Average-Case Complexity:O(n)
    if (this->isEmpty() == true)
        return false;


    if(this->search(elem)==false)
        return false;

    for(int index = 0; index < this->lenght; index++){
        if(this->elements[index].first == elem) {
            if (this->elements[index].second > 1) {
                this->elements[index].second -= 1;
                this->nrElemente -= 1;
                if(this->lenght < this->capacity/4)
                    resizeDown();
                return true;
            } else {
                for (int j = index; j < this->lenght - 1; j++)
                    elements[j] = elements[j + 1];
                this->nrElemente --;
                this->lenght -= 1;
                if(this->lenght < this->capacity/4)
                    resizeDown();
                return true;

            }
        }
    }
}


bool Bag::search(TElem elem) const {
	//TODO - Implementation
    //Best-Case Complexity:Theta(1)
    //Worst-Case Complexity:O(n)
    //Average-Case Complexity:O(n)
    for(int index = 0; index < lenght; index++)
        if(this->elements[index].first== elem)
            return true;
    return false;

}

int Bag::nrOccurrences(TElem elem) const {
	//TODO - Implementation
    //Best-Case Complexity:Theta(1)
    //Worst-Case Complexity:O(n)
    //Average-Case Complexity:O(n)
    if(this->isEmpty() == true)
        return 0;

    for(int index = 0; index < this->lenght; index++)
        if(this->elements[index].first == elem)
            return elements[index].second;


    //if element not found return 0
    return 0;
}


int Bag::size() const {
    //TODO - Implementation
    //Complexity:Theta(1)
    if(this->lenght > 0)
        return this->nrElemente;
    return 0;
}


bool Bag::isEmpty() const {
    //TODO - Implementation
    //Complexity:Theta(1)
    return this->lenght == 0;
}

BagIterator Bag::iterator() const {
	return BagIterator(*this);
}


Bag::~Bag() {
    //TODO - Implementation
    //Complexity:O(n)
    delete[] this->elements;
}


void Bag::resizeUp() {
    //Complexity:O(n)
    int newCapacity = this->capacity * 2;
    std::pair<TElem, int>* newElements = new std::pair<TElem, int>[newCapacity];
    for (int index = 0; index < this->lenght; index++) {
        newElements[index] = this->elements[index];
    }
    delete[] this->elements;
    this->elements = newElements;
    this->capacity = newCapacity;
}


void Bag::resizeDown() {
    //Complexity:O(n)
    this->capacity /= 2;
    std::pair<TElem, int>* newElements = new std::pair<TElem, int>[this->capacity];
    for (int index = 0; index < this->lenght; index++) {
        newElements[index] = this->elements[index];
    }
    delete[] this->elements;
    this->elements = newElements;

}

