#include <iostream>
#include <string>
using namespace std;

class stack
{
    int top;
    int arr[5];

public:
    stack()
    {
        top = -1;
        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }
    }
    //check stack is empty or not
    bool isempty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }
    //check stack is full or not
    bool isfull()
    {
        if (top == 4)
            return true;
        else
            return false;
    }
    //push the element in stack
    void push(int val)
    {
        if (isfull())
        {
            cout << "stack overflow " << endl;
        }
        else
        {
            top++;
            arr[top] = val;
        }
    }
    //pop the element from stack
    int pop()
    {
        if (isempty())
        {
            cout << "stack underflow " << endl;
        }
        else
        {
            int popvalue = arr[top];
            arr[top] = 0;
            top--;
            return popvalue;
        }
        
    }
    //found element is present in which position in stack
    int peek(int pos)
    {
        if (isempty())
        {
            cout << "stack underflow " << endl;
            return 0;
        }
        else
        {
            return arr[pos];
        }
    }
    
    int count()
    {
        return (top + 1);
    }
    //change the value of element present in stack 
    void change(int pos, int val)
    {
        arr[pos] = val;
    }
    //display the element present in stack
    void display()
    {
        cout << "all value in the stack are " << endl;
        for (int i = 0; i < 4; i++)
        {
            cout << arr[i] << " ";
        }
        cout<<endl;
    }
};

int main()
{
    stack s1;
    int position, value, option;
    do
    {
        cout << "what operation do you perform ?select option number .enter 0 to exit " << endl;

        cout << "1. push()" << endl;
        cout << "2. pop()" << endl;
        cout << "3. peek()" << endl;
        cout << "4. isempty()" << endl;
        cout << "5. isfull()" << endl;
        cout << "6. count()" << endl;
        cout << "7. change()" << endl;
        cout << "8. display()" << endl;
        cout << "9. clear screen()" << endl;
        cin >> option;
        switch (option)
        {
            break;
        case 1:
            cout << "enter the value to push in stack " << endl;
            cin >> value;
            s1.push(value);
            break;
        case 2:
            cout << "pop function called ,poped value is " << s1.pop() << endl;
            break;
        case 3:
            cout << "enter position of item you want to peek " << endl;
            cin >> position;
            cout << "peek function is called , value at position " << position << " is " << s1.peek(position) << endl;
            break;
        case 4:
            if (s1.isempty())
                cout << "stack is empty " << endl;
            else
                cout << "stack is full " << endl;
            break;
        case 5:
            if (s1.isfull())
                cout << " stack is full " << endl;
            else
                cout << " stack is empty " << endl;
            break;
        case 6:
            cout << " count function is called , number if item in stack are " << s1.count() << endl;
            break;
        case 7:
            cout << "change function is called " << endl;
            cout << " enter the position of item you want to change " << endl;
            cin >> position;
            cout << endl;
            cout << "enter the value of item you want to change " << endl;
            cin >> value;
            s1.change(position, value);
            break;
        case 8:
            cout << "display function is called " << endl;
            s1.display();
            break;
        case 9:
            system("cls");
        default:
            cout << "enter proper option number " << endl;
            break;
        }
    } while (option != 0);

    return 0;
}
//contributor-satyam kumar
