//creation of circular linked list
#include<stdio.h>
#include<malloc.h>
struct node
{
	int info;
	struct node *link;
}*last=NULL;
main()
{
	int data;
	printf("Enter the data ");
	scanf("%d",&data);
	struct node *tmp;
	tmp=malloc(sizeof(struct node));
	tmp->info=data;
	if(last==NULL)
	{
		last=tmp;
		tmp->link=last;
	}
	else
	{
		tmp->link=last->link;
		last->link=tmp;
		last=tmp;
	}
}
