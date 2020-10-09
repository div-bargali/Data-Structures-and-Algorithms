package minheapmap

import "container/heap"

// The Interface type describes the requirements
// for a type using the routines in this package.
// Any type that implements it may be used as a
// min-heap with the keys stored in a map

type Interface interface {
	heap.Interface
	//Remove an element from the corresponding Map for the heap entries
	Remove(x interface{})
	//Update a particular value of an entry in the heap and re-evaluate the heap invariance
	Update(k, v interface{})
	//Get the elem present at a particular index in the heap array
	GetElem(x interface{}) interface{}
	//Get the correspinding value to a key in the Map for the heap entries
	GetKey(x interface{}) int
}

//Decrease the value associated with the key in the <key,value> tuple
func Decrease(h Interface, k interface{}) {
	p := h.GetKey(k)
	if !down(h, p, h.Len()) {
		up(h, p)
	}
}

// Push pushes the element x onto the heap.
// The complexity is O(log n) where n = h.Len().
// Push() is for the interface to call and should be used to add keys to the heap
func Push(h Interface, x interface{}) {
	h.Push(x)
	up(h, h.Len()-1)
}

// Pop removes and returns the minimum element (according to Less) from the heap.
func Pop(h Interface) interface{} {
	n := h.Len() - 1
	h.Remove(h.GetElem(0))
	h.Update(h.GetElem(n), 0)
	h.Swap(0, n)
	down(h, 0, n)
	return h.Pop()
}

func up(h Interface, j int) {
	for {
		i := (j - 1) / 2 // parent
		if i == j || !h.Less(j, i) {
			break
		}
		h.Update(h.GetElem(i), j)
		h.Update(h.GetElem(j), i)
		h.Swap(i, j)
		j = i
	}
	return
}

func down(h Interface, i0, n int) bool {
	i := i0
	for {
		j1 := 2*i + 1
		if j1 >= n || j1 < 0 { // j1 < 0 after int overflow
			break
		}
		j := j1 // left child
		if j2 := j1 + 1; j2 < n && h.Less(j2, j1) {
			j = j2 // = 2*i + 2  // right child
		}
		if !h.Less(j, i) {
			break
		}
		h.Update(h.GetElem(i), j)
		h.Update(h.GetElem(j), i)
		h.Swap(i, j)
		i = j
	}
	return i > i0
}
