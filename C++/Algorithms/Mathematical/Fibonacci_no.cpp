//Space optimized method to find the nth fibonacci number
#include<iostream>
using namespace std; 
  
int fib(int n) 
{ 
	
	int a = 0, b = 1, c, i; 
    if( n == 0) 
        return a; 
    for(i = 2; i <= n; i++) 
    { 
       c = a + b; 
       a = b; 
       b = c; 
    } 
    return b; 
   
} 

  
// Driver code 
int main() 
{ 
    int n;
    int a = 0, b = 1, c, i;
    cout << "Enter the number : ";
    cin >> n;
    cout << "The last fibonacci number is : " << fib(n); 
    return 0; 
} 
