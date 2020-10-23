#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip>
using namespace std;

// Number of vertices in the graph
#define N 4

// data structure to store graph edges
struct Edge {
	int src, dest;
};

// class to represent a graph object
class Graph
{
public:
	// An array of vectors to represent adjacency list
	vector<int> adjList[N];

	// Constructor
	Graph(vector<Edge> edges)
	{
		// add edges to the directed graph
		for (Edge edge: edges)
		{
			int src = edge.src;
			int dest = edge.dest;

			adjList[src].push_back(dest);
		}
	}
};

// C is connectivity matrix and stores transitive closure of graph
// root is the topmost node in DFS tree(it is starting vertex of DFS)
// descendent is current vertex to be explored in DFS
// Invariant: A path already exists from root -> descendent in graph
void DFS(Graph const& graph, bool C[N][N], int root, int descendent)
{
	for (int child : graph.adjList[descendent])
	{
		// if child is an adjacent vertex of descendent, we have
		// found a path from root->child
		if (!C[root][child])
		{
			C[root][child] = true;
			DFS(graph, C, root, child);
		}
	}
}

int main()
{
	// array of graph edges as per above diagram
	vector<Edge> edges = {
		{ 0, 2 }, { 1, 0 }, { 3, 1 }
	};

	// create a graph from edges
	Graph graph(edges);

	// C is connectivity matrix and stores the transitive closure
	// of the graph. The value of C[i][j] is 1 only if a directed
	// path exists from vertex i to vertex j.
	bool C[N][N];
	memset(C, false, sizeof C);

	// consider each vertex and start DFS from it
	for (int v = 0; v < N; v++)
	{
		C[v][v] = true;
		DFS(graph, C, v, v);

		// print path info for vertex v
		for (int u = 0; u < N; u++)
			cout << left << setw(4) << C[v][u];
		cout << endl;
	}

	return 0;
}
