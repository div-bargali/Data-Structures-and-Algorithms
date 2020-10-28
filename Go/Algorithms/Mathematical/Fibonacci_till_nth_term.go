package main

import (
	"fmt"
)

func main() {
	n := 4
	a := 0
	b := 1
	sum := 0
	if n < 2 {
		fmt.Print("Fibonacci sereies till 1st term is 0")
	} else if n < 3 {
		fmt.Print("Fibonacci sereies till 2nd term is 0 1")
	} else {
		fmt.Print("Fibonacci sereies till ", n, "th term is ", a, " ", b, " ")
		for i := 2; i < n; i++ {

			sum = a + b
			fmt.Print(sum, " ")
			a = b
			b = sum
		}

	}
}
