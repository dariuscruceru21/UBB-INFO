#include <exception>
#include "BagIterator.h"
#include "Bag.h"


using namespace std;


BagIterator::BagIterator(const Bag& c): bag(c)
{
	//TODO - Implementation
    index = 0;
    frq_index = 1;
}

void BagIterator::first() {
	//TODO - Implementation
    index=0;
    frq_index=1;
}


void BagIterator::next() {
    //TODO - Implementation
    exception excep;
    if (valid() && frq_index == bag.elements[index].second) {
        index++;
        frq_index = 1;
    } else if (frq_index != bag.elements[index].second && valid())
                 frq_index++;

}
bool BagIterator::valid() const {
	//TODO - Implementation
    if(bag.isEmpty())
        return false;
    else{
        if(index < bag.lenght && index>=0)
            return true;
    }
	return false;
}


TElem BagIterator::getCurrent() const
{
	//TODO - Implementation
    if(valid())
        return bag.elements[index].first;
	return NULL_TELEM 
}
