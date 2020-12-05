### Graph
- [BFS Using Queue](bfs%20using%20queue.cpp)

    bfs using queue,which is Breadth First Search algorithm, traverses a graph in a breadthward motion and uses a queue to remember to get next vertex to start a search, when a  dead end occurs in any iteration. Below are rules for BFS algorithm. 1.Rule => Visit the adjacent unvisited vertex. Then Mark it as visited. Display it. Insert it in a queue. 2. Rule => if no adjacent vertex is found, remove the first vertex from the queue. 3. Rule => repeat Rule1  and Rule2 until the queue is empty. 
    
    Time complexity = O(V+E) (V represent number of nodes, E represent number of edges)

- [Connected Components](ConnectedComponents.cpp)

    ConnectedComponents, with a given undirected graph, we have to print all connected components line by line. To find connected components for an undirected graph, we need to do either BFS or DFS starting from every unvisited vertex. 
    
    Time complexity = O(V+E)

- [DFS Using Stack](dfs%20using%20stack.cpp)

    dfs using stack, which is a Depth First Search algorithm, traverses a graph in a depthward motion and uses a stack to remember to get the next vertex to start a search, when a dead end occurs in any iteration. Like BFS, DFS also has rules to apply. 1. Rule => visit the adjacent unvisited vertex. Mark it as visited. Display it. Push it in a stack. 2. Rule => if no adjacent vertex is found, we have to pop up a vertex from the stack.(It will pop up all the vertices from the stack, which do not have adjacent vertices).  3. Rule => we have to repeat Rule1 and Rule2 until the stack is empty. 
    
    Time complexity = O(V+E) (V represent number of nodes, E represent number of edges)

- [Graph Implementation Using Adjacency List](graph%20implementation%20using%20adjacency%20list.cpp), [Graph Implementation](graph_implementation.cpp) 

    graph implementation using adjacency list, an adjacency list represents a graph as an array if linked lists. The index of the array represents a vertex and each element in its linked list represents the other vertices that form an edge with the vertex. The linked list can slightly be changed to even store weight of the edge. 
    
    Time complexity = Adding a vertex : O(1)  Adding an edge : O(1)  Removing a vertex : O(|V|+|E|)  Removing an edge : O(|E|)  Querying => O(|V|)
