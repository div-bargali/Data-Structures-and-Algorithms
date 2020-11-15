/** Move all zeroes to end of array    **/
#include <iostream> 
using namespace std; 

void pushZerosToEnd(int arr[], int n) 
{ 
   int count = 0; 
   for (int i = 0; i < n; i++) 
      if (arr[i] != 0) 
         arr[count++] = arr[i];       //copy the value of arr

   while (count < n) 
      arr[count++] = 0;             //input zero
} 

int main() 
{ 

   int arr[10000],n;
  cin>>n;                        //length of string
  for(int i=0;i<n;i++)
  {
   cin>>arr[i];                     // input string
   }

   pushZerosToEnd(arr, n); 
   cout << "Array after pushing all zeros to end of array :\n"; 
   for (int i = 0; i < n; i++) 
      cout << arr[i] << " ";          //Outputs zero as long as the string.
   return 0; 
} 
