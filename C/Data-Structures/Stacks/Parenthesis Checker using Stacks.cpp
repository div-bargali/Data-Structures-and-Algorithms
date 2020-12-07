//This code is contributed by @dalalvarun
// https://github.com/dalalvarun

#include <iostream>
#define MAX 30
using namespace std;

struct call_stack
{
    char bracket;
    struct call_stack *next;
};

struct call_stack *top = nullptr;
struct call_stack *push(char x);
struct call_stack *pop();
char peek();
int main()
{
    cout<<"\nEnter an expression:";
    char exp[MAX];
    gets(exp);
    for(int i=0; i<MAX;i++)
    {
        if(exp[i]=='(' || exp[i]=='[' || exp[i] == '{')
        {
            push(exp[i]);
            continue;
        }
        else if(exp[i]==')' || exp[i]==']' || exp[i] == '}')
        {
            if((peek()=='(' && exp[i]==')') || (peek()=='[' && exp[i]==']') || (peek()=='{' && exp[i]=='}'))
                top = pop();
            else
            {
                printf("\nInvalid Expression!!!");
                return 0;
            }
        }
    }
    if(peek()=='$')
        printf("\nValid Expression!!!");
    else
        printf("\nInvalid Expression!!!");
    return 0;
}

struct call_stack *push(char ip)
{
    auto new_el = new call_stack;
    new_el->bracket = ip;
    if(top==nullptr)
    {
        top = new_el;
        new_el->next = nullptr;
    }
    else
    {
        new_el->next = top;
        top = new_el;
    }
    return top;

}

struct call_stack *pop()
{
    struct call_stack *ptr = top;
    top = top->next;
    delete ptr;
    return top;

}

char peek()
{
    if(top==nullptr)
        return '$';
    return top->bracket;
}
