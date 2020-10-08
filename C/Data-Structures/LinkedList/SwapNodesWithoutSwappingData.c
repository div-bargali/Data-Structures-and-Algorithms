// Program in C to swap nodes without swapping data

// example - 

// input -
// 6
// 10 15 12 13 20 14
// 12 20

// output
// 10 15 20 13 12 14

#include <stdio.h>

#include<stdlib.h>

struct node{

int data;

struct node* next;

};

void display(struct node *ptr){

do{

printf("%d ", ptr->data );

ptr =ptr->next;

}

while(ptr!=NULL);

}

struct node *createList(int n){
int i=0;
struct node *head=NULL;
struct node *temp=NULL;
struct node *p=NULL;
for(i=0;i<n;i++){
temp = (struct node *)malloc(sizeof(struct node));
scanf("%d",&(temp->data));
temp->next=NULL;
if(head==NULL){
head=temp;
}
else{
p=head;
while(p->next!=NULL)
p=p->next;
p->next=temp;
}
}
return head;
}
int main() {

int n,x,y;
// printf("enter the size of linked list\n");
scanf("%d", &n);
struct node* head=(struct node*)malloc(sizeof(struct node));
head=createList(n);
//enter x and y
scanf("%d",&x);
scanf("%d",&y);
struct node* p=(struct node*)malloc(sizeof(struct node));
struct node* prev=(struct node*)malloc(sizeof(struct node));
p=head;
while(p!=NULL && p->data!=x)
{
prev=p;
p=p->next;
}
struct node *pX=p;
struct node* prevX=prev;
p=head;
prev=NULL;
while(p!=NULL&&p->data!=y){
prev=p;
p=p->next;
}
struct node *pY=p;
struct node* prevY=prev;
struct node* temp=(struct node*)malloc(sizeof(struct node));
temp=pY->next;
pY->next=pX->next;
pX->next=temp;
if(prevX==NULL){
head=pY;
prevY->next=prevX;
}
if(prevY==NULL){
head=pX;
prevX->next=prevY;
}
if(prevX!=NULL && prevY!=NULL){
prevX->next=pY;
prevY->next=pX;
}
display(head);
return 0;
}
