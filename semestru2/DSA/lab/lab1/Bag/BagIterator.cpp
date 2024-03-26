#include <exception>
#include "BagIterator.h"
#include "Bag.h"
#include <stdexcept>


using namespace std;


BagIterator::BagIterator(const Bag& c): bag(c)
{
	//TODO - Implementation
    this->index = 0;
    this->frq_index = 1;
}

void BagIterator::first() {//sets the index two the first element of the dynamic array. Complexity: Theta(1)
	//TODO - Implementation
    //Complexity: Theta(1)
    this->index=0;
    this->frq_index=1;
}


void BagIterator::next() {//iterates to the next element from the bag.
    //TODO - Implementation
    //Complexity: Theta(1)
    if (this->valid() == false) {
        throw std::runtime_error("Iterator is not valid");
    }
    // Move to the next element if the current frequency is exhausted
    if (this->frq_index < this->bag.elements[this->index].second) {
        this->frq_index++;
    } else {
        this->index++;
        this->frq_index = 1; // Reset the frequency index
    }

}

bool BagIterator::valid() const {//checks if the current index is a valid one. Complexity: Theta(1)
	//TODO - Implementation
    //Complexity: Theta(1)
    return this->index >= 0 && this->index < this->bag.lenght;
}


TElem BagIterator::getCurrent() const//gets the current value of the pair the index is on. Complexity: Theta(1)
{
	//TODO - Implementation
    //Complexity :Theta(1)
    if(this->valid())
        return this->bag.elements[this->index].first;

    throw std::runtime_error("Iterator is not valid");
}
