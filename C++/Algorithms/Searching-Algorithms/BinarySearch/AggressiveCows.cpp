/*  C++ program to implement Aggressive Cows
    using Binary Search

    Problem: https://www.spoj.com/problems/AGGRCOW/

    Algorithm:  We will guess the answer by using binary search approach.

                if guess is valid:
                    try to maximise distance
                    i.e look for larger guess(optimise the answer)
                else:
                    look for smaller guess

    Time Complexity:
        Guessing 'and' then checking whether guess is valid or not
        
        Guessing: O(logn)
        Checking: O(n)

        T(n) = O(nlogn)

*/

#include <bits/stdc++.h>
using namespace std;

/*
    Check! If mid is the minimum distance between cows,
    can we place all the 'c' cows into the stalls
*/
bool isValid(const vector<int> &a, int c, int mid)
{
    int current_cow = 0; // location of current cow
    int cnt = 1;         // number of cows which are placed

    int next_cow; // location of next cow

    // Searching for next cow's location
    for (next_cow = 1; next_cow < a.size(); next_cow++)
    {
        if (a[next_cow] - a[current_cow] >= mid)
        {
            cnt++;
            current_cow = next_cow;
        }
    }

    if (cnt < c)
        return false;

    return true;
}

int main()
{

    int n = 5; // number of stalls
    int c = 3; // number of cows

    vector<int> a{1, 2, 8, 4, 9}; // stall locations

    sort(a.begin(), a.end());

    int start = 1;             // worst possible answer
    int end = a[n - 1] - a[0]; // best possible answer
    int res = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2; // guess the answer

        // check if guess is correct
        if (isValid(a, c, mid))
        {
            res = mid;       // store the guess
            start = mid + 1; // look for better answer
        }
        else
        {
            end = mid - 1;
        }
    }

    cout << res << '\n';

    return 0;
}
