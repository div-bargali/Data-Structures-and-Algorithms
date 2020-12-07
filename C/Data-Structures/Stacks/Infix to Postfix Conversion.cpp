//This code is contributed by @dalalvarun
// https://github.com/dalalvarun

#include <iostream>
using namespace std;
struct stack
{
    char data;
    struct stack *next;
};

struct stack *top = nullptr;
struct stack *push(struct stack *,char);
struct stack *pop(struct stack *);
char peek(struct stack *);
int getPriority(char);
/*
 * Sample Output
 * Enter infix expression:( ( A + B ) — C * ( D / E ) ) + F
 * 
 * The postfix expression is:
 * A B + C D E / * - F +
 */
int main()
{
    string input;
    cout<<"\nEnter infix expression:";
    getline(cin,input);
    cout<<"\nThe postfix expression is: \n";
    for(int i=0;i<input.length();i++)
    {
        if(isdigit(input[i])|| isalpha(input[i]))
        {
            cout<<input[i]<<" ";
        }
        if(input[i]=='(')
            top = push(top,input[i]);
        if(input[i]=='+' || input[i]=='-' || input[i]=='*' || input[i]=='/' || input[i]=='%'|| input[i]=='^')
        {
            if(peek(top)!='$')
            {
                if(peek(top)=='(')
                {
                    top = push(top,input[i]);
                }
                else if(getPriority(input[i])>getPriority(peek(top)))
                {
                    top = push(top,input[i]);
                }
                else if(getPriority(input[i])<=getPriority(peek(top)))
                {
                    while(1)
                    {
                        char temp = peek(top);
                        if(getPriority(temp)< getPriority(input[i]) || temp=='('|| peek(top)=='$')
                        {
                            top = push(top,input[i]);
                            break;
                        }
                        else
                        {
                            cout<<temp<<" ";
                            top = pop(top);
                        }
                    }


                }
            }
            else
            {
                top = push(top,input[i]);
            }
        }
        if(input[i]==')')
        {

            while(peek(top)!='(')
            {
                char temp = peek(top);
                cout<<temp<<" ";
                top = pop(top);
            }
            top = pop(top);
        }

    }
    while(top)
    {
        char temp = peek(top);
        cout<<temp<<" ";
        top = pop(top);
    }
    return 0;


}

struct stack *push(struct stack *top, char val)
{
    auto ptr = new stack;
    ptr->data = val;
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
        return nullptr;
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

char peek(struct stack *top)
{
    if(top==nullptr)
        return '$';
    return top->data;
}

int getPriority(char x)
{
    if(x=='^')
        return 4;
    else if(x=='*' || x=='/')
        return 3;
    else if(x=='%')
        return 2;
    else if(x=='+'|| x=='-')
        return 1;
    else if(x=='(')
        return 0;
    else
        return -1;
}
