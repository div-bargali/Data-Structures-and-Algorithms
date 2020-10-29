/*Recursive approach for issue #790 Adding Factorial Equation | C++*/
#include <iostream>

using namespace std;
//Recursive function to calculate factorial of the number
int fact(int num)
{
    if(num<0)           //Because factorial of negative numbers do not exist
        return -1;
    else if(num==0||num==1)     //0!=1 and 1!=1 (Base Case)
        return 1;
    else
    {
        return num*fact(num-1);     //Recursive call
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
