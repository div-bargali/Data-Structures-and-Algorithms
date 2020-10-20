/*
Problem Statement - Given a value N, find the number of ways to make change for N cents,
if we have infinite supply of each of S = { S1, S2, .. , SM } valued coins. 
Input:
n = 4 , m = 3
S[] = {1,2,3}
Output: 4
Explanation: Four Possible ways are:
{1,1,1,1},{1,1,2},{2,2},{1,3}.

Approach Used - Dynamic Programming 
*/
#include<bits/stdc++.h>
using namespace std;
int coin_change(int coin[],int n,int cent)
{
    //dp array
    int dp[n+1][cent+1];
    for(int i=0;i<cent+1;i++)
    dp[0][i] = 0;
    for(int i=0;i<n+1;i++)
    dp[i][0] =1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=cent;j++)
        {
            if(coin[i-1]<=j)
            dp[i][j] = dp[i][j-coin[i-1]] + dp[i-1][j];    // counting the number of choices for each  way
            else
            dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][cent];
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
	    int coin[n];
	    for(int i=0;i<n;i++) cin>>coin[i];
	    int cent;
	    cin>>cent;
	    cout<<coin_change(coin,n,cent)<<endl;
	}
	return 0;
}
