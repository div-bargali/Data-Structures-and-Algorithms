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
