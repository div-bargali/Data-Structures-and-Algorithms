//Problem statement: Given a valid sentence without any spaces between the words and a dictionary of valid English words, find all possible ways to break the sentence in individual dictionary words.

//Input: A dictionary of words and the target word

//Output: Possible word breaks

/*Example:
Consider the following dictionary 
{ i, like, sam, sung, samsung, mobile, ice, 
  and, cream, icecream, man, go, mango}

Input: "ilikesamsungmobile"
Output: i like sam sung mobile
        i like samsung mobile
        */
        
/*SOLUTION APPROACH
- The crux of the solution involves splitting the input word at a given index and checking if that split is valid.
- For example, take the example word "ilikesamsungmobile". If we decide to split at index 0, the entire word "ilikesamsungmobile" must exist in the dictionary. But it doesnt. So let us move to the next index
  If we decide to split at index 1, "i" should be a combination of the dictionary words and "likesamsungmobile" should also be a combination. Only then will the entire word be broken. Now "i" is present in the dictionary. So we look at "likesamsungmobile". 
  Again if we recur for "likesamsungmobile": if we decide to split at index 0, "likesamsungmoble" must be present in the dictionary. If not, we move to the next index to see if "l"+"ikesamsungmobile" is possible. If that does not work as well, we check for "li"+"kesamsungmobile", and so on
- If we look again at the previous example, we can see some repetition. If we decide to split "ilikesamsungmobile" as "i"+"likesamsungmobile" and "likesamsungmobile"="l"+"ikesamsungmobile". Now for the next iteration, the input word will be "il" + "ikesamsungmobile". But "ikesamsungmobile" has already been encountered and we will be doing unnecessary calculation
  This is where we use DP to store the solution every time we break at a particular instance
- Hence, this problem is a beautiful combo of DP and backtracking
*/

#include <bits/stdc++.h>
using namespace std;

// Function to determine if string can be segmented into a space-separated
// sequence of one or more dictionary words
bool wordBreak(vector<string> const &dict, string str, vector<int> &lookup)
{
	// n stores length of current substring
	int n = str.size();

	// return true if we have reached the end of the string
	if (n == 0)
		return true;

	// if sub-problem is seen for the first time
	if (lookup[n] == -1)
	{
		// mark sub-problem as seen (0 initially assuming string
		// can't be segmented)
		lookup[n] = 0;

		for (int i = 1; i <= n; i++)
		{
			// consider all prefixes of current string
			string prefix = str.substr(0, i);

			// if prefix is found in dictionary, then recur for suffix
			if (find(dict.begin(), dict.end(), prefix) != dict.end() &&
				wordBreak(dict, str.substr(i), lookup))
			{
				// return true if the string can be segmented
				return lookup[n] = 1;
			}
		}
	}

	// return solution to current sub-problem
	return lookup[n];
}

// Word Break Problem
int main()
{
	// vector of strings to represent dictionary
	// we can also use trie or std::set to store dictionary
	vector<string> dict = { "this", "th", "is", "famous", "Word", "break",
			"b", "r", "e", "a", "k", "br", "bre", "brea", "ak", "problem" };

	// input string
	string str = "Wordbreakproblem";

	// look-up array to store solutions to sub-problems
	// lookup[i] stores if substring str[n-i..n) can be segmented or not
	vector<int> lookup(str.length() + 1, -1);

	if (wordBreak(dict, str, lookup))
		cout << "String can be segmented";
	else
		cout << "String can't be segmented";

	return 0;
}