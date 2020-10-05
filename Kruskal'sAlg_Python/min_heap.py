class MinHeap():
    def __init__(self):
        self.heap_list = []
    def insert(self, data):
        #assume data is going to be a tuple of three elements,
        #two int edges and a float weight, only checking weight
        #making a min heap of tuples
        self.heap_list.append(data)
        self.bubble_up(len(self.heap_list) - 1)
    def deleteMin(self):
        #deletes min tuple from the heap and prints it
        value = self.heap_list[0]
        self.bubble_down()
        return value
    def size(self):
        return len(self.heap_list)
    def get_parent_index(self, index):
        if index == 0:
            return 0
        return int(index - 1) //2
    def get_left_index(self,index):
        return (2 * index) + 1
    def get_right_index(self, index):
        return self.get_left_index(index) + 1
    def exist(self, index):
        return index < len(self.heap_list)
    def bubble_up(self, index):
        parent_index = self.get_parent_index(index)

        while self.heap_list[parent_index] > self.heap_list[index]:
            #first swap the values at the indexes, then fix the indexes
            self.heap_list[parent_index], self.heap_list[index] = self.heap_list[index], self.heap_list[parent_index]
            index = parent_index
            parent_index = self.get_parent_index(index)
    def bubble_down(self):
        self.heap_list[0] = self.heap_list[-1]
        self.heap_list = self.heap_list[:-1]
        index = 0
        while index < len(self.heap_list):
            # child index that is less than, assume left for now
            minIndex = self.get_left_index(index)
            # check that the index exist, if not we are done
            if not self.exist(minIndex):
                break
            # try the right child
            try:
                if self.heap_list[self.get_right_index(index)] < self.heap_list[minIndex]:
                    minIndex = self.get_right_index(index)
            except IndexError:
                pass
            if self.heap_list[minIndex] < self.heap_list[index]:
                self.heap_list[index], self.heap_list[minIndex] = self.heap_list[minIndex], self.heap_list[index]
                index = minIndex
            else:
                # done sinking
                break
        
