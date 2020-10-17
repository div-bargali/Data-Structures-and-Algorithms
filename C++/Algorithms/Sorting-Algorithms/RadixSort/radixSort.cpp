//Radix Sort
//Radix sort is a sorting technique that sorts the elements by first grouping the individual digits of the same place value.
// Then, sort the elements according to their increasing/decreasing order.

// Time Complexity: O(l*(n+k)),where l is the number of digits in each item, and k is the number of values each digit can have.
//Space Complexity: O(n + k), where n is the number of items to sort

// C++ implementation of Radix Sort
#include <iostream>
using namespace std;
 
// A function to get maximum value in array
int getMax(int ar[], int n)
{
    int max = ar[0];
    for (int i = 1; i < n; i++)
        if (ar[i] > max)
            max = ar[i];
    return max;
}
 
// A function to do counting sort on the basis of significant places.
void countingSort(int ar[], int size, int place) {
  const int max = 10;
  int output[size];
  int count[max];

  for (int i = 0; i < max; ++i)
    count[i] = 0;

  // Calculate count of elements
  for (int i = 0; i < size; i++)
    count[(ar[i] / place) % 10]++;

  // Calculate cummulative count
  for (int i = 1; i < max; i++)
    count[i] += count[i - 1];

  // Place the elements in sorted order
  for (int i = size - 1; i >= 0; i--) {
    output[count[(ar[i] / place) % 10] - 1] = ar[i];
    count[(ar[i] / place) % 10]--;
  }

  for (int i = 0; i < size; i++)
    ar[i] = output[i];
}

// Radix Sort function
void radixsort(int arr[], int n)
{
    // Find the maximum number to know number of digits
    int max = getMax(arr, n);
 
    // Do counting sort for every digit based on place value.
    for (int place = 1; max / place > 0; place *= 10)
        countSort(arr, n, place);
}
 
// A function to print an array
void print(int ar[], int n)
{
    for (int i = 0; i < n; i++)
        cout << ar[i] << " ";
}
 
// Driver Code
int main()
{
     //enter no of elements
    int n;
    cin>>n;
    int arr[n];
    //enter elemetns
    for(int i=0;i<n;i++)
      cin>>arr[i];

    radixsort(arr, n);                 // Function Call
    printf("Array after Radix Sort: ");
    print(arr, n);
    return 0;
}