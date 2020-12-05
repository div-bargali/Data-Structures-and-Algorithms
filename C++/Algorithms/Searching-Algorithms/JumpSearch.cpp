/*
In the case of linear search, the value is searched from the first digit in the array.
However, if the value you are looking for is in the back, it is not efficient, so we will grab a certain block and jump to find it instead of going up one by one.
*/

#include<bits/stdc++.h>
using namespace std;

int jump_search(int a[], int n, int find)
{
    int step = sqrt(n); // Formula to calculate the block to jump to. So, use the square root
    int pre_step = 0;

    // If the value of the block jumped from the array is less than the value to be found, the loop continues.
    // If there is a number greater than the value to be found, store the block place in the pre_step variable. 
    while (a[min(step, n) - 1]  < find) 
    { 
        pre_step = step; 
        step += sqrt(n); 
        if (pre_step >= n) return -1; // If the array is not found by the end, it returns -1
    }

    // If the value you are looking for is greater than the value entered in the pre_step variable
    // Raise the pre_step value one by one and perform a linear search to find it.
    while(a[pre_step] < find)
    {
        pre_step++;
        if(pre_step == min(step,n)) return -1;
    }

    // If the number of digits of the value you are looking for is found, it returns the number of digits.
    if(a[pre_step] == find) return pre_step;
    else return -1;
}

void merge(int arr[], int low, int mid, int high){
  int i, j, k;
  int n1 = mid + 1 - low; 
  int n2 = high - mid;
  int l[n1], r[n2];
  for(int i=0; i<n1; i++) l[i]=arr[low+i]; // left
  for(int j=0; j<n2; j++) r[j]=arr[mid+j+1]; // right
  i=0; j=0; k=low;

  while(i<n1 && j<n2){
    if(l[i]<=r[j]) arr[k++]=l[i++];
    else arr[k++]=r[j++];
  }
  while(i<n1) arr[k++]=l[i++];
  while(j<n2) arr[k++]=r[j++];
}

void mergeSort(int arr[],int low,int high){ // sorting 
  int mid;
  if(low<high){
    mid=low+(high-low)/2;

    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
  }
}  

int main()
{
    int n, search;
    cout << "Enter no. of elements in an array: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements in an array: ";
    for(int i=0;i<n;i++) cin >> arr[i];
    mergeSort(arr,0,n-1); // Merge sort is used because the processing speed is rather fast.
    cout << "Enter a number to be searched: ";
    cin >> search;
    int result = jump_search(arr,n,search); // Jump Search
    if(result == -1) cout << search << " is not present in the array." << endl;
    else cout << search << " is present at index no " << result+1 << endl;

    return 0;
}