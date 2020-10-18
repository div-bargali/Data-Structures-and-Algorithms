// A C++ program for Kruskal's Minimum 
// Spanning Tree (MST) algorithm. The program Used
//the adjacency matrix 
/*Ask the input from the user the num of edges, 
num of vertices and the graph with the value of each edge
Nodes are given 0 index based
*/
#include <bits/stdc++.h>
using namespace std;

//Graph edge with src , dest and weight
struct Graph_Edge{
    int src, dest, weight;
};
static bool compare(Graph_Edge* a, Graph_Edge* b){
    return a->weight < b->weight;
}


//function to calculate mst
int minSpaingTree(vector<Graph_Edge*>& graph, int vertices, int edges) {
        vector<int>cycle_check(vertices);

        //giving the id to every node
        for(int i = 0 ; i < vertices ; i++){
            cycle_check[i] = i;
        }

        int min_cost = 0;

        for( int i = 0 ; i < graph.size() ; i++){

            //consider the edge only when it is not forming the cycle with the existing nodes
            if (cycle_check[graph[i]->src]!=cycle_check[graph[i]->dest]){
                min_cost += graph[i]->weight;
                for(int j=0 ; j<vertices ; j++){
                    if ( cycle_check [j] == cycle_check[graph[i]->src]){
                        cycle_check[j] = cycle_check[graph[i]->dest];
                    }
                }
            }

        }
    return min_cost;

}
int main(){
    int num_vertices;
    cin >> num_vertices;
    
    int num_edges;
    cin >> num_edges;    
    vector<Graph_Edge*>graph;

    int a, b, val;
    for(int i=0;i<num_edges ;i++){
        cin >> a;
        cin >> b;
        cin >> val;
        struct Graph_Edge* temp = new Graph_Edge;
        temp->src = a;
        temp->dest = b;
        temp->weight = val;
        graph.push_back(temp);
    }
    //sort the edges in the ascending order
    sort(graph.begin(), graph.end(), compare);

    int min_cost = minSpaingTree(graph, num_vertices, num_edges);

    cout <<  "Minimum cost of total Path " << min_cost <<"\n";

    return 0;
}
