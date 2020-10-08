// Circular Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*Head;

void create(int A[],int n) // To Create List
{
	int i;
	struct Node *t,*last;
	Head=(struct Node*)malloc(sizeof(struct Node));
	Head->data=A[0];
	Head->next=Head;
	last=Head;
	for(i=1;i<n;i++)
	{
		t=(struct Node*)malloc(sizeof(struct Node));
		t->data=A[i];
		t->next=last->next;
		last->next=t;
		last=t;
	}
}
void Display(struct Node *h) //Print All Data
	{
		do
		{
			printf("%d ",h->data);
			h=h->next;
		}
		while(h!=Head);
		printf("\n");
	}

int Length(struct Node *p) //Gives Length Of List
{
	int len=0;
	do
	{
		len++;
		p=p->next;
	}
	while(p!=Head);
	return len;
}
void Insert(struct Node *p,int index, int x) //Insert New Element At Desired Index
{
	struct Node *t;
	int i;
	if(index<0 || index > Length(p)){
		printf("Can't Insert, Invalid Index\n");
		return;
	}
	if(index==0)
	{
		t=(struct Node *)malloc(sizeof(struct Node));
		t->data=x;
		if(Head==NULL)
		{	
			Head=t;
			Head->next=Head;
		}
		else
		{
			while(p->next!=Head)p=p->next;
			p->next=t;
			t->next=Head;
			Head=t;
		}
	}
	else
	{
		for(i=0;i<index-1;i++)p=p->next;
		t=(struct Node *)malloc(sizeof(struct Node));
		t->data=x;
		t->next=p->next;
		p->next=t;
	}
}
int Delete(struct Node *p,int index) // Delete Element Of Desired Position (Index)
{
	struct Node *q;
	int i,x;
	if(index <0 || index >Length(Head)){
		printf("Can't Delete, Invalid Index\n");
		return -1;
	}
	if(index==1)
	{
		while(p->next!=Head)
			p=p->next;
		x=Head->data;
		if(Head==p)
		{
			free(Head);
			Head=NULL;
		}
		else
		{
			p->next=Head->next;
			free(Head);
			Head=p->next;
		}
	}
	else
	{
	for(i=0;i<index-2;i++)
		p=p->next;
	q=p->next;
	p->next=q->next;
	x=q->data;
	free(q);
	}
	return x;
}
int main()
{
	int A[]={1,2,3,4,5,6}; 	//Initializing With Declaration
	int n = 6;				//Length Of List

	create(A,n);			//Create List
	Display(Head);		//OUTPUT 1 2 3 4 5 6 

	Delete(Head,1);		//OUTPUT 0 2 3 4 5 6 

	Insert(Head,0,9);	//A = {9, 2, 3, 4, 5, 6} 
	Insert(Head,1,8);	//A = {9, 8, 2, 3, 4, 5, 6} 
	Insert(Head,2,7);	//A = {9, 8, 7, 2, 3, 4, 5, 6} 
	Insert(Head,3,0);	//A = {9, 8, 7, 0, 2, 3, 4, 5, 6} 

	Delete(Head,11);	//OUTPUT "Can't Delete, Invalid Index"

	Display(Head);		//OUTPUT 9 8 7 0 2 3 4 5 6 
	return 0;
}