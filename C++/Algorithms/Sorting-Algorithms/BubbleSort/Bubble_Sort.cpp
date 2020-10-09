// Bubble Sort : Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.

#include<iostream>
using namespace std;

// swap two elements
void swap(int *x, int *y)  
{  
    int temp = *x;  
    *x = *y;  
    *y = temp;  
}  

//Function to implement bubble sort  
void bubbleSort(int arr[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)      
      
    // Last i elements are already in place  
    for (j = 0; j < n-i-1; j++)  

        // swap if arr[j] is greater than arr[j+1]   
        if (arr[j] > arr[j+1])  
        {
           swap(&arr[j], &arr[j+1]);  
        }   

}  
// DRIVER CODE
int main()  
{  
    int n;
    cout<<"Enter the size of the array"<<endl;
    // enter size of array
    cin>>n; 

    int arr[n];
    cout<<"Input the array"<<endl;
     
    // Input the array 
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    bubbleSort(arr, n);  
    cout<<"Sorted array: \n";  
    
    // print the sorted array 
     for(int i=0;i<n;i++)
     {
         cout<<arr[i]<<" ";
     }

    return 0;  
}  
  
// CONTRIBUTOR : Harsh Prakash