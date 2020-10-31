//This code is contributed by @dalalvarun
// https://github.com/dalalvarun

#include <iostream>
#include <algorithm>
using namespace std;
struct stack
{
    char data;
    struct stack *next;
};

struct stack *top = nullptr;
string infixToPostfix(string);
struct stack *push(struct stack *,char);
struct stack *pop(struct stack *);
char peek(struct stack *);
int getPriority(char);
/*
 * Sample Output
 * Enter the infix expression:(A-B/C)*(A/K-L)
 * The Prefix expression is: * - A / B C - / A K L
 * A B + C D E / * - F +
 */
int main()
{
    string input;
    cout<<"\nEnter the infix expression:";
    getline(cin,input);
    reverse(input.begin(),input.end());
    int len = input.length();
    for(int i=0;i<len;i++)
    {
        if(input[i]=='(')
            input[i]=')';
        else if(input[i]==')')
            input[i]='(';
    }
    string output = infixToPostfix(input);
    reverse(output.begin(),output.end());
    cout<<"The Prefix expression is:"<<output;
}
string infixToPostfix(string input)
{
    string output;
    int len = input.length();
    for(int i=0;i<len;i++)
    {
        if(isdigit(input[i])|| isalpha(input[i]))
        {
            output.push_back(input[i]);
            output.push_back(' ');
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
                            output.push_back(temp);
                            output.push_back(' ');
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
                output.push_back(temp);
                output.push_back(' ');
                top = pop(top);
            }
            top = pop(top);
        }

    }
    while(top)
    {
        char temp = peek(top);
        output.push_back(temp);
        output.push_back(' ');
        top = pop(top);
    }
    return output;
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
