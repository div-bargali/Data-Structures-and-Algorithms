/*

Arr = [0, 0, 0, 0, 0, 0]

rangeUpdate1 [0, 2], add 100
Arr = [100, 0, 0, -100, 0, 0]

rangeUpdate1 [1, 5], add 100. 
Arr = [100, 100, 0, -100, 0, 0]
Note: You can not add -100 at 6th index because array length is 6.

rangeUpdate1 [2, 3], add 100
Arr = [100, 100, 100, -100, -100, 0]    

Now we will convert above operation array to prefix sum array as shown below,
Arr = [100, 200, 300, 200, 100, 100]

Which is the final updated array.


*/

#include <bits/stdc++.h>
using namespace std;

void add(int arr[], int N, int lo, int hi, int val)
{
	arr[lo] += val;
	if (hi != N - 1)
	arr[hi + 1] -= val;
}

void updateArray(int arr[], int N)
{
	for (int i = 1; i < N; i++)
		arr[i] += arr[i - 1];
}

void printArr(int arr[], int N)
{
	updateArray(arr, N);
	for (int i = 0; i < N; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// Driver code
int main()
{
	int N = 6;

	int arr[N] = {0};

	add(arr, N, 0, 2, 100);
	add(arr, N, 1, 5, 100);
	add(arr, N, 2, 3, 100);

	printArr(arr, N);
	return 0;
}
