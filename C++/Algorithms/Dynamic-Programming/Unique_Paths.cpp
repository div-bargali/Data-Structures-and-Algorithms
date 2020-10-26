/*
Given a A X B matrix with your initial position at the top-left cell, find the number of possible unique paths to reach the bottom-right cell of the matrix from 
the initial position.
Note: Possible moves can be either down or right at any point in time, i.e., we can move to matrix[i+1][j] or matrix[i][j+1] from matrix[i][j].
*/


#include<bits/stdc++.h>
using namespace std;

int NumberOfPath( int, int);

// Position this line where user code will be pasted

int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        
        //calling NumberOfPath() function
        cout << NumberOfPath(a,b) << endl;
    }
    return 0;
}



int dp[16][16];
//top-down approach
int NumberOfPath(int a,int b)
{
    memset(dp,-1,sizeof(dp));
    if(a ==0 || b==0)
    return 0;
    if(dp[a][b]!=-1)
    return dp[a][b];
    else if(b==1) return 1;
    
    return dp[a][b]=NumberOfPath(a,b-1) + NumberOfPath(a-1,b);
}
/*
Bottom Up Approach
int NumberOfPath(int a, int b) {
    //code here
 int dp[a+1][b+1];
 
 for(int i=0;i<a+1;i++)
 {
     for(int j = 0 ;j<b+1;j++)
     {
         if(i==0 || j==0 ) dp[i][j] =0;
         else if(j==1) dp[i][j] = 1;
         else
         dp[i][j] = dp[i-1][j] + dp[i][j-1];
     }
 }
 return dp[a][b];
}*/
