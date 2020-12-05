// C++ program for insertion sort  

/*
Algorithm that starts from the second data, compares it with the previous data, designates the insertion position, 
moves the data back, and inserts the data in the designated position


Time Complexity : O(n^2)
*/

#include <bits/stdc++.h> 
using namespace std; 
  
void insertionSort(int arr[], int n) 
{  
    int i, key, j;  
    for (i = 1; i < n; i++) // Cycle 
    {  
        key = arr[i];  
        j = i - 1;  
        while (j >= 0 && arr[j] > key) // If arr[j]> arr[i], the value must be swapped, so the value is replaced.
        {  
            arr[j + 1] = arr[j];  // swap
            j = j - 1;  
        }  
        arr[j + 1] = key;  // swap
    }  
}  
  
void printArray(int arr[], int n) // print Array 
{  
    int i;  
    for (i = 0; i < n; i++)  
        cout << arr[i] << " ";  
    cout << endl; 
}  
  
int main()  
{  
    int arr[] = { 5, 13, 11, 15, 16 };  
    int n = sizeof(arr) / sizeof(arr[0]);  // n is arr's size
  
    insertionSort(arr, n);  
    printArray(arr, n);  
  
    return 0;  
}  