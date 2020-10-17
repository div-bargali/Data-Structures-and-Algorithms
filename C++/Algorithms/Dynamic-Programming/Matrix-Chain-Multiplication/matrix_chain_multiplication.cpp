// MATRIX CHAIN MULTIPLICATION
// Reducing the no. of operation to multiply n-1 matrices using dynamic programming
// No. of operations(multiplications) depends on the order in which the different matrices are multiplied
// TC to multiply two matrices (i,k) and (k,j) = i*k*j - O(n^3)
#include <bits/stdc++.h>
using namespace std;

int dp[100][100];

// Bottom Up DP
int matrix_chain_BU(int *m, int n) {
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		int r = 1, c = i;
		while (c <= n) {
			int ans = (r == c ) ? 0 : INT_MAX;
			for (int k = r; k < c; k++) {
				int prob = dp[r][k] + dp[k + 1][c] + (m[r - 1] * m[k] * m[c]);
				ans = min(ans, prob);
			}
			dp[r][c] = ans;
			r++; c++;
		}
	}
	return dp[1][n];
}

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int main() {
	init();
	int matrices[] = {4, 2, 3, 1, 3};  // 4 matrices of size 4*2,2*3,3*1,1*3
	int n = sizeof(matrices) / sizeof(int);
	memset(dp, -1, sizeof(dp));

	// cout << matrix_chain(matrices, 1, n - 1) << endl;
	cout << matrix_chain_BU(matrices, n - 1) << endl;

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
