#include <iostream>
using namespace std;
#define ll long long int
#define MAXSIZE 100

int main() {
	ll arr[MAXSIZE],i=0;
	while(cin>>arr[i]){
	    i++;
	}
	ll n = i;
	
	ll pos[n],neg[n];
	    ll i,pi=0,pn=0,xp=0,xn=0;
	    for(i=0;i<n;i++){
	        if(arr[i] >= 0){
    	        pos[pi] = arr[i];
    	        pi++;
    	    }
    	    else{
    	        neg[pn] = arr[i];
    	        pn++;
    	    }
	    }
	    for(i=0;i<n;i++){
	        if(i%2==0 && xp<pi){
	            arr[i] = pos[xp];
	            xp++;
	        }
	        else if(i%2!=0 && xn<pn){
	            arr[i] = neg[xn];
	            xn++;
	        }
	        else if(xp>=pi){
	            arr[i] = neg[xn++];
	        }
	        else if(xn>=pn){
	            arr[i] = pos[xp++];
	        }
	    }
	
	for(i=0;i<n;i++){
	    cout<<arr[i]<<" ";
	}
	return 0;
}