//Check if the brackets are balanced using using stack.
// Testcase:
// Input 1: ([{}])
// Output: true

// Input 2: (){[])
// Output: false

#include <iostream>
#include <string>
#include<stack>
using namespace std;

bool isBalanced(string exp) {
	// Write your code here

    stack<char> s;
    
    int i=0;
    while(exp[i]!='\0'){
        
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
            s.push(exp[i]);
        
        else if(exp[i]==')'){
            if(s.size()==0 || s.top()!='(')
                return false;
            s.pop();
        }
        
        else if(exp[i]==']'){
            if(s.size()==0 || s.top()!='[')
                return false;
            s.pop();
        }
        
        else if(exp[i]=='}'){
            if(s.size()==0 || s.top()!='{')
                return false;
            s.pop();
        }
        
        i++;
    }
    
    return true;
    
}

int main() 
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}
