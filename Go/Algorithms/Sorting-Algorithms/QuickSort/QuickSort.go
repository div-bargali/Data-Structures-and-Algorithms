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
	swap(&arr[(high + low) / 2], &arr[high])

	pivot := arr[high]
	i := low - 1
	for j := low; j <= high; j++ {
		if arr[j] < pivot {
			i++
			swap(&arr[i], &arr[j])
		}
	}
	swap(&arr[i + 1], &arr[high])
	return i + 1
}

func quicksort(arr []int64, low int, high int) {
	if low < high {
		pi := partition(arr, low, high)
		quicksort(arr, low, pi - 1)
		quicksort(arr, pi + 1, high)
	}
}

func main() {
	var a int64 = 10
	var b int64 = 20

	swap(&a, &b)
	fmt.Printf("%t\n", a == 20 && b == 10)

	n := 100
	arr := make([]int64, 100)
	for i := 0; i < n; i++ {
		arr[i] = rand.Int63n(100)
	}

	quicksort(arr, 0, len(arr) - 1)
	fmt.Printf("%v\n", arr)
}