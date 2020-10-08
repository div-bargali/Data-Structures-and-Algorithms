/*
Given an array of n integers, are there elements a, b, c in nums such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.
Notice that the solution set must not contain duplicate triplets.
*/

/* Sample inputs and outputs
Input: arr = [-1,0,1,2,-1,-4]
Output: [-1,-1,2] [-1,0,1]

Input: arr= [0]
Output: []
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;


//Function to check if triplet with sum = 0 exists
void threeSum(int arr[],int n) {
        
    sort(arr,arr + n);
    for(int i = 0; i < n; i++)
    {
        if(i != 0 && arr[i] == arr[i-1])continue;
        int j = i+1, k = n-1;
        while(j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if(sum == 0)
            {
                cout<<"[ "<<arr[i]<<", "<<arr[j]<<", "<<arr[k]<<"] ";
                j++;
                while (j < k && arr[j] == arr[j-1]) j++;
               
            }
        else if (sum > 0) k--;
        else j++;
        }
    }
        
}

//Driver code to test the threeSum function
int main(){

    int arr[]={ -1, 0, 1, 2, -1, -4 };
    int n = 6;
    
    threeSum(arr,n);

    return 0;
}