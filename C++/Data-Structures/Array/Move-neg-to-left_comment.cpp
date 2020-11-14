#include<bits/stdc++.h>
using namespace std;
void printArray(int array[], int size) { 
    for (int i = 0; i < size; ++i) {
      cout << array[i] << " ";         //print array
   } 
   cout << endl;
}   
void shiftArray(int array[], int size) { 
    int left = 0, right = size-1;
    while(left <= right) {               //sorting
        if(array[left] < 0 && array[right] < 0) {
           left++;
        }
        else if(array[left] < 0 && array[right] > 0) {
           right--;
        }
        else if(array[left] > 0 && array[right] < 0) {
           swap(array[left], array[right]);
           right--;
           left++;
        }
        else {
           right--;
        }
    }
} 
int main() {
   int size;
   cout << "Enter the size of array:\n";
   cin >> size;                     //input size
   int array[size];
   cout << "Enter the elements of the array:\n";
   for(int i = 0; i < size; ++i) {
      cin >> array[i];               //input value
   }
   cout << "Original Array:\t";
   printArray(array, size);            //print original array
   cout << "After moving all negative elements to left:\t";
   shiftArray(array, size);            //Run sorting function
   printArray(array, size);            //print shift array
   return 0;
}


