#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};
typedef struct node NODE;
NODE *currptr,*start=NULL,*lastptr,*newnode;
int count=1;
NODE* getnode(int value)
{
    NODE *newnode=(NODE *)malloc(sizeof(NODE));
    if(newnode==NULL)
    {
    printf("Memory not alloted\n");
    return (0);
    }
    else
    {
    newnode->info=value;
    newnode->link=NULL;
    return(newnode);
    }
}
void insert_beg()
{
    int item;
    printf("Enter the value to be inserted:");
    scanf("%d", &item);
    newnode=getnode(item);
    if(start==NULL)
    {start=newnode;
    newnode->link=NULL;
    }
    else
    {
    newnode->link=start;
    start=newnode;
    }

}
void reverse()
{
    int temp;
    currptr=start;
    lastptr=start;
    while(lastptr->link!=NULL)
    {
    lastptr=lastptr->link;
    count++;
    }
    int i,j;
    for(i=0;i<count-1;i++)
    {
        for(j=0;j<count-i-1;j++)
        {
         temp=currptr->info;
         currptr->info=currptr->link->info;
         currptr->link->info=temp;


        currptr=currptr->link;
        }
        currptr=start;
    }
    }
void display()
{
    if(start==NULL)
    printf("NO nodes to display\n");
    for(currptr=start;currptr!=NULL;currptr=currptr->link)
    printf("%d",currptr->info);
}
void main()
{
 int c;
 do{

 printf("Enter choice\n");
 scanf("%d", &c);
    switch(c)
    {


 case 1:insert_beg();break;
 case 2:reverse();break;
 case 3:display();break;
}
 }while(c!=4);

 }
