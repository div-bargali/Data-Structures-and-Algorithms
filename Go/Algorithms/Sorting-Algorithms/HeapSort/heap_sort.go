package main

import "log"

// This file includes a function heapSort to sort a slice of integers in
// ascending order.

// heapify compares the current node with either of its child for maximality.
// If either of the child has greater value then current node's value and the
// max child's value are swapped. Then, heapify is recursively called over the
// affected child.
// heapify here is for creating max heap.
func heapify(a []int, cur int) {
	max := cur
	left := cur<<1 | 1
	right := (cur + 1) << 1

	if left < len(a) && a[left] > a[max] {
		max = left
	}

	if right < len(a) && a[right] > a[max] {
		max = right
	}

	if max == cur {
		return
	}

	a[max], a[cur] = a[cur], a[max]
	heapify(a, max)
}

func heapSort(a []int) {
	// start from first non leaf node to create a max heap
	for i := len(a)/2 - 1; i >= 0; i-- {
		heapify(a, i)
	}

	for i := len(a) - 1; i >= 0; i-- {
		a[0], a[i] = a[i], a[0]
		heapify(a[:i], 0)
	}
}

// check validates heap sort and stops if sorting fails
func check(expected, input []int) {
	inputCopy := append([]int{}, input...)
	heapSort(input)

	if len(expected) != len(input) {
		log.Fatalf("[FAIL]: unequal length; expected: %v, received: %v", expected, input)
	}

	for i, v := range expected {
		if v != input[i] {
			log.Fatalf("[FAIL]: unequal slices; expected: %v, received: %v", expected, input)
		}
	}

	log.Printf("[PASS]: input: %v, output: %v", inputCopy, input)
}

// go run heap_sort.go
func main() {
	check([]int{-30, -10, 10, 20}, []int{10, -10, 20, -30})
	check([]int{-2, -1, 0, 10, 999999}, []int{-1, -2, 10, 999999, 0})
}
