//Implementing the Linked list
#include<stdio.h>
#include<malloc.h>
struct node
{
	int info;
	struct node *link;
}*start;
void create_list(int data);
void addatbeg(int data);
void addafter(int data,int pos);
void display();
void search(int data);
void del(int m);
void main()
{
	int m,n,i,choice,position,searchitem;
	start=NULL;
	while(1)
	{
		printf("\n1.Create list\n2.Add at beginning\n3.Add after a given position\n4.Display\n5.Search an item\n6.Deletion of a node in a singly linked list\nEnter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\nHow many number of node you want in a linked list : ");
				scanf("%d",&n);
				for(i=0;i<n;i++)
				{
					printf("\nEnter the element ");
					scanf("%d",&m);
					create_list(m);
				}
				break;
			case 2:
				printf("\n Enter element you want to add at the beginning ");
				scanf("%d",&m);
				addatbeg(m);
				break;
			case 3:
				printf("\nEnter the element ");
				scanf("%d",&m);
				printf("\nEnter the positioin after which you want to insert the element");
				scanf("%d",&position);
				addafter(m,position);
				break;
			case 4:
				display();
				break;
			case 5:
				printf("\nEnter element you want to search ");
				scanf("%d",&searchitem);
				search(searchitem);
				break;
			case 6:
				printf("Deletion of a node in a singly linked list ");
				if(start==NULL)
				{
					printf("List is Empty ");
					break;
				}
				printf("Enter the element you want to delete ");
				scanf("%d",&m);
				del(m);
				break;
		}
	}
}
void create_list(int data) 
{
	struct node *q,*tmp;
	tmp=malloc(sizeof(struct node));
	tmp->info=data;
	tmp->link=NULL;
	if(start==NULL)
	{
		start=tmp;
	}
	else{
		q=start;
		while(q->link!=NULL)
		{
			q=q->link;
		}
		q->link=tmp;
	}
}
void addatbeg(int data)
{
	struct node *tmp;
	tmp=malloc(sizeof(struct node));
	tmp->info=data;
	tmp->link=start;
	start=tmp;
	
}
void addafter(int data,int pos)
{
	struct node *tmp,*q;
	int i;
	q=start;
	for(i=0;i<pos-1;i++)
	{
		q=q->link;
		if(q==NULL)
		{
			printf("\nThere are less than %d element ",pos);
			return;
		}
	}
	tmp=malloc(sizeof(struct node));
	tmp->link=q->link;
	tmp->info=data;
	q->link=tmp;
}
void display()
{
	struct node *q;
	if(start==NULL)
	{
		printf("\n List is empty ");
		return;
	}
	q=start;
	printf("\n List \n");
	while(q!=NULL)
	{
		printf("%d",q->info);
		q=q->link;
	}
	printf("\n");
}
void search(int data)
{
	struct node *ptr=start;
	while(ptr!=NULL)
	{
		if(ptr->info==data)
		{
			printf("\nItem found");
			return;
		}
		ptr=ptr->link;
	}
	if(ptr==NULL)
	{
		printf("\nItem not found");
	}
}
void del(int data)
{
	int ch;
	printf("\nEnter case\n1.First node\n2.In between");
	scanf("%d",&ch);
	struct node *tmp,*q;
	switch(ch)
	{
		case 1:
			if(start->info==data)
			{
				tmp=start;
				start=start->link;
				free(tmp);
				return;
			}
			break;
		case 2:
			q=start;
			while(q->link->link!=NULL)
			{
				if(q->link->info==data)
				{
					tmp=q->link;
					q->link=tmp->link;
					free(tmp);
					return;
					
				}
				q=q->link;
				break;
			}
	}
}

