from iterator import BagIterator

class Bag:
    def __init__(self):
        self.b = []

    def add(self, e):
        self.b.append(e)

    def remove(self, e):
        new_size = len(self.b)
        size_bag = len(self.b)
        if e in self.b:
            self.b.remove(e)
            new_size = len(self.b)

        if size_bag > new_size:
            return True
        else:
            return False

    def search(self, e):
        if e in self.b:
            return True
        else:
            return False

    def size(self):
        return len(self.b)

    def nrOcurance(self, e):
        ct = 0
        for elem in self.b:
            if elem == e:
                ct += 1
        if ct == 0:
            return "Does not exist"
        else:
            return ct

    def destroy(self):
        self.b = []
        return self.b

    def iterator(self):
        i = BagIterator(self.b)
