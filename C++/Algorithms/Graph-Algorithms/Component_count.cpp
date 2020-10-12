/* counting the number of components is simple dfs implementation.
A simple knowledge of DFS is enough for this problem.
We just need to run dfs starting from any node.
In one dfs all the nodes of the same component will be visited.
Thus this is one component.
The count of dfs run is simply the number of components in the graph
*/


#include<iostream>
using namespace std;
#include<queue>
#include<map>
#include<math.h>
#define lli long long int
#include<vector>
#define vi vector<int>
#define mod 1000000007
#define pb push_back
#define fo(i,n) for(int i=1;i<=n;i++)

#include <bits/stdc++.h>

vi adj[100003];
int vis[100003],member;

void dfs(int node){
    vis[node]=1;
    member++;
    for(int child: adj[node]){
        if(!vis[child]){
            dfs(child);
        }
}
}

int main(){
    int t,n,m,a,b;
    cin>>t;

    while(t--){
        lli ans=1,cc=0;

        cin>>n>>m;

        fo(i,n) vis[i]=0, adj[i].clear();

        fo(i,m) cin>>a>>b, adj[a].pb(b), adj[b].pb(a);
        fo(i,n)
        if(!vis[i]){
        	      member=0;
                  cc++; dfs(i);
                  ans = (ans * member)%mod;
        }
       cout<<cc<<" "<<ans<<endl;
    }

}
