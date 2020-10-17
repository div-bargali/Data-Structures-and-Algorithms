#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#define vi vector<int>
#define lli long long int
#define fo(i,n) for(int i=1;i<=n;i++)
#define foo(i,n) for(int i=0;i<n;i++)
#define ff first
#define ss second
#define pb push_back
#define vii vector<lli>

#define ok ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#define vp vector<pair<lli,lli>>
#include <map>           
lli mod=1000000007;         
#define max 100003

int go(string &s,string &t){
	
	int n=s.length();
	int m=t.length();
    
	int dp[n+1][m+1];
	
for(int i=0;i<=m;i++) dp[i][0]=1;
	for(int i=0;i<=n;i++)  dp[0][i]=max;
	                                                  
	fo(i,n){
		fo(j,m){
		  
		  char c=s[i-1];
		  int k;
		  for(k=j-1;k>=0;k--){
		  	if(t[k]==c)
		  	break;
		  }
		  if(k==-1)
		  dp[i][j]=1;
		  else{
		  	dp[i][j]=min(dp[i-1][j],dp[i-1][k]+1);
		  }
		 
		}
	}
	 int ans=dp[n][m];
		  if(ans>=max) return -1;
		  return ans;	
			
}

int main(){
	int t; cin>>t;
	while(t--){
		string s,t;
		cin>>s>>t;
		int ans=go(s,t);
		cout<<ans<<endl;
	}
}





