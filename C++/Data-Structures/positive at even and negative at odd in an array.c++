// program to place poisitve no at even and negative no. at odd
// input 10 
// 1 -3 5 6 -3 6 7 -4 9 10
// output 1 -3 5 6 6 -3 7 -4 9 10
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n,temp;
	// cout<<"Enter the size of array\n";
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
	    cin>>a[i];
	}
	
	
	for(int i=0;i<n;i++){
	    if(a[i]<0 && i%2==0){
	       
	        for(int j=i;j<n;j++){
	            if(a[j]>=0){
	                temp=a[i];
	                a[i]=a[j];
	                a[j]=temp;
	                break;
	            }
	        }
	    }
	}
	
	for(int i=0;i<n;i++){
	    cout<<a[i]<<" ";
	}
	return 0;
}
