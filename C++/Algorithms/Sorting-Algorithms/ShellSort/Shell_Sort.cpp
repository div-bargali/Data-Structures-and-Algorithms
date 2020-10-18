//array size
// 5
//array before shell sorting
// 3 5 8 4 2
//array after shell sorting
// 2 3 4 5 8

#include <iostream>

using namespace std;

int main()
{
    int size;
    cin >>size;
    
    // Create an array with given number of elements
    int x[size];

    // Take the array of numbers
    for (int n=0 ; n<size ;++n)
            cin>>x[n];

    int i=0,j=0,key;

    int increment=(size/2);
    
    // Shellsort implementation
    while (increment !=0)
    {
        i=increment;
        while(i<size)
            {
            key=x[i];
            j=i-increment;
            while (j>=0 && x[j]>key)
                {
                x[j+increment]=x[j];
                j=j-increment;
                }
            x[j+increment]=key;
            i++;
            }
        increment=increment/2;
    }
    for (int n=0 ; n<size ;++n)
        {
            cout<<x[n]<<" ";

        }
    cout<<endl;

    return 0;
}
