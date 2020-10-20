//Minimum Number of Jumps to reach End of an Array
//Approach Used - Dynamic Programming
/*
Given an array of integers where each element represents the max number of steps that can be made forward from that element. 
The task is to find the minimum number of jumps to reach the end of the array (starting from the first element). 
If an element is 0, then cannot move through that element.

Input - 1 3 5 8 9 2 6 7 6 8 9
Output - 3

from position 0 , element 1 , we can move 1 step ahead,
from position 1, element 3 , we can move 3 steps ahead till position 5th, element 9
from position 5,  it will take just one step more to reach end of an array , since we can move 9 steps.
i.e total_steps = 1 + 1 + 1 
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int jumps(int arr[],int n)
{
    if(arr[0] == 0) return -1;   
    int dp[n];
    dp[0] = 0;
    for(int i=1;i<n;i++)
    {
        dp[i] = INT_MAX;
        for(int j=0;j<i;j++)
        {
            if(i<=arr[j]+j)
            {
                dp[i] = min(dp[i],dp[j]+1);
            }
        }
    }
    return (dp[n-1]==INT_MAX)?-1:dp[n-1];
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    cout<<jumps(arr,n)<<endl;
	}
	return 0;
}
