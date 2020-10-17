#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#define vi vector<int>
#define lli long long int
#define fo(i,n) for(int i=1;i<=n;i++)
#define foo(i,n) for(int i=0;i<n;i++)
#define ff first
#define ss second
#define pb push
#define vii vector<lli>
#define ok ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#define vp vector<pair<lli,lli>>
#include <map>

stack<char> s;

bool check(char c){
	if(s.empty()) return false; 
  if(c==']'){
  	if(s.top()!='[') return false;
  	else{
  		s.pop(); return true;
	  }
  }
  else if(c=='}'){
  	if(s.top()!='{') return false;
  	else{
  		s.pop(); return true;
	  }
  }
  if(c==')'){
  	if(s.top()!='(') return false;
  	else{
  		s.pop(); return true;
	  }
  }
}

int main(){
	
	ok
	
	int t; cin>>t;
	
	while(t--){
		bool flag=true;
		string str; cin>>str;
		if(str.length()%2){
		 cout<<"not valid"<<endl; continue; }
		
		foo(i,str.length()){
			if(str[i]=='(' || str[i]=='{' || str[i]=='[')
			s.push(str[i]);
			
		    else if(str[i]==']' || str[i]==')' || str[i]=='}')
			flag=check(str[i]);
			if(!flag) break;
			
		}
  
       if(flag) cout<<"valid"<<endl;
       else cout<<"not valid"<<endl;
		
	}
		
    
	
}
