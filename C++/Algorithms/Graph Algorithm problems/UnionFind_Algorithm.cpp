#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#define vi vector<int>
#define lli long long int
#define rep(i,n) for(int i=1;i<=n;i++)
#define ff first
#define ss second
#define pb pushback
#define vii vector<lli>
using namespace std;

vi par(100002);

int min(int a , int b){
  if(a>b)
   return b;
   return a;
}

int find(int a){
  if(par[a] < 0) return a;
  
  else return par[a] = find(par[a]);   
  
}

void uni(int a, int b){
  int x = find(a);
  int y = find(b);
  int parY = par[y];
  //cout<<"\nparent of "<<a<<" is"<<par[x]<<"\n";
  //cout<<"\nparent of "<<b<<" is"<<par[y]<<"\n";
  if(x!=y){
    par[b] = x;
    par[x] = min(parY , par[x]);
    //cout<<"\n this is min of "<<par[y]<<"and "<<par[x]<<"\n";
  }
  
  return;
 }
 
int main(){
  
  int n,m;
  cin>>n>>m;
  rep(i,n) par[i] = -i;
  rep(i,m){
    int a,b;
    cin>>a>>b;
    uni(a,b);
  }
  
 rep(i,n)
  cout<<"parent of "<<i<<"-->   "<<par[i]<<endl;
  
  int q; cin>>q;
  while(q--){
    int x,y; cin>>x>>y;
    int m = find(x);
    int n = find(y);
    
    if(m==n){
       cout<<"TIE"<<endl; continue;}
    if(par[m] < par[n])
    cout<<x<<endl;
    else cout<<y<<endl;;
  }
} 
  
  



















