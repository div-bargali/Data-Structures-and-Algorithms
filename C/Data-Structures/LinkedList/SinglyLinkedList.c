#include<stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node* next;
};

void addBeg(struct Node** h,int d){
  struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
  temp->data = d;
  temp->next = (*h);
  (*h) = temp;
  printf("\nAdded at beggining.\n\n\n");

}

void addEnd(struct Node** h, int d){
  struct Node* temp = (*h);
  struct Node* new = (struct Node*)malloc(sizeof(struct Node));
  new->data = d;
  new->next = NULL;
  if(*h ==NULL){
    *h = new;
    return;
  }
  while(temp->next !=NULL){
    temp = temp->next;
  }
  temp->next = new;
  printf("\nAdded at end..\n\n\n");
  return;
}

void printList(struct Node *node)
{
  if(node == NULL){
    printf("Empty List!\n");
  }
  while (node != NULL)
  {
     printf(" %d ", node->data);
     node = node->next;
  }
  printf("\n\n\n");
}
// Deleting the node having first occurrence of key
void deleteKey(struct Node** h, int key){
  if (*h == NULL){
    printf("\nEmpty list! Try again..\n");
    return;
  }
  struct Node* temp= *h, *prev;

  if(temp!=NULL && temp->data == key){
    *h =temp->next;
    printf("\nDeleted.. \n\n\n");
    free(temp);
    return;
  }
  while(temp!=NULL && temp->data!=key){
    prev=temp;
    temp = temp->next;
  }
  if(temp == NULL){
    printf("\nElement not found! Retry..\n");
    return;
  }

  prev->next = temp->next;
  printf("\nDeleted\n\n\n");
  free(temp);

}
//Delete -> Position
void deletePos(struct Node** h, int pos){
  if (*h == NULL){
    printf("\n\nEmpty List! Try adding..\n");
    return;
  }
  struct Node* temp=*h;
  if(pos == 0){
    *h=temp->next;
    free(temp);
    printf("\n\nDeleted.. \n\n\n");
    return;
  }
  int i;
  for(i=0; i<pos-1;i++)
  {
    temp=temp->next;
  }
  if(temp == NULL || temp->next == NULL){
    printf("\n\nInvalid position! Try again...\n\n\n");
    return;
  }
  struct Node* next =temp->next->next;
  printf("\nDeleted.. \n\n\n");
  free(temp->next);
  temp->next=next;

}

int main(){
  struct Node* head = NULL;
  int stop=1;
while(stop){
    printf("Enter a choice from following :\n\n1:Add element at beggining.\n2:Add element at end.\n3:Delete element by key.\n4:Display list.\n5:Stop.\n6:Delete element by position\n");
    int choice,el,key;
    printf("\n\nEnter your choice : ");
    scanf("%d",&choice);
    switch (choice) {
      case 1:
        printf("Enter element\n");
        scanf("%d",&el);
        addBeg(&head,el);
        break;
      case 2:
        printf("Enter element\n");
        scanf("%d",&el);
        addEnd(&head,el);
        break;
      case 3:
        printf("Enter key\n");
        scanf("%d",&key);
        deleteKey(&head,key);
        break;
      case 4:
        printList(head);
        break;
      case 5:
        stop=0;
        break;
      case 6:
        printf("Enter position\n");
        scanf("%d",&key);
        deletePos(&head,key);
        break;
      default:
        printf("Invalid Choice! Come again.\n");
        break;
    }

  }
  return 0;
}