//This code is contributed by @dalalvarun
// https://github.com/dalalvarun

#include <iostream>
#define MAX 40
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
 * Enter a postfix expression:2 3 1 * + 9 -
 * 
 * The evaluation is: -4
 */

int main()
{
    cout<<"Enter a postfix expression:";
    char input[MAX];
    gets(input);

    for(int i=0;i<MAX;i++)
    {
        if(input[i]=='\0')
            break;

        if(isdigit(input[i]))
        {
            int j = i+1;
            int X =0;
            while(isdigit(input[i]))
            {
                X = X*10 + (int)(input[i]-'0');
                i++;
            }
            i--;
            top = push(top,X);
        }
        if(input[i]=='+' || input[i]=='-' || input[i]=='*' || input[i]=='/')
        {
            int B = peek(top);
            top = pop(top);
            int A = peek(top);
            top = pop(top);
            int C;
            if(input[i]=='+')
                C = A+B;
            else if(input[i]=='-')
                C = A-B;
            else if(input[i]=='*')
                C = A*B;
            else if(input[i]=='/')
                C = A/B;
            top = push(top,C);
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
