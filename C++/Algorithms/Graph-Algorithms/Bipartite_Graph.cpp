/* Bipartite algorithm is very simple to code.
   In this we pass one type of node to root and to every adjacent child of it
   we pass oppsite type and so on for every other node
   */


#include<iostream>
using namespace std;
#include<queue>
#include<map>
#include<math.h>
#define lli long long int
#include<vector>
#define vi vector<int>
#define fo(i,n) for(int i=1;i<=n;i++)

#include <bits/stdc++.h>

vi adj[2003];
int vis[2003] , col[2003];

bool dfs(int node,int color){

	vis[node]=1;
	col[node]=color;

	for(int child: adj[node]){
		if(!vis[child]){
		if(!dfs(child,color^1)) return false;}

		else if(vis[child]==1){
			if(col[child]==col[node]) return false;
		}

	}

	return true;
}

int main(){
	int t,a,b; cin>>t;

	fo(k,t){

		for(int i=0;i<2003;i++) vis[i]=0, adj[i].clear();

		lli n,m; cin>>n>>m;

		while(m--)

     	cin>>a>>b , adj[a].push_back(b) , adj[b].push_back(a);

     	cout<<"Scenario #"<<k<<":"<<endl;

     	if(dfs(1,0))
     	cout<<"Suspicious bugs found!"<<endl;
     	else
     	cout<<"No suspicious bugs found!"<<endl;


	}

}
