class Heap:
    def __init__(self):
        self.data = []

    @staticmethod
    def _parent(idx):
        return (idx-1)//2

    @staticmethod
    def _left(idx):
        return 2*idx+1

    @staticmethod
    def _right(idx):
        return 2*idx+2

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

    def add(self, x):
        self.data.append(x)
        i = len(self.data) - 1
        p = Heap._parent(i)
        while i > 0 and self.data[p] < self.data[i]:
            self.data[p], self.data[i] = self.data[i], self.data[p]
            i = p
            p = Heap._parent(i)

    def max(self):
        return self.data[0]

    def pop_max(self):
        ret = self.data[0]
        self.data[0] = self.data[len(self.data)-1]
        del self.data[len(self.data)-1]
        self._heapify()
        return ret

    def __bool__(self):
        return len(self.data) > 0

    def __len__(self):
        return len(self.data)

    def __repr__(self):
        return repr(self.data)
