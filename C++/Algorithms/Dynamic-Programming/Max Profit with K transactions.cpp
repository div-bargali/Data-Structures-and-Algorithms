#include <bits/stdc++.h>
using namespace std;

// Function try to find maximum profit by doing k transactions
int maxProfitWithKTransactions(vector<int> prices, int k) {
  
    //Base Case
    if(prices.size() == 0)
        return 0;

    //2D DP array with transactions as row and price array as column
    vector<vector<int>> profits(k+1, vector<int>(prices.size(),0));

    for(int i =1;i<k+1;i++)
    {
        int maxValSoFar = INT_MIN;
        for(int j=1;j<prices.size();j++)
        {
            // find Maximum possible prefix value for each instance
            maxValSoFar = max(maxValSoFar, profits[i-i][j-i]-prices[j-1]);
            // Check whether buying this stock is greater than previous day stocks
            profits[i][j] = max(profits[i][j-1], maxValSoFar + prices[j]);
        }
    }

    return profits[k][prices.size()-1];
}
