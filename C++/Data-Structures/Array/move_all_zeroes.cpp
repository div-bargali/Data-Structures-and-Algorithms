/** Move all zeroes to end of array    **/


#include <iostream> 
using namespace std; 

void pushZerosToEnd(int arr[], int n) 
{ 
	int count = 0; 
	for (int i = 0; i < n; i++) 
		if (arr[i] != 0) 
			arr[count++] = arr[i]; 

	while (count < n) 
		arr[count++] = 0; 
} 

int main() 
{ 

	int arr[10000],n;
  cin>>n;
  for(int i=0;i<n;i++)
  {
   cin>>arr[i];
   }

	pushZerosToEnd(arr, n); 
	cout << "Array after pushing all zeros to end of array :\n"; 
	for (int i = 0; i < n; i++) 
		cout << arr[i] << " "; 
	return 0; 
} 
