#include<stdio.h>
#include<stdlib.h>
#define max 10
int insertq ( int queue[max], int *rear , int *data)
{
      if ( *rear == max -1 )
            return(-1);
      else
      {
            *rear = *rear + 1;
            queue[*rear] = *data;
            return(1);
      }
}
int delq( int queue[max], int *front, int *rear , int *data)
{
      if ( *front == *rear)
            return(-1);
      else
      {
            (*front)++;
            *data = queue[*front];
            return(1);
      }
}
int main()
{
      int queue[max],data;
      int front,rear,reply,option;
      //... init queue
      front = rear = -1;
      printf("\tMenu");
      printf("\n----------------------------");
      printf("\n 1. Insert element in queue");
      printf("\n 2. Delete element from queue");
      printf("\n 3. Exit");
      printf("\n----------------------------");
      while(1)
      {
            printf("\nChoose operation : ");
            scanf("%d",&option);
            switch(option)
            {
                  case 1 ://insert
                        printf("\nEnter Number : ");
                        scanf("%d",&data);
                        reply = insertq(queue,&rear,&data);
                        if ( reply == - 1)
                              printf("Queue is full");
                        else
                              printf("%d is inserted in queue.\n",data);
                        break;
                  case 2 : //dele
                        reply = delq(queue,&front,&rear,&data);
                        if ( reply == -1 )
                              printf("Queue is empty ");
                        else
                              printf("\nDeleted number is : %d\n", data);
                              break;
                        case 3 : exit(0);
            }
      }
}