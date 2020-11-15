/*Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
Only adjacent values are deleted.
ex) 12333333
= 123
ex2)
1234512345
= 1234512345

*/
#include<bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int>& nums) // this function returns length
{
    int l = 0, i, c = 0;

    for (i = 0; i < nums.size(); i++) // l stores the number of distcinct elements in the array
    {
        if (i == 0)
        {
            l++; continue;
        }
        if (nums[i] == nums[i - 1])
            continue;
        else
            l++;
    }
    for (i = 0; i < nums.size(); i++)
    {
        if (i == 0)
        {
            c++; continue;
        }
        if (nums[i] != nums[i - 1])   //as soon a new element is encountered it is paced at index c
        {
            nums[c] = nums[i];
            c++;
            if (c == l)           //it checks all the distcinct elements have been alloted in the first l indices
                break;
        }
    }
    return l;
}
int main()
{
    vector<int> nums;
    int n, i;
    cin >> n;
    for (i = 0; i < n; i++)           //takes input fro/m user
    {
        int b;
        cin >> b;
        nums.push_back(b);
    }
    int len = removeDuplicates(nums);
    for (i = 0; i < len; i++)      //prints the required distinct elements
        cout << nums[i] << " ";
    return 0;
}
