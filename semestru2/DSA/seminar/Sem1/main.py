from bag import Bag
from iterator import BagIterator

def test_add():
    bag = Bag()
    bag.add(5)
    assert bag.size() == 1
    bag.add(8)
    assert bag.size() == 2

def test_remove():
    bag = Bag()
    bag.add(5)
    bag.add(4)
    bag.add(8)
    assert bag.remove(4) == True
    assert bag.remove(1) == False

def test_search():
    bag = Bag()
    bag.add(6)
    bag.add(8)
    bag.add(1)
    assert bag.search(8) == True
    assert bag.search(0) == False

def test_size():
    bag = Bag()
    bag.add(3)
    bag.add(4)
    bag.add(1)
    assert bag.size() == 3

def test_nrOcurrance():
    bag = Bag()
    bag.add(1)
    bag.add(1)
    bag.add(2)
    assert bag.nrOcurance(1) == 2
    assert bag.nrOcurance(3) == "Does not exist"

def test_valid():
    i = BagIterator([1,2,3,4,5])
    i.next()
    assert i.valid() == True



def test_next():
    i = BagIterator([1,2,3,4,5])
    i.first()
    i.next()
    assert i.getCurrent() == 2




def main():
    test_size()
    test_search()
    test_add()
    test_nrOcurrance()
    test_remove()
    test_next()
    test_valid()



main()
