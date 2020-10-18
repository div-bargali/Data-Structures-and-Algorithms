#include<bits/stdc++.h>
using namespace std;

void partition(int a[], int l, int r, int& i, int& j)
{
	//3 Way QuickSort, is divided in 3 parts
	//for ar[l to r]
	//a) ar[l to i] elements less than pivot.
	//b) ar[i+1 to j-1] elements equal to pivot.
	//c) ar[j to r] elements greater than pivot.

	i = l - 1, j = r;
	int p = l - 1, q = r;
	int v = a[r];

	while (true) {

		while (a[++i] < v);

		while (v < a[--j])
			if (j == l)
				break;
		if (i >= j)
			break;

		swap(a[i], a[j]);
		if (a[i] == v) {
			p++;
			swap(a[p], a[i]);
		}
		if (a[j] == v) {
			q--;
			swap(a[j], a[q]);
		}
	}
	swap(a[i], a[r]);

	j = i - 1;

	for (int k = l; k < p; k++, j--)
		swap(a[k], a[j]);

	i = i + 1;

	for (int k = r - 1; k > q; k--, i++)
		swap(a[i], a[k]);
}

void quicksort(int a[], int l, int r)
{
	if (r <= l)
		return;

	int i, j;

	partition(a, l, r, i, j);
	quicksort(a, l, j);
	quicksort(a, i, r);
}

int main()
{
	int n;
	cin >> n;

	int ar[n];

	for (int i = 0; i < n; i++)
		cin >> ar[i];

	printf("Before Sorting: ");

	for (int i = 0; i < n; ++i)
		cout << ar[i] << " ";

	cout << "\n";

	quicksort(ar, 0, n - 1);

	printf("After Sorting: ");

	for (int i = 0; i < n; ++i)
		cout << ar[i] << " ";

	cout << "\n";

	return 0;
}

/*

Input:

7
10 90 49 2 1 5 23

Output

Before Sorting: 10 90 49 2 1 5 23
After Sorting: 1 2 5 10 23 49 90

*/