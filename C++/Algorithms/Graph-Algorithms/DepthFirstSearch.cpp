//----------Coded By: Ap.darknight-------------//
#include <bits/stdc++.h>
#include<string>
using namespace std;
typedef long long ll;
#define mapL map<ll, ll>
#define mapC map<char,ll>
#define mapS map<string,ll>
#define ff first
#define ss second
#define vecL vector<ll>
#define vecC vector<char>
#define vecS vector<string>
#define pb push_back
#define repf(i,j,k) for(ll i=j; i<k; i++)
#define repb(i,j,k) for(ll i=j; i>k; i--)
#define mod 1000000007
#define bit 32
//----------------------GRAPH LCA---------------------//
vecL level(100001,0), par(100001,-1);

//normal_lifting
int lca(int a, int b){
    ll d = level[a] - level[b];
    while(d>0){
        b = par[b], d--;
    }
    if(a==b) return a;

    while(par[a]!=par[b]) a=par[a], b = par[b];
    return par[a];
}

vecL vis(100001,0), adj[100001];


//Travels whole graph under O(n) time Complexity.
void dfs(int node){
  vis[node]=1;

  for(auto child: adj[node]){
    if(!vis[child]){
      dfs(child);
    }
  }
  return;
}

void solve(){
    dfs();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,n,x,y,k,e;
    // solve() solves your query!!
    solve();

    return 0;
}
