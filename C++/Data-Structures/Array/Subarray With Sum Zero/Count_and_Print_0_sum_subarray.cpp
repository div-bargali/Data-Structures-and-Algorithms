/* Question : COUNT AND PRINT the number of subarrays with sum as 0.

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

#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector<pair<int, int>> allSubarrays; //A vector to store the indices of subarrys of sum 0
/*Using vectors to store pairs instead of 2D arrays - as number of subarrays can go up 
to n*(n+1)/2 (when all the elements are 0).

COUNT OF SUBARRAYS is not predetermined .
Hence static allocation will cause wastage of space*/

int subarray_sum_0(int *arr, int n)
{
    int ans = 0;
    int sum = 0; //sum stores the cumulative sum from index 0 to i

    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
       
        if (sum == 0)
        {
            ans++;
            allSubarrays.push_back({0, i});
        }

        /*Search if (sum-0 ) is found in the map.
        If sum is already found in the map, it means that we have few elements in the middle
        which add up to a sum of 0 .
        Hence we again obtain the same sum value*/

        if (mp.find(sum) != mp.end())
        {
            for (auto it : mp[sum])
            {
                ans+=mp[sum].size();
                /*storing all the indices which had the same sum so that the subarray in between 
                them has their sum as 0*/
                allSubarrays.push_back(make_pair(it + 1, i));
            }
        }
        mp[sum].push_back(i);
    }
    return ans;
}

int main()
{
    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    int total = subarray_sum_0(arr, size);

    cout<<'\n';
    if (total == 0)
        cout << "There is no subarray with sum 0";
    else
    {
        cout << "Count of subarrays with sum 0 : " << total << endl;
        
        
        cout << "\nPrinting the Subarrays with sum 0 \n";
        int count = 1;
        //printing all subarrays
        for (int i = 0; i < (int)allSubarrays.size(); i++)
        {
            int l = allSubarrays[i].first, r = allSubarrays[i].second;
            cout << count++ << ". ";
            for (int j = l; j <= r; j++)
            {
                cout << arr[j] << " ";
            }
            cout << '\n';
        }
    }

    return 0;
}