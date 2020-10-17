// A C++ program for Prim's Minimum 
// Spanning Tree (MST) algorithm. The program Used
//the adjacency matrix 
//Ask the input from the usee the num of edges, 
//num of vertices and the graph with the value of each edge
#include <bits/stdc++.h>
using namespace std;
struct compare{
        bool operator()(pair<int, int>&a, pair<int, int>&b){
            return a.first > b.first;
        }
    };
//function to calculate mst
int minSpaingTree(vector<vector<int>>& graph, int n) {
        int connect = 0;
        
        int i = 0 ;

        //maintian a visited array for all vertices
        vector<bool>visited(n, false);

        int total = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, compare>qt;
        
        while( ++connect < n ){

            visited[i] = true;
            int j = 0;
            while(j < n){
                if (!visited[j] && graph[i][j]!=-1){
                    qt.push(make_pair(graph[i][j], j));
                }
                j++;
            }
            //pop the mini value from the priority queue
            int dis = qt.top().first;

            // add the distance in the path min value
            total+=dis;

            //used to print the path 
            cout << i+1 <<"--->"<<qt.top().second +1<<"\n";
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
    for(int i=0;i<graph_size;i++){
        cin >> a;
        cin >> b;
        cin >> val;
        graph[a-1][b-1] = val;
        graph[b-1][a-1] = val;
    }

     cout << "path taken\n";
      
     int min_cost = minSpaingTree(graph, num_vertices);

     cout <<  "Minimum cost of total Path " << min_cost <<"\n";

     return 0;


}