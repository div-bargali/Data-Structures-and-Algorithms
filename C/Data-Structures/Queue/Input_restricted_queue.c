well this how to do a c program with a concept of input restricted queue check it out !!!!!!!!!!!


#include<stdio.h>
#include<stdlib.h>
#define max 4
typedef struct queue
{
	int data[max];
	int front,rear;
}queue;
int isempty(queue *q)
{
	if(q->front==-1 && q->rear==-1)//when no element in the queue
		return 1;
	else
		return 0;
}
int isfull(queue *q)
{
	if(q->rear==max-1)//here MAX is size of queue
		return 1;
	else
		return 0;
}
void insert(queue *q,int x)
{
	if(isfull(q))//when queue is full
	{
		printf("\nqueue overflow");
		return;
	}
	else if(isempty(q))//when the queue is empty, will will insert first element
		q->rear=q->front=0;//both front and rear will increase by 1 i.e set to 0
	else//there are some elements already present in queue
		q->rear=q->rear+1;//only rear will increase by 1
	q->data[q->rear]=x;//new element x assigned to index rear
}
int delet_front(queue *q)
{
	int x;
	if(isempty(q))
	{
		printf("\nqueue underflow");
		return -1;
	}
	x=q->data[q->front];//element from the front end is to be deleted
	if(q->front==q->rear)//when only one element present in the queue
		q->front=q->rear=-1;//then both front & rear will decrease by 1, i.e set to -1
	else//when more than one elemet present in queue
		q->front=q->front+1;//then only front will increase by 1
	return x;
}
int delet_rear(queue *q)
{
	int x;
	if(isempty(q))
	{
		printf("\nqueue underflow");
		return -1;
	}
	x=q->data[q->rear];//element from the rear end is to be deleted
	if(q->front==q->rear)//when only one element present in the queue
		q->front=q->rear=-1;//then both front & rear will decrease by 1, i.e set to -1
	else//when more than one elemet present in queue
		q->rear=q->rear-1;//then only rear will decrease by 1
	return x;
}
void disp(queue *q)
{
	int i;
	if(isempty(q))
	{
		printf("\nqueue underflow");
		return;
	}
	for(i=q->front;i<=q->rear;i++)//elements will be printed from front to rear
		printf("%d\t",q->data[i]);
	
	printf("\ntotal elements = %d ",q->rear-q->front+1);
	printf("\nFront = %d",q->front);
	printf("\nRear = %d",q->rear);
}
int main()
{
 queue *q;
 q=(queue*)malloc(sizeof(queue));
 int num,op,item;
 q->front=-1;
 q->rear=-1;
 while(1)
 {
 	printf("\n1.INSERT\n2.DELETE FRONT\n3.DELETE REAR\n4.DISPLAY\n5.EXIT\n");
 	printf("enter option : ");
 	scanf("%d",&op);
 	switch(op)
 	{
 		case 1:
 			printf("enter item to insert : ");
 			scanf("%d",&item);
 			insert(q,item);
 			break;
 		case 2:
 			num=delet_front(q);
 			if(num!=-1)
 			{
 				printf("\ndeleted item = %d",num);
 			}
 			break;
 		case 3:
 			num=delet_rear(q);
 			if(num!=-1)
 			{
 				printf("\ndeleted item = %d",num);
 			}
 			break;
 		case 4:
 			printf("\nthe queue elsements\n");
 			disp(q);
 			break;
 		case 5:exit(0);
 		default:printf("invalid option\n");
 	}
 };
 return 0;
}
