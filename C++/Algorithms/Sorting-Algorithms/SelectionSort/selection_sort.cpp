
//Time Complexity: O(n2) as there are two nested loops.

//Auxiliary Space: O(1)
//The good thing about selection sort is it never makes more than O(n) swaps and can be useful when memory write is a costly operation.


#include <iostream>
using namespace std;
int main()
{
    long long int n,i,j,pos,t;
    cin>>n; // array's size
    long long int a[n];
    for(i=0;i<n;i++) cin>>a[i]; // write input
    for(i=0;i<n-1;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[pos]) pos=j; // Find the starting element of an array
        }
        t=a[pos]; // swap
        a[pos]=a[i];
        a[i]=t;
    }
    for(i=0;i<n;i++) cout<<a[i]<<' '; // print output 
    return 0;
}
