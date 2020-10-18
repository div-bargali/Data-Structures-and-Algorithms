package main

import "fmt"

type queue struct {
	data []int
}

// Return true if queue is empty
func (q *queue) isEmpty() bool {
	return len(q.data) == 0
}

// enqueue value into queue
func (q *queue) enqueue(data int) {
	q.data = append(q.data, data)
}

// return data element and a boolean value, if queue is empty boolean value returned wll be false
func (q *queue) dequeue() (int, bool) {
	if q.isEmpty() {
		return 0, false
	}
	data := q.data[0]
	q.data = q.data[1:]
	return data, true
}

func main() {
	var q queue
	q.enqueue(1)
	q.enqueue(2)
	q.enqueue(4)
	q.enqueue(8)
	fmt.Println(q.data)
	fmt.Println(q.dequeue())
	fmt.Println(q.data)
	fmt.Println(q.dequeue())
	fmt.Println(q.dequeue())
	fmt.Println(q.data)
	fmt.Println(q.dequeue())
	fmt.Println(q.dequeue())
	fmt.Println(q.data)
}
