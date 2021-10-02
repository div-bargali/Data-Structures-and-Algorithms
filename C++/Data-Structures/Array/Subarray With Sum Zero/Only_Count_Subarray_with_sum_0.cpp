/* Question : COUNT(only) the number of subarrays with sum as 0.

    Sample Input:
        5 -2 -3 0 2 -2
    Sample Output :
        6
        The subarrays are :
            1. 5 -2 -3
            2. 0
            3. 5 -2 -3 0
            4. 2 -2
            5. 0 2 -2
            6. 5 -2 -3 0 2 -2
*/

#include<iostream>
#include<map>
using namespace std;

//Time Complexity : O(n) (+ O(log n) because maps take log n take for access)
int subarray_sum_0(int* arr,int n)
{
    int ans=0;
    int sum=0; //sum stores the cumulative sum from index 0 to i
    
    map<int,int> mp; //to store the frequency of cumulative sums
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum==0)
            ans++;

        //Search if (sum-0 ) is found in the map.
        //If sum is already found in the map, it means that we have few elements in the middle
        //which add up to a sum of 0 .
        //Hence we again obtain the same sum value

        if(mp.find(sum)!=mp.end())
        {
            ans+=mp[sum];
        }
        ++mp[sum];
    }
    return ans;
}
int main()
{
    int size;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
        cin>>arr[i];

    int total=subarray_sum_0(arr,size);
    

    if (total == 0)
        cout << "There is no subarray with sum 0";
    else
    {
        cout << "Count of subarrays with sum 0 : " << total << endl;
    }
    return 0;
}