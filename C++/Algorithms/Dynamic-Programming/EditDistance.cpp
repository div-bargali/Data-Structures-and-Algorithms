/*
The edit distance between two strings is the minimum number of operations required to transform one string into the other.

The allowed operations are:
Add one character to the string.
Remove one character from the string.
Replace one character in the string.
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;
	int n = a.size(), m = b.size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i == 0)
				dp[i][j] = j;
			else if (j == 0)
				dp[i][j] = i;
            //if both the characters are equal
			else if (a[i - 1] == b[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
            //if both characters are different
			else {
				dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
			}
		}
	}
	cout << dp[n][m] << endl;
}


