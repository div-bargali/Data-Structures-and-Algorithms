/*
Author: Kumar Shrey
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    ll n,i,j,k;
    //n = Number of Eggs
    // k =Number of Floors
    cout<<"Enter number of eggs: ";
    cin>>n;
    cout<<"Enter number of Floors: ";
    cin>>k;
    ll dp[n+1][k+1];
    for (i = 1; i <= n; i++) {
        dp[i][1] = 1;
        dp[i][0] = 0;
    }

    for (j = 1; j <= k; j++)
        dp[1][j] = j;
    ll ans;
    ll x;
    for (i = 2; i <= n; i++) {
        for (j = 2; j <= k; j++) {
            dp[i][j] = INT_MAX;
            for (x = 1; x <= j; x++) {
                ans = 1 + max(dp[i - 1][x - 1],dp[i][j - x]);
                if (ans < dp[i][j])
                    dp[i][j] = ans;
            }
        }
    }
    cout<<"Minimum Trials: "<<dp[n][k];
    return 0;
}

