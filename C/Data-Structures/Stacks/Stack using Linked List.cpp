//This code is contributed by @dalalvarun
// https://github.com/dalalvarun

//Stack using Linked Lists
//A Stack is a data structure in which the data-items are inserted or removed using Last In First Out (LIFO) principle.

#include <bits/stdc++.h>
using namespace std;
class stackNode
{
    public:
        int data;
        stackNode *next;
};

class Stack
{
    private:
        stackNode *root;
    public:
        Stack()
        {
            root = nullptr;
        }
        void push();
        void display();
        void pop();
        void peek();
};

void Stack::push()
{
    int val;
    cout<<"\nEnter the element to be entered:";
    cin>>val;
    auto *node = new stackNode;
    node->data = val;
    if(root==nullptr)
    {
        node->next = nullptr;
        root = node;
    }
    else
    {
        node->next = root;
        root = node;
    }
}

void Stack::display()
{
    if(root==nullptr)
    {
        cout<<"\nThe Stack is empty!!!";
        return;
    }
    else
    {
        cout<<"\nThe Stack is as follows:\n";
        stackNode *iterator = root;
        while(iterator!=nullptr)
        {
            cout<<"->"<<iterator->data;
            iterator = iterator->next;
        }
    }
}

void Stack::pop()
{
    if(root==nullptr)
    {
        cout<<"\nUnderflow!!!";
        return;
    }
    else
    {
        stackNode *iterator = root;
        if(iterator->next == nullptr)
            root = nullptr;
        else
            root = root->next;
        delete iterator;
    }
    cout<<"\nElement Popped successfully!!!";
}

void Stack::peek()
{
    if(root == nullptr)
    {
        cout<<"\nThe Stack is empty!!!";
        return;
    }
    else
    {
        cout<<"Peek:"<<root->data;
        return;
    }
}

int main()
{
    Stack S;
    int decision;
    do
    {
        cout<<"\n------------Menu------------";
        cout<<"\n1.Push element";
        cout<<"\n2.Pop element";
        cout<<"\n3.Peek";
        cout<<"\n4.Display Stack";
        cout<<"\n5.Exit";
        cout<<"\nEnter your choice:";
        cin>>decision;
        switch (decision)
        {
            case 1:
                S.push();
                break;
            case 2:
                S.pop();
                break;
            case 3:
                S.peek();
                break;
            case 4:
                S.display();
                break;
        }
    }
    while(decision!=5);
    return 0;
}
