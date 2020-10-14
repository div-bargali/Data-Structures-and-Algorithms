//This is a detailed solution to provide intuition on solving CP problems based on finding the reduced max size of a given array whose elements are divisible by given number. (Elements of the array can be replaced by sum of elements present in the array).
//Have a look into at the question: https://codeforces.com/problemset/problem/1176/B

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t; // Input to run the program for 't' test cases
    while(t--){
        int n,f=0,r1=0,r2=0;
        cin>>n; // Input to know the total number of elements in the array
        vector<int>a; // array initialization (a vector can also be used as an array)
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            if(x%3==0)
            f++; // counting the number of elements which are divisible by 3
            if(x%3==1)
            r1++; // counting the number of elements which leave reminder 1 when divided by 3
            if(x%3==2)
            r2++; // counting the number of elements which leave reminder 2 when divided by 3
        }
        int ans=f;
        int m=min(r1,r2); // We can add-up the elements whose reminder is 1 with those whose reminder is 2 such that the newly formed number is divisible by 3
        ans+=m;
        m=(r1+r2-2*m)/3; // Consider r1 as a set and r2 as a set. The remaining elements of a particular set, the one which has max elements and are not pared with the other remainder set but can still yield a sum which is divisible by 3.
        ans+=m; 
        cout<<ans<<endl;
    }
    return 0;
}
