#include <bits/stdc++.h> 
using namespace std; 
  
stack<int> sort_stack(stack<int> &input) 
{ 
    stack<int> tmpStack; 
  
    while (!input.empty()) 
    { 
        // pop out the first element 
        int tmp = input.top(); 
        input.pop(); 
  
        // while temporary stack is not empty and top 
        // of stack is greater than temp 
        while (!tmpStack.empty() && tmpStack.top() > tmp) 
        { 
            // pop from temporary stack and push 
            // it to the input stack 
            input.push(tmpStack.top()); 
            tmpStack.pop(); 
        } 
  
        // push temp in tempory of stack 
        tmpStack.push(tmp); 
    } 
  
    return tmpStack; 
} 
  
// main function 
int main() 
{ 
    int n,t;
    cin>>n;
    stack<int> input; 
    for(i=0;i<n;i++)
    {
      cin>>t;
      input.push(t);
    }
  
    stack<int> tmpStack = sort_stack(input); 
  
    while (!tmpStack.empty()) 
    { 
        cout << tmpStack.top()<< " "; 
        tmpStack.pop(); 
    } 
} 
