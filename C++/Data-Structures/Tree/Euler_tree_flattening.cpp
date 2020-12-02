// this template is for flattening tree traversal using DFS
// this technique is very useful in competitive coding when you have to perform queries on trees.
/* the approach is---->
 
    make the start timer to 0
    
    start dfs and upon reaching any new node assign start time to that node
   and when the dfs for that node completes assign the finish time for that node 
 

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

vi s(1000), t(1000), ft(2000);
vi adj[1000];
int timer = 1;


void dfs(int node, int par){         //defin dfs
   s[node] = timer;
   ft[timer] = node;
   timer++;
   for(int child: adj[node]){
      if(child!=par)
      dfs(child,node);            //recursive
   }
   t[node] = timer;
   ft[timer] = node;
   timer++;
   
}

int main(){                        //driver
   int n; cin>>n;
   fo(i,n-1){
      int a,b;
      cin>>a>>b;
      adj[a].pb(b), adj[b].pb(a);
   }
   
   //timer=1;
   dfs(1,-1);                     
   
   cout<<"\nstart time:  ";
   fo(i,n) cout<<s[i]<<" ";
   cout<<"\nend time:  ";
   fo(i,n) cout<<t[i]<<" ";
   cout<<"\n flat tree: ";
   fo(i,2*n) cout<<ft[i]<<" ";
   
}