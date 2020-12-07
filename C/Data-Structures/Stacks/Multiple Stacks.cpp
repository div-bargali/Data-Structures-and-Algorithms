//This code is contributed by @dalalvarun
// https://github.com/dalalvarun
#include <iostream>
#define MAX 10
using namespace std;

int stack[MAX];
int topA = -1, topB = MAX;
int pushA(int);
int pushB(int);
int popA(int);
int popB(int);
int displayA(int);
int displayB(int);


int main()
{
    int option;
    do
    {
        cout<<"\n--------MAIN MENU--------";
        cout<<"\n 1.PUSH IN STACK A";
        cout<<"\n 2.PUSH IN STACK B";
        cout<<"\n 3.POP FROM STACK A";
        cout<<"\n 4.POP FROM STACK B";
        cout<<"\n 5.DISPLAY STACK A";
        cout<<"\n 6.DISPLAY STACK B";
        cout<<"\n 7.EXIT";
        cout<<"\nEnter your choice:";
        cin>>option;
        switch(option)
        {
            case 1:
                topA = pushA(topA);
                break;
            case 2:
                topB = pushB(topB);
                break;
            case 3:
                topA = popA(topA);
                break;
            case 4:
                topB = popB(topB);
                break;
            case 5:
                topA = displayA(topA);
                break;
            case 6:
                topB = displayB(topB);
                break;
        }
    }while(option!=7);
    return 0;
}

int pushA(int top)
{
    if(top==topB-1)
    {
        cout<<"\nOverflow!!!";
        return top;
    }
    else
    {
        cout<<"\nEnter the element to push:";
        int el;
        cin>>el;
        top++;
        stack[top] = el;
        cout<<"\nElement "<<el<<" pushed!!!";
        return top;
    }

}

int pushB(int top)
{
    if(top == topA+1)
    {
        cout<<"\nOverflow!!!";
        return top;
    }
    else
    {
        cout<<"\nEnter the element to be pushed:";
        int el;
        cin>>el;
        top--;
        stack[top] = el;
        cout<<"\nElement "<<el<<" pushed!!!";
        return top;
    }
}

int popA(int top)
{
    if(top == -1)
    {
        cout<<"\nUnderflow!!!";
        return top;
    }
    else
    {
        top--;
        cout<<"\nElement popped from stack A";
        return top;
    }
}

int popB(int top)
{
    if(top == MAX)
    {
        cout<<"\nUnderflow!!!";
        return top;
    }
    else
    {
        top++;
        cout<<"\nElement popped from stack B";
        return top;
    }
}

int displayA(int top)
{
    if(top==-1)
    {
        cout<<"\nStack A is empty";
        return top;
    }
    else
    {
        cout<<"\nThe stack A is as follows:\n";
        for(int i = top; i >= 0; i--)
            cout<<stack[i]<<" ";

        return top;
    }
}


int displayB(int top)
{
    if(top==MAX)
    {
        cout<<"\nStack B is empty";
        return top;
    }
    else
    {
        printf("\nThe stack B is as follows:\n");
        for(int i=top; i<=MAX-1; i++)
            cout<<stack[i]<<" ";
        return top;
    }
}
