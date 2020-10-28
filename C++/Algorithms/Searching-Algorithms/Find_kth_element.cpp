/* Problem Statement
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
Find the kth positive integer that is missing from this array
Constraints:
1 <= arr.length <= 1000
1 <= arr[i] <= 1000
1 <= k <= 1000
arr[i] < arr[j] for 1 <= i < j <= arr.length
*/
#include<bits/stdc++.h>
using namespace std;
int findKthPositive(vector<int>& arr, int k)
{
    int b[10001];
    int i; int ans = 0;
    for (i = 0; i <= 10000; i++)
        b[i] = i;                 //stores value i at every index i
    for (i = 0; i < arr.size(); i++)
        b[arr[i]] = -1;           //stores -1 for elements already in the array

    for (i = 1; i <= 10000; i++)
    {
        if (b[i] != -1)            //if it is not -1, then it is counted towards kth integer, so k--
            k--;
        if (k == 0)                 // if k becomes 0, it means we have found kth positive integer
        {
            ans = i;             //value is stored in ans
            break;
        }
    }
    return ans;
}
int main()
{
    vector<int> arr;
    int n, k, i;
    cin >> n >> k;
    for (i = 0; i < n; i++)           //takes input from user
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    cout << findKthPositive(arr, k);
    return 0;
}