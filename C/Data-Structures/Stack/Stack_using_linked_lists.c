//     ###  IMPLEMENTATION OF STACK USING LINKED LISTS  ###

#include<stdio.h>
#include <stdlib.h>

struct stack
{
	int data;
	struct stack* next;
	
}stack;

struct stack* push(struct stack* top, int data)// Add element to the stack
{
	struct stack* temp = (struct stack*)malloc(sizeof(stack));
	

	temp->data = data;
	if(top == NULL)
	{
		temp->next = NULL;
		printf("Added element is : %d\n",temp->data );
		return temp;
	}
	temp->next = top;
	top = temp;
	printf("Added element is : %d\n",top->data );
	
	return top;
}

struct stack* pop(struct stack* top)
{
	if(top == NULL){
		printf("Stack is empty\n");
		return NULL;
	}
	struct stack* temp = (struct stack*)malloc(sizeof(stack));
	temp = top;
	printf("Deleted element is : %d\n",temp->data );
	free(temp);
	if(top->next == NULL)
		return NULL;
	top = top->next;
	return top;
}

void display(struct stack* top) //To display all data
{	
	if(top == NULL){
		printf("Stack is empty\n");
		return;
	}

	printf("Stack is : [ ");

	while(top!=NULL)
	{
		printf("%d ",top->data );
		top = top->next;
	}
	printf("]");
}

void peek(struct stack* top)	//To print the top element
{
	if(top == NULL){
		printf("Stack is empty\n");
		return;
	}
	printf("The top element of stack is : %d\n",top->data);
}


int main()
{
	struct stack* s = (struct stack*)malloc(sizeof(stack)) ;
	s = NULL;
	int choice,data;
	printf("###		IMPLEMENTATION OF STACKS USING LINKED LISTS		###\n");
	printf("1.Push \n2.Pop \n3.Peek top element \n4.Display complete stack \n5.Exit \n");

	do
	{
		printf("Enter your choice: ");
		scanf("%d",&choice);

		switch(choice )
		{
			case 1 : printf("Enter element to be pushed : ");
					 scanf("%d",&data);
					 s = push(s,data);
					 break;

			case 2 : s = pop(s);
					 break;

			case 3 : peek(s);
					 break;

			case 4 : display(s);
					 break;

			case 5 : printf("\nExit\n");
					 break;

			default : printf("\nINVALID CHOICE\n");
	                  break;

		}
	}
	while(choice != 5);
		return 0;


}