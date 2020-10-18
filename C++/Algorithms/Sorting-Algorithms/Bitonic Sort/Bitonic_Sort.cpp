#include<bits/stdc++.h>
using namespace std;

//compared swapping of elements interms of dir == 0 or dir == 1
void compAndSwap(int a[], int i, int j, int dir)
{
	if (dir == (a[i] > a[j]))
		swap(a[i], a[j]);
}


void bitonicMerge(int a[], int low, int cnt, int dir)
{
	//x0 <= x1 …..<= xi  and  xi >= xi+1….. >= xn-1
	//if dir == 1, bitonic sequence is sorted in ascending order
	//else it is sorted in descending order.

	if (cnt > 1)
	{
		int k = cnt / 2;

		for (int i = low; i < low + k; i++)
			compAndSwap(a, i, i + k, dir);

		bitonicMerge(a, low, k, dir);
		bitonicMerge(a, low + k, k, dir);
	}
}

void bitonicSort(int a[], int low, int cnt, int dir)
{
	if (cnt > 1)
	{
		int k = cnt / 2;

		//first in ascending order
		bitonicSort(a, low, k, 1);

		//now in descending order
		bitonicSort(a, low + k, k, 0);

		//now merging opposite ordered halves.
		bitonicMerge(a, low, cnt, dir);
	}
}


//This program is to sort a bitonic sequence in ascending order.
void sort(int a[], int N, int up)
{
	bitonicSort(a, 0, N, up);
}

int main()
{
	int n;
	cin >> n;
	int a[n];

	for (int i = 0; i < n; i++)
		cin >> a[i];

	int up = 1;
	sort(a, n, up);

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";

	cout << "\n";

	return 0;
}

/*

Input:

8
3 7 4 8 6 2 1 5

Output:

1 2 3 4 5 6 7 8


*/