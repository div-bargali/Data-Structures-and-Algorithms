//
// Stack using queues in C
//
// By Aron R, 6 Oct 2021
// To implement stack data structure usnig C

#include <stdio.h>
#include <stdlib.h>

int MAXSIZE = 8;
int stack[8];
int top = -1;

int isempty(void) {

   if(top == -1)
      return 1;
   else
      return 0;
}
   
int isfull(void) {

   if(top == MAXSIZE)
      return 1;
   else
      return 0;
}

int peek(void) {
   return stack[top];
}

int pop(void) {
   int data;
    
   if(!isempty()) {
      data = stack[top];
      top = top - 1;
      return data;
   } else {
      printf("Could not retrieve data, Stack is empty.\n");
       exit(0);
   }
}

void push(int data) {

   if(!isfull()) {
      top = top + 1;
      stack[top] = data;
   } else {
      printf("Could not insert data, Stack is full.\n");
   }
}

int main() {
    
    // Example implementation
   // push items on to the stack
   push(3);
   push(5);
   push(9);
   push(1);
   push(12);
   push(15);

   printf("Element at top of the stack: %d\n" ,peek());
   printf("Elements: \n");

  // print stack data
   while(!isempty()) {
      int data = pop();
      printf("%d\n",data);
   }

   printf("Stack full: %s\n" , isfull()?"true":"false");
   printf("Stack empty: %s\n" , isempty()?"true":"false");
   
   return 0;
}
 
