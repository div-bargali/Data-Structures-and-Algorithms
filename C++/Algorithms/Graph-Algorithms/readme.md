### Graph-Algorithms
- [A Star Search Algorithm](A_star_Search_Algorithm.cpp)

    A_star_Search_Algorithm is one of the best and popular technique used in path-finding and graph traversals. Consider a square grid having many obstacles and we are given a starting cell and a target cell. We want to reach the target cell from the starting cell as quickly as possible.

    Time complexity = O(E) (E is the number of edges in the graph) 

- [Articulation Point and Bridges](ArticulationPointandBridges.cpp)
    
    ArticulationPointandBridges, a vertex in an undirected connected graph is an undirected connected graph is an articulation point if and only if removing it (and edges through it) disconncets the grapth. Articulation points represent vulnerabilities in a connected network - single points whose failure would split the network into 2 or more components. For a disconnected undirected graph, an articulation point is a vertex removing which increases number of connected components. 
    
    Time complexity = O(V*(V+E))

- [Bipartite Graph](Bipartite_Graph.cpp)
    
    Bipartite_Graph, which is a graph whose vertices can be divided into two independent sets, U and V such that every edge(u,v) either connects a vertex from U to V or a from V to U. A bipartite graph is possible if the graph coloring is possible using two colors such that vertices in a set are colored with the same color.
    
    Time complexity = O(V+E)

- [Breadth First Search](Breadth%20First%20Search.cpp)
    
    Breadth First Search(BFS) is an algorithm for traversing or searching tree or garph data structures. It starts at the tree root(or some arbitrary node of a graph) and explores all of the neighbor nodes at the present depth prior to moving on to the nodes at the next depth level.
    
    Time complexity = O(V+E)

- [Component Count](Component_Count.cpp)
    
    Component_count, with a given undirected graph G, the task is to print the number of connected components in the graph. To approach, we use a variable count to store the number of connected components and to the following steps. 1. Initialize all vertices as unvisited. 2. For all the vertices check if a vertex has not been visited, then perform DFS on that vertex and increment the variable count by 1. 
    
    Time complexity = O(|V|+|E|)  

- [Cycle Detection Directed Graph](Cycle_detection_directed_graph.cpp)
    
    Cycle_detection_directed_graph, with a given directed graph, check whether the graph contains a cycle or not. Function we created should return true if the given graph contains at least one cycle, else return false.
    
    Time complexity = O(V+E)

- [Depth First Search](Depth%20First%20Search.cpp)
    
    Depth First Search is an algorithm for traversing or searching tree or graph data structures. The algorithm starts at the root node and explores as far as possible along each branch before backtracking.
    
    Time complexity = O(V+E)

- [Dijkstra's Algorithm](Dijkstra's%20Algorithm.cpp)
    
    The shortest path tree is built up, edge by edge. We maintain two sets: a set of the vertices already included in the tree and the set of the vertices not yet included. The Greedy choice is to pick the edge that connects the two sets and is on the smallest weight path from source to the set that contains not yet included vertices.
    
    Time complexity = O(|E|+|V|log|V|)

- [FordFulkerson](FordFlkerson.cpp)
    
    FordFulkerson is a algorithm with a given graph which represents a flow network where every edge has a capacity. Also given two vertices source 's' and sink 't' in the graph, we have to find the maximum possible flow from s to t with following constraints which is Flow on an edge doesn't exceed the given capacity of the edge and incoming flow is equal to outgoing flow for every vertex except s and t.
    
    Time complexity = O(max_flow*E)

- [Kosaraju or Kosaraju-Sharir Algorithm](Kosaraju.cpp)
    
    Kosaraju or kosaraju-Sharir algorithm is a linear time algorithm to find the strongly connected components of a directed graph.
    
    Time complexity = O(V+E)

- [Kruskal's Minimum Spanning Tree](Kruskal's.cpp)
    
    In Kruskal's algorithm, we create a MST(Minimum Spanning Tree) by picking edges one by one. The Greedy Choice is to pick the smallest weight edge that doesn't cause a cycle in the MST constructed so far.
    
    Time complexity = O(Elog V)    (V is the number of vertices)

- [Number of Islands](Number_of_islands.cpp)
    
    Number_of_Islands is a algorithm with an given boolean 2D matrix, find the number of islands. In this algorithm island is a group of connected 1s that forms an island. We can find value by counting the number of connected components in an undirected graph. (connected component of an undirected graph is a subgraph in which every two vertices are connected to each other by a path(s), and which is connected to no other vertices outside the subgraph).
    
    Time complexity = O(ROW x COL)

- [Prim's Minimum Spanning Tree](prims.cpp)
    
    We create a MST by picking edges one by one in Prim's algorithm. We maintatin two sets: a set of the vertices already included in MST and the set of the vertices not yet included. The Greedy choice is to pick the smallest weight edge that connects the two sets. 		
    
    Time complexity = O((V+E)log V)

- [Topological Sort](Topological_sort.cpp)
    
    Topological_sort is sorting algorithm for directed acyclic graph, which is a linear ordering of vertices such that for every directed edge u v, vertex u comes before v in the ordering. But if graph is not a DAG, topological sorting is not possible.
    
    Time complexity = O(V+E) 

- [Transitive Closure](Transitive_Closure.cpp)
    
    Transitive_Closure is a algorithm, with given a directed graph, find out if a vertex v is reachable from another vertex u for all vertex pairs (u,v) in the given graph. In this algorithm, reachable mean that there is a path from vertex u to v. The reachability matrix is called transitive closure of a graph.		
    
    Time complexity = O(v^2)