package main

import "fmt"

type binarySearch struct{}

// Returns true if key is present in data list, binary search will only work on sorted lists
func (ls *binarySearch) binarySearch(data []int, key int) bool {
	l := 0
	r := len(data) - 1
	// loop until left index is less than or equal to right index
	for l <= r {
		// set middle index
		m := (l + r) / 2
		// if value found return true
		if key == data[m] {
			return true
		}
		//update left, right index based
		if key > data[m] {
			l = m + 1
		} else {
			r = m - 1
		}
	}
	return false
}

func main() {
	ls := binarySearch{}
	data := []int{1, 2, 5, 6, 11}
	fmt.Println(ls.binarySearch(data, 2))
	fmt.Println(ls.binarySearch(data, 15))

	data = []int{1, 3, 8, 15}
	fmt.Println(ls.binarySearch(data, 2))
	fmt.Println(ls.binarySearch(data, 15))
}
