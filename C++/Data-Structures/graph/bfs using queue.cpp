#include<bits/stdc++.h>
using namespace std;
int n=1000;
vector<int> graph[1002];
int vis[n]={0};


void bfs(int root)         //bfs using queue also used to find min path
{vis[root]=1;
queue<int>q;
q.push(root);
while(!q.empty()){ 
   int k=q.pop();
   for(i=0;i<graph[k].size();i++){
      if(vis[graph[k][i]]==0){q.push(graph[k][i])vis[graph[k][i]]=1;}
}
    

int main() {

int n;                  //no of vertex
int e;                  //no of edges
for(i=0;i<e;i++)
{int c,d;               //which two have edges
cin>>c>>d;
graph[c].push_back(d);      //create tree
graph[d].push_back(c);
}
bfs(1);                  //call bfs function
   return 0;
}





