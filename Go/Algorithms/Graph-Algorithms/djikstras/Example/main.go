package main

import (
	"fmt"
	"math"

	"github.com/Data-Structures-and-Algorithms/Go/Algorithms/Graph-Algorithms/djikstras/minheapmap"
)

//Using a MinHeap with O(1) Lookup for an implementation of the Djikstras algo for minimum cost spanning path.
type node struct {
	name       string        //ID of the node
	neighbours map[*node]int // indicates a directed edge from the node to the neighbour
}

func main() {
	//Build a graph representation..
	n1 := &node{
		name: "guitar",
	}
	n2 := &node{
		name: "book",
	}
	n3 := &node{
		name: "LP",
	}
	n4 := &node{
		name: "poster",
	}
	n5 := &node{
		name: "drums",
	}
	n6 := &node{
		name: "piano",
	}
	n1.neighbours = make(map[*node]int)
	n1.neighbours[n6] = 20
	n2.neighbours = make(map[*node]int)
	n2.neighbours[n4] = 0
	n2.neighbours[n3] = 5
	n3.neighbours = make(map[*node]int)
	n3.neighbours[n1] = 15
	n3.neighbours[n5] = 20
	n4.neighbours = make(map[*node]int)
	n4.neighbours[n5] = 10
	n4.neighbours[n1] = 30
	n5.neighbours = make(map[*node]int)
	n5.neighbours[n6] = 10
	src := n2
	// src: ok , adjList: ok
	mheap := minHeapMap{
		minHeap: make([]entry, 0),
		mapping: make(map[*node]int),
	}
	minheapmap.Push(&mheap, entry{
		n:    n1,
		cost: math.MaxInt32,
	})
	minheapmap.Push(&mheap, entry{
		n:    n3,
		cost: math.MaxInt32,
	})
	minheapmap.Push(&mheap, entry{
		n:    n4,
		cost: math.MaxInt32,
	})
	minheapmap.Push(&mheap, entry{
		n:    n5,
		cost: math.MaxInt32,
	})
	minheapmap.Push(&mheap, entry{
		n:    n6,
		cost: math.MaxInt32,
	})
	minheapmap.Push(&mheap, entry{
		n:    n2,
		cost: 0,
	})
	fmt.Println("created heap:", mheap.minHeap)
	srcMap := make(map[*node]*node)
	srcMap[src] = src
	costMap := make(map[*node]int)
	for len(mheap.minHeap) > 0 {
		top := minheapmap.Pop(&mheap).(entry)
		n := top.n
		fmt.Println("taking out", n.name)
		delete(mheap.mapping, n)
		c := top.cost
		fmt.Println("to reach", n.name, "cost:", c)
		costMap[n] = c
		for ngbr, cost := range n.neighbours {
			fmt.Println("at neighbr", ngbr.name, "edge cost:", cost)
			if mheap.contains(ngbr) {
				//current cost
				k := mheap.GetKey(ngbr)
				currCost := mheap.minHeap[k].cost
				fmt.Println("curr cost of reaching", ngbr.name, "-", currCost)
				//if current cost < c+cost
				if c+cost < currCost {
					mheap.minHeap[k].cost = c + cost
					fmt.Println("upgating", ngbr.name, "to", c+cost)
					minheapmap.Decrease(&mheap, ngbr)
					srcMap[ngbr] = n
				}
				// update cost of the ngbr in the heap
			}
		}

	}
	for n, c := range costMap {
		fmt.Println("node:", n.name, " cost:", c)
	}

}

//need to implement decrement() in log(n) and contains in O(1)
type minHeapMap struct {
	minHeap []entry
	mapping map[(*node)]int
}

type entry struct {
	n    *node
	cost int
}

func (m *minHeapMap) contains(n *node) bool {
	_, ok := m.mapping[n]
	return ok
}

func (m *minHeapMap) Remove(x interface{}) {
	delete((*m).mapping, x.(entry).n)
}

func (m *minHeapMap) Update(k, v interface{}) {
	(*m).mapping[k.(entry).n] = v.(int)
}

func (m minHeapMap) GetElem(x interface{}) interface{} {
	return (m).minHeap[x.(int)]
}

func (m *minHeapMap) GetKey(x interface{}) int {
	return (*m).mapping[x.(*node)]
}

func (m *minHeapMap) Len() int {
	return len((*m).minHeap)
}

func (m *minHeapMap) Less(i, j int) bool {
	return ((*m).minHeap)[i].cost < ((*m).minHeap)[j].cost
}

func (m *minHeapMap) Swap(i, j int) {
	(*m).minHeap[i], (*m).minHeap[j] = (*m).minHeap[j], (*m).minHeap[i]
}

func (m *minHeapMap) Push(x interface{}) {
	(*m).minHeap = append((*m).minHeap, x.(entry))
	(*m).mapping[x.(entry).n] = len((*m).minHeap) - 1
}

func (m *minHeapMap) Pop() interface{} {
	v := (*m).minHeap
	l := len(v)
	top := v[l-1]
	v = v[:l-1]
	(*m).minHeap = v
	return top
}
