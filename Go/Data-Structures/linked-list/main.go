package main

import "fmt"

type node struct {
	data int
	next *node // address of the next node
}

// quotient list
type linkedList struct {
	head   *node
	length int // indicate how long the linked list is
}

func (l *linkedList) prepend(n *node) {
	second := l.head
	l.head = n
	l.head.next = second
	l.length++
}

func (l linkedList) printListData() {
	toPrint := l.head
	for l.length != 0 {
		fmt.Printf("%d ", toPrint.data)
		toPrint = toPrint.next
		l.length--
	}
	fmt.Printf("\n")
}

func (l *linkedList) deleteWithValue(value int) {
	if l.length == 0 {
		return
	}

	if l.head.data == value {
		l.head = l.head.next
		l.length--
		return
	}

	previousToDelete := l.head
	/*
		We do not want to compare the data of the node in to delete,
		we are going to	compare the data of the next node.
		To skip the node with the input value, we need to make modifications
		in the previous node next.
	*/
	for previousToDelete.next.data != value {
		if previousToDelete.next.next == nil {
			return
		}
		previousToDelete = previousToDelete.next
	}
	previousToDelete.next = previousToDelete.next.next
	l.length--
}

func (l *linkedList) deleteByIndex(value int) {
	if l.length == 0 {
		return
	}

	if value >= l.length {
		return
	}

	if value == 0 {
		l.head = l.head.next
		l.length--
		return
	}

	previousNode := l.head
	count := 0

	// If i want to delete the last node
	if value == l.length-1 {
		for previousNode.next.next != nil {
			previousNode = previousNode.next
		}
		previousNode.next = nil
		l.length--
		return
	}

	// Normal case
	for count < value-1 {
		count += 1
		previousNode = previousNode.next
	}
	previousNode.next = previousNode.next.next
	l.length--
}

func main() {
	mylist := linkedList{}
	node1 := &node{data: 48}
	node2 := &node{data: 18}
	node3 := &node{data: 16}
	node4 := &node{data: 11}
	node5 := &node{data: 7}
	node6 := &node{data: 2}
	mylist.prepend(node1)
	mylist.prepend(node2)
	mylist.prepend(node3)
	mylist.prepend(node4)
	mylist.prepend(node5)
	mylist.prepend(node6)
	mylist.printListData()

	mylist.deleteWithValue(100)
	mylist.deleteWithValue(2)
	mylist.printListData()
	mylist.deleteByIndex(2)
	mylist.deleteByIndex(mylist.length - 1)
	mylist.printListData()
	emptyList := linkedList{}
	emptyList.deleteWithValue(10)

}
