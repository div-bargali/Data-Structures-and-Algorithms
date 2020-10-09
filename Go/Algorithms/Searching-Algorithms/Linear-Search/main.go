package main

import "fmt"

type linearSearch struct{}

// Returns true if key is present in data list
func (ls *linearSearch) linearSearch(data []int, key int) bool {
	// iterate through list and return true if found
	for _, k := range data {
		if key == k {
			return true
		}
	}
	return false
}

func main() {
	ls := linearSearch{}
	data := []int{1, 2, 8, 3, 6}
	fmt.Println(ls.linearSearch(data, 2))
	fmt.Println(ls.linearSearch(data, 5))
}
