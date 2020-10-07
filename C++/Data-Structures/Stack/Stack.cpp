#include <bits/stdc++.h>   //we are using cp header
using namespace std; 
  
void showstack(stack <int> s)  //function for stack
{ 
    while (!s.empty()) 
    { 
        cout << '\t' << s.top(); 
        s.pop(); 
    } 
    cout << '\n'; 
} 
  
int main () 
{ 
    stack <int> s;    // declaring stack
    s.push(10);                   //pushing elements
    s.push(30); 
    s.push(20); 
    s.push(5); 
    s.push(1); 
  
    cout << "The stack is : "; 
    showstack(s);                   //calling our stack function
  
    cout << "\ns.size() : " << s.size(); 
    cout << "\ns.top() : " << s.top(); 
  
  
    cout << "\ns.pop() : "; 
    s.pop(); 
    showstack(s); 
  
    return 0; 
} 


/*
Output:
The stack is :     1    5    20    30    10

s.size() : 5
s.top() : 1
s.pop() :     5    20    30    10  
*/
