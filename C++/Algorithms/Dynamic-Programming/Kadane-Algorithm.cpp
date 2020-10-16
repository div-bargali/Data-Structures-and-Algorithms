#include<bits/stdc++.h>
using namespace std;
//function to find the maximum sum of contiguous sub-array
int maxSumSubArray(int array[], int size) {
    int current_sum = array[0], maximum_sum = array[0];
    for(int i = 1; i < size; ++i) {
        if(array[i] > current_sum + array[i]) {
            current_sum = array[i];
        }
        else {
            current_sum += array[i];
        }
        if(current_sum > maximum_sum) {
            maximum_sum = current_sum;
        }
    }
    return maximum_sum;
}

int main() {
	
    int array[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    // Other test cases: array[] = {-1, -2, -3, -4}
    int size = sizeof(array) / sizeof(array[0]);
    int maximum_sum = maxSumSubArray(array, size);
    cout << "Largest sum of contiguos subarray is " << maximum_sum << endl;

	return 0;
}

