
#include <iostream>

using namespace std;
int fibonacci(int n){
    if(n==0){
        return 0;
    }
    else if( n == 1){
        return 1;
    }
    else{
        return fibonacci(n-1) + fibonacci(n-2);
    }
}
int main()
{   
    //example
    cout << fibonacci(10) << endl;

    return 0;
}
