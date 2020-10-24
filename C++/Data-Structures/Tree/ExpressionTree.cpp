/*
Given a postfix expression.Your task is to complete the method constructTree().The output of the program will print the infix expression of the given postfix expression.

Approach Used -  Create a stack and as you will be  traversing the postfix expression , if the expression contains operand , create a node and insert it into tree.
Else if it's an operator , pop the stack and make left and right child nodes of tree. 
*/

#include<bits/stdc++.h>
using namespace std;

struct et
{
	char value;
	et* left, *right;
	
	et(char x){
	    value = x;
	    left = right = NULL;
	}
};

bool isOperator(char c)
{
	if (c == '+' || c == '-' ||	c == '*' || c == '/' ||	c == '^')
	      	return true;
	return false;
}

void inorder(et *t)
{
	if(t)
	{
		inorder(t->left);
		printf("%c ", t->value);
		inorder(t->right);
	}
}

et* constructTree(char postfix[])
{
 stack<et*> st;
    et *t, *t1, *t2;
 
    for (int i=0; i<strlen(postfix); i++)
    {
        // If operand, simply push into stack
        if (!isOperator(postfix[i]))
        {
            t = new  et(postfix[i]);
            st.push(t);
        }
        else // operator
        {
            t = new  et(postfix[i]);
 
            // Pop two top nodes
            t1 = st.top(); // Store top
            st.pop();      // Remove top
            t2 = st.top();
            st.pop();
 
            //  make them children
            t->right = t1;
            t->left = t2;
 
            // Add this subexpression to stack
            st.push(t);
        }
    }
 
    //  only element will be root of expression
    // tree
    t = st.top();
    st.pop();
 
    return t;
}


int main()
{   
    int t;
    cin>>t;
    while(t--){
    char postfix[25];
	cin>>postfix;
	et* r = constructTree(postfix);
	inorder(r);
	cout<<endl;
}
return 0;
}





