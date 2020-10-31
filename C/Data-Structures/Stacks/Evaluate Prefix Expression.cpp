//This code is contributed by @dalalvarun
// https://github.com/dalalvarun

#include <iostream>
#include <algorithm>
using namespace std;

struct stack
{
    int data;
    struct stack *next;
};

struct stack *top = nullptr;
struct stack *push(struct stack *, int);
struct stack *pop(struct stack *);
int peek(struct stack *);

/*
 * Trial Output
 * Enter the prefix expression:+ - 9 2 7
 *
 * The evaluation is: 14
 */

int main()
{
    cout<<"\nEnter the prefix expression:";
    string input;
    getline(cin,input);
    reverse(input.begin(),input.end());
    for(int i=0;i<input.length();i++)
    {
        if(input[i]==' ')
            continue;
        if(isdigit(input[i]))
            top = push(top,(input[i]-'0'));

        if(input[i]=='+' || input[i]=='-' || input[i]=='/' || input[i]=='*')
        {
            int op1 = peek(top);
            top = pop(top);
            int op2 = peek(top);
            top = pop(top);
            switch (input[i])
            {
                case '+':
                    top = push(top, op1 + op2);
                    break;
                case '-':
                    top = push(top,op1-op2);
                    break;
                case '*':
                    top = push(top,op1*op2);
                    break;
                case '/' :
                    top = push(top,op1/op2);
                    break;
            }
        }
    }
    cout<<"\nThe evaluation is: "<<peek(top);
    return 0;
}

struct stack *push(struct stack *top, int x)
{
    auto ptr = new stack;
    ptr->data = x;
    if(top==nullptr)
    {
        top = ptr;
        ptr->next = nullptr;
    }
    else
    {
        ptr->next = top;
        top = ptr;
    }
    return top;
}

struct stack *pop(struct stack *top)
{
    if(top==nullptr)
    {
        return top;
    }
    else if(top->next == nullptr)
    {
        struct stack *ptr = top;
        delete ptr;
        top = nullptr;
        return top;
    }
    else
    {
        struct stack *ptr = top;
        top = top->next;
        delete ptr;
        return top;
    }
}
int peek(struct stack *top)
{
    if(top==nullptr)
        return -1;
    return top->data;
}
