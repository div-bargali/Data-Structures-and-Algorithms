// IMPLEMENTATION OF QUEUE USING STACKS

#include <stdio.h>
#include <stdlib.h>

#define N 100

//function declarations

//for stack operations 

void push1(int);	
void push2(int);
int pop1();
int pop2();

//Queue operations

void enqueue(); // To add element in tha Queue
void dequeue(); // Remove one element from Queue
void display(); // Print complete Queue
void create();

int S1[N], S2[N];// Declaration of stacks using array of N units
int top1 = -1, top2 = -1;
int count = 0;

void main(){
	int val;
	int choice; 
	printf("\nQUEUE USING STACKS IMPLEMENTATION\n\n");
	printf("\n1.ENQUEUE");
	printf("\n2.DEQUEUE");
	printf("\n3.DISPLAY");
	printf("\n4.EXIT");
	printf("\n");
	create();
	while (1)
	{
		printf("\nEnter your choice : ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			enqueue();
			break;
		case 2:
			dequeue();
			break;
		case 3:
			display();
			break;
		case 4:
			exit(0);
		default:
    	    printf("\nInvalid Choice\n");
        }
    }
}

void create()
{
	top1 = top2 = -1;
}

void push1(int data){
	if(top1 == N-1)
	{
		printf("Queue Overflow\n");
	}
	else
	{
		top1++;
		S1[top1] = data;
	}
}

void push2(int data)
{
	if(top2 == N-1)
	{
		printf("Queue Overflow\n");
	}
	else
	{
		top2++;
		S1[top2] = data;
	}
}

int pop1()
{
	return S1[top1--];
}

int pop2()
{
	return S2[top2--];
}

void enqueue()
{
    int data;

    printf("Enter data into queue: ");
    scanf("%d", &data);
	push1(data);
	count++;
}

void dequeue(){
	if (top1 == -1 && top2 == -1)
	{
		printf("Queue is EMPTY\n");
	}
	else
	{
		for(int i = 0; i <= count; i++)
		{
			push2(pop1());
		}
		pop2();
		count--;
		for(int i = 0; i <= count; i++){
			push1(pop2());
		}
	}
}


void display()
{
    int i;
    if (top1 == -1 && top2 == -1)
    {
		printf("Queue is EMPTY\n");
	}
	else
	{
		printf("Elements in the Queue are : ");
		for (i = 0;i <= top1;i++)
	    {
    	    printf(" %d ", S1[i]);
    	}
	}
}	