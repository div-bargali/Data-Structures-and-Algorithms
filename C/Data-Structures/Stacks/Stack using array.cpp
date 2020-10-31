//This code is contributed by @dalalvarun
// https://github.com/dalalvarun

#include <iostream>
#define MAX 10
using namespace std;

int stack[MAX], top=-1;

int push(int top)
{
    if(top==MAX-1)
    {
        cout<<"\nOverflow!!!";
        return top;
    }
    else
    {
        top++;
        cout<<"\nEnter the element to be pushed:";
        int el;
        cin>>el;
        stack[top] = el;
        cout<<"\nElement pushed successfully!!!";
        return top;
    }
}

int pop(int top)
{
    if(top==-1)
    {
        cout<<"\nUnderflow!!!";
        return top;
    }
    else
    {
        top--;
        cout<<"\nElement popped!!!";
        return top;
    }
}

int peek(int top)
{
    if(top==-1)
        cout<<"\nThe stack is empty!!!";
    else
        cout<<"Peek: "<<stack[top];
    return top;
}
int display(int top)
{
    if(top==-1)
        cout<<"\nThe stack is empty!!!";
    else
    {
        cout<<"\nThe stack is as follows:";
        for(int i=top;i>=0;i--)
        {
            cout<<"-->"<<stack[i];
        }
    }
    return top;
}


int main()
{
    int option;
    do
    {
        cout<<"\n ------------MAIN MENU------------";
        cout<<"\n 1. PUSH";
        cout<<"\n 2. POP";
        cout<<"\n 3. PEEK";
        cout<<"\n 4. DISPLAY";
        cout<<"\n 5. EXIT";
        cout<<"\n\nEnter your choice:";
        cin>>option;
        switch(option)
        {
            case 1:
                top = push(top);
                break;
            case 2:
                top = pop(top);
                break;
            case 3:
                top = peek(top);
                break;
            case 4:
                top = display(top);
                break;
        }
    }
    while(option!=5);
    return 0;
}