/*
Implementation of Quicksort according to https://en.wikipedia.org/wiki/Quicksort
*/

package main

import (
	"fmt"
	"math/rand"
)

func swap(a *int64, b *int64) {
	t := *a
	*a = *b
	*b = t
}

func partition(arr []int64, low int, high int) int {
	pivot := arr[high]
	i := low
	for j := low; j <= high; j++ {
		if arr[j] < pivot {
			swap(&arr[i], &arr[j])
			i++
		}
	}
	swap(&arr[i], &arr[high])
	return i
}

func quicksort(arr []int64, low int, high int) {
	if low < high {
		pi := partition(arr, low, high)
		quicksort(arr, low, pi - 1)
		quicksort(arr, pi + 1, high)
	}
}

func main() {
	//Generates n random values and sorts them with quicksort
	n := 100
	arr := make([]int64, 100)
	for i := 0; i < n; i++ {
		arr[i] = rand.Int63n(100)
	}

	quicksort(arr, 0, len(arr) - 1)
	fmt.Printf("%v\n", arr)
}