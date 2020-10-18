#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
// Sub linked list structure
typedef struct LinkedList{
    int data;
    struct LinkedList *addr;
}LL;
// Parent Linked List structure
typedef struct Llist{
    int data;
    struct LinkedList *addr1;
    struct Llist *addr2;
}LI;
// Appending in sub linked list
void SAPPEND(LI *h){
    LI *node=h;
    int val;
    printf("Enter the value to append in Sub Linked List : ");
    scanf("%d",&val);
    while(node->addr2!=NULL)
        node=node->addr2;
    if(node->addr1==NULL){
        LL *tem=(LL *)malloc(sizeof(LL));
        tem->addr=NULL;
        tem->data=val;
        node->addr1=tem;
    }else{
        LL *curr=node->addr1;
        while(curr->addr!=NULL)
            curr=curr->addr;
        curr->addr=(LL *)malloc(sizeof(LL));
        curr->addr->addr=NULL;
        curr->addr->data=val;
    }
}
// Appending the node of main linked list
void APPEND(LI **h){
    int val;
    printf("Enter the node value of new Linked List : ");
    scanf("%d",&val);
    if(*h==NULL){
        LI *temp=(LI *)malloc(sizeof(LI));
        temp->data=val;
        temp->addr2=NULL;
        temp->addr1=NULL;
        *h=temp;
    }else{
        LI *curr=*h;
        while(curr->addr2!=NULL)
            curr=curr->addr2;
        curr->addr2=(LI *)malloc(sizeof(LI));
        curr->addr2->addr1=NULL;curr->addr2->data=val;curr->addr2->addr2=NULL;
    }
    int a=1;
    while(a){
        printf("Enter 1 to Append values in Same Sub Linked List\nEnter 0 to finish current Sub Linked List\n");
        scanf("%d",&a);
        switch (a) {
            case 1:
                SAPPEND(*h);
                break;
            case 0:
                break;
        }
    }
}
// Display Function
void DISP(LI **head){
    if(*head==NULL){
        printf("Linked List is Empty !\n");
    }else{
        LI *traverse=*head;
        while(traverse!=NULL){
            LL *traverse_sub=traverse->addr1;
            printf("%d--->",traverse->data);
            while(traverse_sub!=NULL){
                printf("%d--->",traverse_sub->data);
                traverse_sub=traverse_sub->addr;
            }
            printf("NULL\n|\nV\n");
            traverse=traverse->addr2;
        }
        printf("NULL\n");
    }
}
int main(){
    LI *head=NULL;
    int a=1;
    while(a){
        printf("Enter 1 to go to next Linked List\nEnter 2 to Display\nEnter 0 to finish the Linked list\n");
        scanf("%d",&a);
        switch (a) {
            case 1:
                APPEND(&head);
                break;
            case 2:
                DISP(&head);
                break;
            case 0:
                break;
                break;
        }
    }
    return 0;
}


