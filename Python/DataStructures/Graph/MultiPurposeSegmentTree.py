from math import log2, ceil

class SegTree:
    '''
        Class for Segment Tree with custom functionality of being RangeSum, RangeMax etc
        This segment tree is 0 indexed
    '''
    def __init__(self, n=None, func=sum, sentinel = 0):
        self.N = 0
        self.SENTINEL = sentinel
        ## default to segment tree with range sum query
        self.func = func
        if n and isinstance(n, int):
            self.N = n
            pw = ceil(log2(n)) + 1
            size = 2**pw - 1
            self.seg = [0]*size
            self.seg_ind = {}
        
        
    def construct_with(self, array):
        n = len(arr)
        self.__init__(n, self.func, self.SENTINEL)
        self._const_util(array, 0, n-1, 0)

    def _const_util(self, array, start_ind, end_ind, seg_ind):
        ##considering array from start_index to end_index both inclusive
        if start_ind == end_ind:
            self.seg[seg_ind] = arr[start_ind]
            self.seg_ind[start_ind] = seg_ind

        else:
            mid_ind = (start_ind + end_ind)//2
            ## recurse on left side
            self._const_util(array, start_ind, mid_ind, 2*seg_ind + 1)

            ## recurse on the right side
            self._const_util(array, mid_ind+1, end_ind, 2*seg_ind + 2)

            ## update value for current seg_ind based on the value of child indices
            left_value, right_value = self.seg[2*seg_ind+1], self.seg[2*seg_ind+2]
            self.seg[seg_ind] = self.func( [ left_value, right_value ] )


    def update(self, ind, new_value):
        ## find seg ind which corresponds to the index ind in array
        seg_ind = self.seg_ind[ind]
        

        ## update seg_index and there correspoding parent nodes
        self.seg[seg_ind] = new_value
        while seg_ind:
            parent = (seg_ind - 1)//2
            left_ind , right_ind = 2*parent+1, 2*parent+2
            self.seg[parent] = self.func([self.seg[left_ind] , self.seg[right_ind]])

            seg_ind = parent

    def range_Query(self, range_Start, range_End):
        ##
        if range_Start < 0 or range_End >= self.N or range_Start > range_End:
            ##TODO: raise some kind of error here
            return "Bad Range"

        return self._range_util(0, self.N-1, range_Start, range_End, 0)

    def _range_util(self, seg_Start, seg_End, range_Start, range_End, seg_ind):
        ## seg_start to seg_end is the range of node of seg_tree under consideration
        ## and seg_ind is the index that keeps  self.func( Array[ range_Start . .  range_End ] )

        ## no overlap condition
        if range_End < seg_Start or seg_End < range_Start:
            return self.SENTINEL

        ## full overlap
        if range_Start <= seg_Start and seg_End <= range_End:
            return self.seg[seg_ind]

        ## partial overlap condition

        mid_ind = (seg_Start + seg_End) // 2
        left_value = self._range_util(seg_Start, mid_ind, range_Start, range_End, 2*seg_ind + 1)
        right_value = self._range_util(mid_ind+1, seg_End, range_Start, range_End, 2*seg_ind + 2)

        return self.func([left_value, right_value])

## Usage
##  seg = SegTree(n = 10, func = max, sentinel = float('-inf') ## range Max Query Segment tree
##  seg = SegTree(n = 10, func = min, sentinel = float('inf') ## range Min Query Segment tree
##  seg = SegTree(n=10) ## sum based segment tree

