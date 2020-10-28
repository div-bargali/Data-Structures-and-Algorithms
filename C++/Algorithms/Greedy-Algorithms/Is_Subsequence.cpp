/*    Problem Statement
Given a string s and a string t, check if s is subsequence of t.
A subsequence of a string is a new string which is formed from the original string by deleting some(can be none) of the characters without disturbing the relative positions of the remaining characters. 
(ie, "ace" is a subsequence of "abcde" while "aec" is not).
*/
#include<bits/stdc++.h>
using namespace std;
bool isSubsequence(string s, string t) {
    int i, j = 0;
    if (s.length() == 0)          // empty string is always a subsequence
        return true;
    char c = s[0];                //c stores first character of s
    if (t.length() < s.length())    // a string s containing less characters than t cannot be its subsequence
        return false;
    for (i = 0; i < t.length(); i++)
    {
        if (t[i] == c)
        {
            j++;                     //it moves the iterator to the next character of s
            if (j == s.length())     //if the iterator has reached the limit of s , it means it is present as subsequence
                return true;
            c = s[j];
        }
    }
    return false;                //if the conditions are not satisified above, then s is not a subsequence of t
}
int main()
{
    string s, t;
    cin >> s >> t;
    cout << boolalpha;    //to display true for 1 and false for 0
    cout << isSubsequence(s, t);
    return 0;
}