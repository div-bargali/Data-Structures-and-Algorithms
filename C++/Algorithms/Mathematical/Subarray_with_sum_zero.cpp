// C++ program to print all subarrays
// in the array which has sum 0
#include <bits/stdc++.h>
using namespace std;

// Function to print all subarrays in the array which
// has sum 0
vector< pair<int, int> > findSubArrays(int arr[], int n)
{
	// create an empty map
	unordered_map<int, vector<int> > map;

	// create an empty vector of pairs to store
	// subarray starting and ending index
	vector <pair<int, int>> out;

	// Maintains sum of elements so far
	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		// add current element to sum
		sum += arr[i];

		// if sum is 0, we found a subarray starting
		// from index 0 and ending at index i
		if (sum == 0)
			out.push_back(make_pair(0, i));

		// If sum already exists in the map there exists
		// at-least one subarray ending at index i with
		// 0 sum
		if (map.find(sum) != map.end())
		{
			// map[sum] stores starting index of all subarrays
			vector<int> vc = map[sum];
			for (auto it = vc.begin(); it != vc.end(); it++)
				out.push_back(make_pair(*it + 1, i));
		}

		// Important - no else
		map[sum].push_back(i);
	}

	// return output vector
	return out;
}

// Utility function to print all subarrays with sum 0
void print(vector<pair<int, int>> out)
{
	for (auto it = out.begin(); it != out.end(); it++)
		cout << "Subarray found from Index " <<
			it->first << " to " << it->second << endl;
}

// Driver code
int main()
{
	int size;
	cout<<"Enter the size of Array : ";
	cin>>size;
	int arr[size];
	for(int i=0; i<size; i++){
	    cin>>arr[i];
	}
	vector<pair<int, int> > out = findSubArrays(arr, size);

	// if we didn’t find any subarray with 0 sum,
	// then subarray doesn’t exists
	if (out.size() == 0)
		cout << "No subarray exists";
	else
		print(out);

	return 0;
}
