#include <iostream>
using namespace std;

// Function to find all Permutations of a given string str[i..n-1]
// containing all distinct characters and which u want to change

void permutations(string str, int i, int n)
{
    // base condition
    if (i == n - 1)
    {
        cout << str << endl;
        return;
    }

    // process each character of the remaining string
    for (int j = i; j < n; j++)
    {
        // swap character at index i with current character
        swap(str[i], str[j]);        // STL swap() used

        // recur for string [i+1, n-1]
        permutations(str, i + 1, n);

        // backtrack (restore the string to its original state)
        swap(str[i], str[j]);
    }
}

// Find all Permutations of a string
int main()
{
    string str = "ABC";

    permutations(str, 0, str.length());

    return 0;
}