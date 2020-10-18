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

const lli N = 100005; 
lli p = 998244353; 

lli factorialNumInverse[N + 1]; 

lli naturalNumInverse[N + 1]; 

lli fact[N + 1]; 

 void InverseofNumber() 
{ 
	naturalNumInverse[0] = naturalNumInverse[1] = 1; 
	for (int i = 2; i <= N; i++) 
		naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p; 
} 

void InverseofFactorial() 
{ 
	factorialNumInverse[0] = factorialNumInverse[1] = 1; 
	for (int i = 2; i <= N; i++) 
		factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p; 
} 
void factorial() 
{ 
	fact[0] = 1; 
	for (int i = 1; i <= N; i++) { 
		fact[i] = (fact[i - 1] * i) % p; 
	} 
} 
lli Binomial(lli N, lli R) 
{ 
	lli ans = ((fact[N] * factorialNumInverse[R]) 
			% p * factorialNumInverse[N - R]) 
			% p; 
			
	cout<<fact[N]<<" "<<factorialNumInverse[R]<<" "<<factorialNumInverse[N-R]<<endl;		
	return ans; 
} 

int main() 
{ 
	InverseofNumber(); 
	InverseofFactorial(); 
	factorial(); 
	
	int t;
	cin>>t;
	while(t--){
		lli n,r;
		cin>>n>>r;
		cout<<Binomial(n,r)<<endl;
	}
  

	return 0; 
} 

