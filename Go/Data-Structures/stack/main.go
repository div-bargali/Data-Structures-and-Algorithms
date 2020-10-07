package main

import "fmt"

type stack struct {
	data []int
}

// push value into stack
func (s *stack) push(data int) {
	s.data = append(s.data, data)
}

//pop value out of stack
func (s *stack) isEmpty() bool {
	return len(s.data) == 0
}

// return data element and a boolean value, if stack is empty boolean value returned wll be false
func (s *stack) pop() (int, bool) {
	if s.isEmpty() {
		return 0, false
	}
	lastElement := len(s.data) - 1
	data := s.data[lastElement]
	s.data = s.data[:lastElement]
	return data, true
}

func main() {
	var st stack
	st.push(1)
	st.push(2)
	st.push(4)
	st.push(8)
	fmt.Println(st.data)
	fmt.Println(st.pop())
	fmt.Println(st.data)
	fmt.Println(st.pop())
	fmt.Println(st.pop())
	fmt.Println(st.pop())
	fmt.Println(st.pop())
	fmt.Println(st.data)
}
