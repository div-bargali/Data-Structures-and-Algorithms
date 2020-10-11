#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define lli long long int 
#include<math.h>

//odd even
pair<int,int> tree[400003];
lli arr[100003];

void update(int si, int ss, int se, int ind, int val){

	if(ss==se){
		
		if(arr[ind]%2==1)
		tree[ss]={0,1};
		else
		tree[ss]={1,0};
		arr[ind]=val;
		return;
	}
	
	int mid = (ss + se) / 2;
	if(ind<=mid)
	update(2*si, ss, mid, ind, val);
	else
	update(2*si+1, mid+1, se, ind, val );
	
	tree[si].first=tree[2*si].first + tree[2*si+1].first;
	tree[si].second=tree[2*si].second + tree[2*si+1].second;
}

void buildT(int si, int ss, int se){
	if(ss==se)
	{
       if(arr[ss]%2)
       tree[si]={1,0};
       else tree[si]={0,1}; return;
	}
	
	int mid = (ss + se)/2;
	buildT(2*si, ss, mid);
	buildT(2*si+1, mid+1, se);
	
	tree[si].first=tree[2*si].first + tree[2*si+1].first;
	tree[si].second=tree[2*si].second + tree[2*si+1].second;
}


int queryEven(int si, int ss, int se, int qs, int qe){
	    	
			if(se<qs || ss>qe) return 0;
	    	
	    	if(ss>=qs && se<=qe) return tree[si].second;
	    	
	    		int mid=(ss+se)/2;
	    		
		return (queryEven(2*si, ss, mid, qs, qe) + queryEven(2*si +1, mid+1, se, qs , qe));
}


int queryOdd(int si, int ss, int se, int qs, int qe){
	    	
			if(se<qs || ss>qe) return 0;
	    	
	    	if(ss>=qs && se<=qe) return tree[si].first;
	    	
	    		int mid=(ss+se)/2;
	    		
		return (queryOdd(2*si, ss, mid, qs, qe) + queryOdd(2*si +1, mid+1, se, qs , qe));
}

int main(){
	int n,q,l,r,code; cin>>n;
	
	for(int i=1;i<=n;i++)   cin>>arr[i];
	
	buildT(1,1,n);
	
	cin>>q;
	while(q--){
		
		cin>>code>>l>>r;
		if(code==0){
			if(arr[l]%2 == r%2) continue;
			else update(1,1,n,l,r);
			cout<<endl;	for(int i=1;i<=n;i++) cout<<arr[i]<<"  "; cout<<endl;
		}
		
	    else	if(code==1){
			int x = queryEven(1,1,n,l,r);
			cout<<x<<endl;
		}
			
		else{
			int y= queryOdd(1,1,n,l,r);
			cout<<y<<endl;
		}
		
	}
	

}
