//Problem: Detecting a cycle in a directed grapgh using DFS

//Input: The graph in tems of edges and vertices

//Output: Yes if graph contains cycle, no otherwise

//Time complexity: O(V+E), Space complexity: O(V) - for the recursion stack

/*
SOLUTION APPROACH:

- Depth First Traversal can be used to detect a cycle in a Graph. DFS for a connected graph produces a tree. There is a cycle in a graph only if there is a back edge present in the graph. A back edge is an edge that is from a node to itself (self-loop) or one of its ancestors in the tree produced by DFS
- For a disconnected graph, Get the DFS forest as output. To detect cycle, check for a cycle in individual trees by checking back edges.
- To detect a back edge, keep track of vertices currently in the recursion stack of function for DFS traversal. If a vertex is reached that is already in the recursion stack, then there is a cycle in the tree. The edge that connects the current vertex to the vertex in the recursion stack is a back edge.
*/

#include<bits/stdc++.h>
using namespace std;

//we will be using the adjacency list representation of a graph
vector<int>adjList[10];

//function to add an edge between u and v
void addEdge(int u, int v)
{
    adjList[u].push_back(v);
}

//utility function
bool isCyclicUtil(int v, bool visited[], bool *recStack) 
{ 
    //if this vertex has not been visited before, process it
    if(visited[v] == false) 
    { 
        // Mark the current node as visited and part of recursion stack 
        visited[v] = true; 
        recStack[v] = true; 
  
        // Recur for all the vertices adjacent to this vertex 
        for(auto i:adjList[v]) 
        { 
            if ( !visited[i] && isCyclicUtil(i, visited, recStack) ) 
                return true; 
            else if (recStack[i]) 
                return true; 
        } 
  
    } 
    recStack[v] = false;  // remove the vertex from recursion stack after it has been processed
    return false; //This statement executes only when there are no back edges 
}
bool isCyclic(int V) 
{ 
    // Mark all the vertices as not visited and not part of recursion stack 
    bool *visited = new bool[10]; 
    bool *recStack = new bool[10]; 
    for(int i = 0; i < V; i++) 
    { 
        visited[i] = false; 
        recStack[i] = false; 
    } 
  
    // Call the recursive helper function to detect cycle in different DFS trees 
    for(int i = 0; i < V; i++) 
        if (isCyclicUtil(i, visited, recStack)) 
            return true; 
  
    return false; 
}

int main() 
{ 
    // Create a graph  
    addEdge(0, 1); 
    addEdge(0, 2); 
    addEdge(1, 2); 
    addEdge(2, 0); 
    addEdge(2, 3); 
    addEdge(3, 3); 
  
    if(isCyclic(4)) 
        cout << "Graph contains cycle"; 
    else
        cout << "Graph doesn't contain cycle"; 
    return 0; 
}
/*
An Another approach to detect cycle in graph

// A DFS based approach to find if there is a cycle 
// in a directed graph. This approach strictly follows 
// the algorithm given in CLRS book. 
#include <bits/stdc++.h> 
using namespace std; 

enum Color {WHITE, GRAY, BLACK}; 

// Graph class represents a directed graph using 
// adjacency list representation



class Graph 
{ 
	int V; // No. of vertices 
	list<int>* adj; // adjacency lists 

	// DFS traversal of the vertices reachable from v 
	bool DFSUtil(int v, int color[]); 
public: 
	Graph(int V); // Constructor 

	// function to add an edge to graph 
	void addEdge(int v, int w); 

	bool isCyclic(); 
}; 

// Constructor 
Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

// Utility function to add an edge 
void Graph::addEdge(int v, int w) 
{ 
	adj[v].push_back(w); // Add w to v's list. 
} 

// Recursive function to find if there is back edge 
// in DFS subtree tree rooted with 'u' 
bool Graph::DFSUtil(int u, int color[]) 
{ 
	// GRAY : This vertex is being processed (DFS 
	//		 for this vertex has started, but not 
	//		 ended (or this vertex is in function 
	//		 call stack) 
	color[u] = GRAY; 

	// Iterate through all adjacent vertices 
	list<int>::iterator i; 
	for (i = adj[u].begin(); i != adj[u].end(); ++i) 
	{ 
		int v = *i; // An adjacent of u 

		// If there is 
		if (color[v] == GRAY) 
		return true; 

		// If v is not processed and there is a back 
		// edge in subtree rooted with v 
		if (color[v] == WHITE && DFSUtil(v, color)) 
		return true; 
	} 

	// Mark this vertex as processed 
	color[u] = BLACK; 

	return false; 
} 

// Returns true if there is a cycle in graph 
bool Graph::isCyclic() 
{ 
	// Initialize color of all vertices as WHITE 
	int *color = new int[V]; 
	for (int i = 0; i < V; i++) 
		color[i] = WHITE; 

	// Do a DFS traversal beginning with all 
	// vertices 
	for (int i = 0; i < V; i++) 
		if (color[i] == WHITE) 
		if (DFSUtil(i, color) == true) 
			return true; 

	return false; 
} 

// Driver code to test above 
int main() 
{ 
	// Create a graph given in the above diagram 
	Graph g(4); 
	g.addEdge(0, 1); 
	g.addEdge(0, 2); 
	g.addEdge(1, 2); 
	g.addEdge(2, 0); 
	g.addEdge(2, 3); 
	g.addEdge(3, 3); 

	if (g.isCyclic()) 
		cout << "Graph contains cycle"; 
	else
		cout << "Graph doesn't contain cycle"; 

	return 0; 
} 
*/
