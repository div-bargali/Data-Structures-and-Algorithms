package main

import "log"

// DFS (depth first search) is an algorithm for traversing a tree/graph
// structure. It starts at root node and explores as far as possible before
// backtracking and continuing along a different path.

/*
All edges are unidirectional, going down below.
	 1
  /  |  \
 2   7   8
/\      / \
6 3    9   12
  /\   |   |
  4 5->10  11
*/
var adjacencyList = map[int][]int{
	1: {2, 7, 8},
	2: {3, 6},
	3: {4, 5},
	5: {10},
	8: {9, 12},
	9: {10, 11},
}

var visit = map[int]struct{}{}

func dfs(cur int) {
	if _, visited := visit[cur]; visited {
		return
	}

	log.Printf("[Enter] Node: %2d", cur)
	visit[cur] = struct{}{}
	for _, node := range adjacencyList[cur] {
		dfs(node)
	}
	log.Printf("[Exit]  Node: %2d", cur)
}

// OUTPUT:
// 2020/10/25 21:25:56 [Enter] Node:  1
// 2020/10/25 21:25:56 [Enter] Node:  2
// 2020/10/25 21:25:56 [Enter] Node:  3
// 2020/10/25 21:25:56 [Enter] Node:  4
// 2020/10/25 21:25:56 [Exit]  Node:  4
// 2020/10/25 21:25:56 [Enter] Node:  5
// 2020/10/25 21:25:56 [Enter] Node: 10
// 2020/10/25 21:25:56 [Exit]  Node: 10
// 2020/10/25 21:25:56 [Exit]  Node:  5
// 2020/10/25 21:25:56 [Exit]  Node:  3
// 2020/10/25 21:25:56 [Enter] Node:  6
// 2020/10/25 21:25:56 [Exit]  Node:  6
// 2020/10/25 21:25:56 [Exit]  Node:  2
// 2020/10/25 21:25:56 [Enter] Node:  7
// 2020/10/25 21:25:56 [Exit]  Node:  7
// 2020/10/25 21:25:56 [Enter] Node:  8
// 2020/10/25 21:25:56 [Enter] Node:  9
// 2020/10/25 21:25:56 [Enter] Node: 11
// 2020/10/25 21:25:56 [Exit]  Node: 11
// 2020/10/25 21:25:56 [Exit]  Node:  9
// 2020/10/25 21:25:56 [Enter] Node: 12
// 2020/10/25 21:25:56 [Exit]  Node: 12
// 2020/10/25 21:25:56 [Exit]  Node:  8
// 2020/10/25 21:25:56 [Exit]  Node:  1

// go run dfs.go
func main() {
	dfs(1)
}
