class BagIterator:
    def __init__(self, b):
        self.i = 0
        self.b = b

    def valid(self):
        return self.i < len(self.b)

    def first(self):
        if len(self.b) > 0:
            self.i = 0
        else:
            raise "Index out of range"

    def next(self):
        self.i += 1

    def getCurrent(self):
        if self.valid() == True:
            return self.b[self.i]
        else:
            raise"Index out of range"

