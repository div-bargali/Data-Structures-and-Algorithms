#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std; 

typedef pair<int,int> ii;
typedef vector<ii> vii;


 int main(){
	 int V, E, total_neighbours, id, weight, a, b;
	 int adjacencyMatrix[100][100];  // this implementaion is used mostly
	 // when the graph size is small and connectivity between two vertices
	 // is frequently required.
	 // space complexity is O(V^2).
	 vector<vii> adjacencyList;
	 // This is the most common and compact way of implementation of graph
	 // its space complexity is O(V+E).
	 priority_queue<pair<int, ii>> edgeList;
	 // implementation is very useful for Kruskal Algorithm
	 // space complexity of O(E).
	 // This are the inputs used stored in in.txt file
	 /*
  6
    0  10   0   0 100   0
   10   0   7   0   8   0
    0   7   0   9   0   0
    0   0   9   0  20   5
  100   8   0  20   0   0
    0   0   0   5   0   0
  6
  2 2 10 5 100
  3 1 10 3 7 5 8
  2 2 7 4 9
  3 3 9 5 20 6 5
  3 1 100 2 8 4 20
  1 4 5
  7
  1 2 10
  1 5 100
  2 3 7
  2 5 8
  3 4 9
  4 5 20
  4 6 5
  */
  freopen("in.txt", "r", stdin);
  
  //adjacency matrix implementation
  scanf("%d", &V);
  // do not use  adjecency matrix if V> 100
  for( int i = 0; i < V; i++)
	for( int j = 0; j < V; j++)
		scanf("%d", &adjacencyMatrix[i][j]);
  
  printf("Neighbours of Vertex 0 -- \n");
    for( int j = 0; j < V; j++)
    if(adjacencyMatrix[0][j])
    printf(" Edge 0-%d : (weight = %d) \n", j, adjacencyMatrix[0][j]);
    
    
    // adjacency list implementation
	scanf("%d", &V);
	adjacencyList.assign(V, vii());
	for( int i = 0; i < V; i++){
		scanf("%d", &total_neighbours);
		for( int j = 0; j < total_neighbours; j++){
			scanf("%d %d ", &id, &weight);
			adjacencyList[i].push_back(ii(id -1,weight)); //adjusting the index
			}
		}
	printf("Neighbours of Vertex 0 -- \n");
	for(vii::iterator  j = adjacencyList[0].begin(); j != adjacencyList[0].end(); j++)
	printf( " Edge 0-%d : (weight = %d) \n", j->first, j->second);
	
	// Edge list implementation
	scanf("%d", &E);
	for( int i = 0; i < E; i++){
		scanf("%d %d %d", &a, &b, &weight);
		edgeList.push(make_pair(-weight, ii(a, b))); //this trick is used for reverse sorting
		}
	for( int i = 0; i < E; i++){
		pair<int, ii> edge = edgeList.top();
		edgeList.pop();
		printf("Weight: %d (%d -%d) \n", -edge.first, edge.second.first, edge.second.second);
		//negating weight again
		}
		
		return 0;
  
	
	 }
