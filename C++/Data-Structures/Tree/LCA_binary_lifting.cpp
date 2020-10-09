
/* find least common ancestor
       
       time complexity    O(logn)
       
       using binary lifting
       
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
#define maxN 10
#include <bits/stdc++.h>

//ques---  find the dist bw two nodes in a tree


vi adj[1001];
vi level(1001);

int LCA[1001][maxN+1];

void dfs(int node, int lvl, int parent){
	
	level[node]=lvl;
	LCA[node][0]=parent;
//	cout<<node<<"jiji";
	
	for(int child: adj[node]){
		if(child!=parent)
		dfs(child,lvl+1,node);
	}
	
}

void init(int n){
	dfs(1,0,-1);
	
		for(int j=1;j<=maxN;j++){
		for(int i=1;i<=n;i++){
		if(LCA[i][j-1]!=-1){
			int temp=LCA[i][j-1];
			LCA[i][j] = LCA[temp][j-1];
		}
	else  LCA[i][j] = -1;
	}
}
}




// this returns the least common ancestor of two nodes a and b


int getLCA(int a, int b){

	int diff;
	
if(level[b]<level[a]) swap(a,b);

diff = level[b] - level[a];
	
	while(diff>0){
		int i = log2(diff);
		
		b = LCA[b][i];
		
		diff -= (1<<i);
	}
	
	if(a == b) return a;
	
	for(int i=maxN;i>=0;i--){
		if(LCA[a][i]!=-1 && (LCA[a][i]!=LCA[b][i]))
		a = LCA[a][i], b = LCA[b][i];
	}
	
	return LCA[a][0];
}

int getDist(int a, int b){
	
	int lca=getLCA(a,b);
	//if(level[a]>level[b])
	return level[a] + level[b] - 2*level[lca];
	
}

int main(){
	                                                    //     now  working fine    :)))
	                                                    
														// it was throwing running time error from 2 hours 
	                                                    // bcoz in for loop there was i = 0; i<=maxN  i.e, maxN+1 times
	                                                    // while I declared LCA as LCA[1001][maxN] should be maxN+1 or bigg....
	                                                    // so remember while assigning sizes globally.
	int n,a,b; cin>>n;
	
	fo(i,n-1)
	cin>>a>>b, adj[a].push_back(b), adj[b].push_back(a);
	
init(n);
	

	
	int q; cin>>q;
	
	while(q--){
		cin>>a>>b;
		int d= getDist(a,b);
		cout<<d<<endl;
	}
	
}
