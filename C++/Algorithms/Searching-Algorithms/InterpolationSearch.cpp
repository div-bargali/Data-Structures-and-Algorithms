//Interpolation Search
//The Interpolation Search is an improvement over Binary Search for instances, where the values in a sorted array are uniformly distributed.
// Binary Search always goes to the middle element. On the other hand, interpolation search may go to different locations according to the 
//value of the key being searched.

//Approach: The idea of formula is to return higher value of pos
// when element to be searched is closer to arr[high]. And
// smaller value when closer to arr[lo]
//pos = low + [ (x-arr[low])*(high-low) / (arr[high]-arr[low]) ]

//Time Complexity: O (log (log n)),If elements are uniformly distributed
//Auxiliary Space: O(1)

// C++ implementation of Interpolation Search

#include<bits/stdc++.h> 
using namespace std; 
  

int interpolationSearch(int arr[], int n, int x)        //x is the element to be searched and n is the size of the array
{ 
    // Find indexes of two corners 
    int low = 0, high = (n - 1); 
  
    while (low <= high && x >= arr[low] && x <= arr[high]) 
    { 
        if (low == high) 
        { 
            if (arr[low] == x) return low; 
            return -1; 
        } 
        
        int pos = low + (((double)(high - low) / 
            (arr[high] - arr[low])) * (x - arr[low])); 
  
        if (arr[pos] == x) 
            return pos; 
  
        // If x is larger, x is in upper part 
        if (arr[pos] < x) 
            low = pos + 1; 
  
        // If x is smaller, x is in the lower part 
        else
            high = pos - 1; 
    } 
    return -1; 
} 
  
// Driver Code 
int main() 
{ 
    int arr[] = {10, 12, 13, 16, 18, 19, 20, 21, 
                 22, 23, 24, 33, 35, 42, 47}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    int x = 18; // Element to be searched 
    int index = interpolationSearch(arr, n, x);         //function called
  
    // If element was found 
    if (index != -1) 
        cout << "Element found at index " << index; 
    else
        cout << "Element not found."; 
    return 0; 
} 
  