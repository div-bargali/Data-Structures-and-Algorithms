// Implement a stack using singly linked list 
#include <bits/stdc++.h> 
using namespace std; 

struct Node                            //create class
{ 
   int data; 
   struct Node* link; 
}; 

struct Node* top; 

void push(int data)                      //insert function
{ 
   struct Node* temp; 
   temp = new Node(); 
   if (!temp) 
   { 
      cout << "\nHeap Overflow"; 
      exit(1); 
   } 

   temp->data = data; 
   temp->link = top; 
   top = temp; 
} 

int isEmpty()                            //get empty or not of stack
{ 
   return top == NULL; 
} 

int peek()                               //get first data
{ 
   
   if (!isEmpty()) 
      return top->data; 
   else
      exit(1); 
} 

void pop()                               //delete function
{ 
   struct Node* temp; 

   if (top == NULL) 
   { 
      cout << "\nStack Underflow" << endl; 
      exit(1); 
   } 
   else
   { 
      temp = top; 
      top = top->link; 
      temp->link = NULL; 
      free(temp); 
   } 
} 

void display()                            //print function
{ 
   struct Node* temp; 
   if (top == NULL) 
   { 
      cout << "\nStack Underflow"; 
      exit(1); 
   } 
   else
   { 
      temp = top; 
      while (temp->link!= NULL) 
      { 
         cout << temp->data << "-> "; 
         temp = temp->link; 
      } 
        cout<<temp->data;
   } 
} 

int main()                               //driver
{ 
   push(11); 
   push(22); 
   push(33); 
   push(44); 
   display(); 
   cout << "\nTop element is "<< peek() << endl; 
   pop(); 
   pop(); 
   display(); 
   cout << "\nTop element is "<< peek() << endl; 
   return 0; 
} 
