#include <iostream>

using namespace std;

int main()
{
    int size;
    cin >>size;

    int x[size];

    for (int n=0 ; n<size ;++n)
            cin>>x[n];

    int i=0,j=0,key;

    int increment=(size/2);

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