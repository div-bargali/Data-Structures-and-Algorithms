/*Given the array nums, obtain a subsequence of the array whose sum of elements is strictly greater than the sum of the non included elements in such subsequence.

If there are multiple solutions, return the subsequence with minimum size and if there still exist multiple solutions, return the subsequence with the maximum total sum of all its elements. A subsequence of an array can be obtained by erasing some (possibly zero) elements from the array.

Note that the solution with the given constraints is guaranteed to be unique. Also return the answer sorted in non-increasing order
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> minSubsequence(vector<int>& a)
{
    sort(a.begin(), a.end());  //sorts the array
    vector<int> v;
    int i, sum = 0, p = 0;
    for (i = 0; i < a.size(); i++)
        sum += a[i];               //stores sum of array
    for (i = a.size() - 1; i >= 0; i--)    //iterates from back of the array
    {
        if (p > (sum - p))           //if sum of p becomes greater than sum-p, it breaks
            break;
        else
        {
            p += a[i];               //p stores current sum of already iterated array elements
            v.push_back(a[i]);      v stores the elements
        }
    }
    return v;
}
int main()
{
    vector<int> a;
    int n, i;
    cin >> n;
    for (i = 0; i < n; i++)           //takes input from user
    {
        int b;
        cin >> b;
        a.push_back(b);
    }
    vector<int> d = minSubsequence(a);
    for (i = 0; i < d.size(); i++)      //prints the required subsequence
        cout << d[i] << " ";
    return 0;
}