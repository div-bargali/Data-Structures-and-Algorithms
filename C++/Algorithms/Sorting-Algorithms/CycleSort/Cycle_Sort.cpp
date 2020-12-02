/*
Cycle sort is an algorithm that minimizes write operations. 
It's slower than O(n^2) sorting on most computers, but it's a good idea to use if you need to use only O(1) for extra memory and the write operation is extremely expensive.
(Like EEPROM, if a write operation shortens the life of the memory)


Original Source(Pesudo Code) : https://stackoverflow.com/questions/3856635/optimizing-a-cycle-sort-implementation

    i = cycleStart
*/

#include<bits/stdc++.h>
using namespace std;

// Sorting the array, Returns the number of writes.
int cycle_sort(int arr[], int size_of_arr) {
    int writes, item, pos;
    writes = 0;

    // Repeat to figure out the cycle's cycle
    for (int i = 0; i < size_of_arr - 1; i++) {
        item = arr[i];
        pos = i;
        for (int j = i + 1; j < size_of_arr; j++) {
            if (arr[j] < item) pos += 1;
        }
        // If pos is equal to cyclestart, it is passed to "continue" because it has reached the beginning of the cycle's cycle.
        if (pos == i) continue;

        // Since itemand arr[pos] are the same, it means they have the same value, so pos is increased
        while (item == arr[pos]) pos += 1;
        swap(arr[pos], item); // swap arr[pos] and item
        writes += 1;

        // Rotate the remaining cycles.
        while (pos != i) {
            // Find where to put the item
            pos = i;
            for (int j = i + 1; j < size_of_arr; j++) {
                if (arr[j] < item) pos += 1;
            }
            // Since itemand arr[pos] are the same, it means they have the same value, so pos is increased
            while (item == arr[pos]) pos += 1;
            swap(arr[pos], item);
            writes += 1;
        }
    }
    return writes; // Return writes to the main function.
}

// main function
int main(void) {
    int n;
    int count = 0;
    int arr[n];

    cin >> n; // n is number of arr element
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // insert element of arr
        count++; // increase count 
    }

    cycle_sort(arr, count); 

    for (int i = 0; i < n; i++)
        cout << arr[i] << " "; // print arr's element
    cout << "\n";

    return 0;
}