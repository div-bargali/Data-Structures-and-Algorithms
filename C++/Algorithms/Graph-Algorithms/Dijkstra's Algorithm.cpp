/* A C++ program for Dijkstra's algorithm. The program Used
the adjacency matrix 
Ask the input from the user the num of edges, 
num of vertices and the graph with the value of each edge
It will print the minimum cost from source to destination

Nodes should be provided from the index 1

*/
#include <bits/stdc++.h>
using namespace std;
struct compare{
        bool operator()(pair<int, int>&a, pair<int, int>&b){
            return a.first > b.first;
        }
    };

int findMinPath(vector<vector<int>>& graph, int n, int src, int dest){
    vector<int>distance(n, INT_MAX);//it will the shortest distance from source to every node

    vector<bool>visited(n, false);

    distance[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, compare>qt;

    int connect = 0;

    int i = src;
    int total = 0;

    //loop will work untill reach the destination
    while( i != dest ){

            visited[i] = true;
            
            int j = 0;

            while(j < n){
                if (!visited[j] && graph[i][j]!=-1 && distance[i]!=INT_MAX && distance[i] + graph[i][j] < distance[j]){
                    distance[j] = distance[i] + graph[i][j];
                    qt.push(make_pair(distance[j], j));
                }
                j++;
            }

            //pop the mini value from the priority queue
            int dis = qt.top().first; 
            cout << dis << "\n";

            total = dis;

            i = qt.top().second;
            qt.pop();
        }
        return total;

}
int main(){
    int num_vertices;
    cin >> num_vertices;
    
    int num_edges;
    cin >> num_edges;    
    vector<vector<int>>graph(num_vertices, vector<int>(num_vertices, -1));

    int a, b, val;
    for(int i=0;i<num_edges;i++){
        cin >> a;
        cin >> b;
        cin >> val;
        graph[a-1][b-1] = val;
        graph[b-1][a-1] = val;
    }
    int source_vertex;
    cin >> source_vertex;

    int dest_vertex;
    cin >> dest_vertex;

      
    int min_cost = findMinPath(graph, num_vertices, source_vertex-1, dest_vertex-1);

    cout <<  "Minimum cost of total Path " << min_cost <<"\n";

    return 0;
}