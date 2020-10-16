#include<bits/stdc++.h>
using namespace std;
void rotate(int array[], int size) {
	// when the array contains only one element
	if(size == 1) {
		return;
	}
	int i = size - 1;
	// swaps the last element repeatidly
	while(i > 0) {
		swap(array[i], array[i-1]);
		i--;
	}
}
void printArray(int array[], int size) {
	for(int i = 0; i < size; ++i) {
		cout << array[i] << " ";
	}
	cout << endl;
}
int main()
 {
	int size;
	cout << "Enter the size of array:\n";
	cin >> size;
	int array[size];
	cout << "Enter the elements of the array:\n";
	for(int i = 0; i < size; ++i) {
		cin >> array[i];
	}
	cout << "Original Array:\t";
	printArray(array, size);
	cout << "After Rotating:\t";
	rotate(array, size);
	printArray(array, size);
	return 0;
}