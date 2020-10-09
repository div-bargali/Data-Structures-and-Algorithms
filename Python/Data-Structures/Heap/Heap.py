class Heap:
    # max heap init data
    def __init__(self):
        self.data = []

    # get parent index
    @staticmethod
    def _parent(idx):
        return (idx-1)//2

    # get left child index
    @staticmethod
    def _left(idx):
        return 2*idx+1

    # get right child index
    @staticmethod
    def _right(idx):
        return 2*idx+2

    # function to rearrange elements in array to heap
    def _heapify(self, idx=0):
        while True:
            l = Heap._left(idx)
            r = Heap._right(idx)
            maxidx = idx
            if l < len(self) and self.data[l] > self.data[idx]:
                maxidx = l
            if r < len(self) and self.data[r] > self.data[maxidx]:
                maxidx = r
            if maxidx != idx:
                self.data[maxidx], self.data[idx] = self.data[idx], self.data[maxidx]
                idx = maxidx
            else:
                break

    # function to rearrange elements in array to heap (recursively)
    def _heapify_rec(self, idx=0):
        l = Heap._left(idx)
        r = Heap._right(idx)
        maxidx = idx
        if l < len(self) and self.data[l] > self.data[idx]:
            maxidx = l
        if r < len(self) and self.data[r] > self.data[maxidx]:
            maxidx = r
        if maxidx != idx:
            self.data[maxidx], self.data[idx] = self.data[idx], self.data[maxidx]
            self._heapify_rec(maxidx)

    # add element to the heap
    def add(self, x):
        self.data.append(x)
        i = len(self.data) - 1
        p = Heap._parent(i)
        while i > 0 and self.data[p] < self.data[i]:
            self.data[p], self.data[i] = self.data[i], self.data[p]
            i = p
            p = Heap._parent(i)

    # return the maximum of the heap
    def max(self):
        return self.data[0]

    # return and remove the maximum of the heap
    def pop_max(self):
        ret = self.data[0]
        self.data[0] = self.data[len(self.data)-1]
        del self.data[len(self.data)-1]
        self._heapify()
        return ret

    # check if the heap is not empty
    def __bool__(self):
        return len(self.data) > 0

    # return the length/size of the heap
    def __len__(self):
        return len(self.data)

    # return data of the heap in string type
    def __repr__(self):
        return repr(self.data)

# tests for Heap class
if __name__ == "__main__":
    import random

    # create new Heap
    h = Heap()

    # add items to heap
    for _ in range(30):
        h.add(random.randrange(100))

    # print heap
    print("Heap: ", h)

    # pop max
    print("Pop max of heap: ", h.pop_max())
    print("Heap after pop: ", h)
