/*Calculating factorial of a number in an iterative way. Issue no-790*/
#include <iostream>

using namespace std;

//function to calculate factorial
int fact(int num)
{
    int i, fact=1;
    if(num<0)               //factorial cannot be calculated for negative numbers
        return -1;
    else if(num==0||num==1) //0!=1 and 1!=1
        return 1;
    else
    {
        for(i=2;i<=num;i++)
        {
            fact=fact*i;
        }
        return fact;
    }
}

int main()
{
    int n, factorial;
    cout<<"\nEnter a number for which factorial is to be computed: ";
    cin>>n;
    factorial=fact(n);
    if(factorial==-1)
    {
        cout<<"\nFactorial for negative numbers cannot be computed\n";
    }
    else{
            cout<<"\nFactorial of "<<n<<"="<<factorial<<endl;
    }
    return 0;
}
