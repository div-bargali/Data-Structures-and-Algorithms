#include <stdio.h>
#include <stdlib.h>

struct node {
int data;
struct node * prev;
struct node * next;
}*head, *last;

void createList(int n);
void displayList();
void insertAtBeginning(int data);

int main()
{
int n, data, choice=1;
head = NULL;
last = NULL;
printf("\nEnter the total number of nodes in list : "); // Input the number of nodes
scanf("%d", &n);
createList(n);
displayList();
printf("\n\nEnter data of first node : ");
scanf("%d", &data);
insertAtBeginning(data);
displayList();
return 0;
}

void createList(int n)
{
int i, data;
struct node *newNode;
if(n >= 1)
{
head = (struct node *)malloc(sizeof(struct node));
printf("\nEnter data of node 1 : ");
scanf("%d", &data);
head->data = data;
head->prev = NULL; // HEAD nodes's prev is set to NULL
head->next = NULL; // HEAD nodes's next is set to NULL
last = head;
for(i=2; i<=n; i++)
{
newNode = (struct node *)malloc(sizeof(struct node));
printf("\nEnter data of node %d : ", i);
scanf("%d", &data);
newNode->data = data;
newNode->prev = last; // Link new node with the previous node
newNode->next = NULL;
last->next = newNode; // Link previous node with the new node
last = newNode; // Make new node as last node
}}}

void displayList()
{
struct node * temp;
int n = 1;
if(head == NULL)
{
printf("\nList is empty.\n");
}
else
{
temp = head;
printf("\nTHE DOUBLY LINKED LIST IS :\n\n");
// Print the list
while(temp != NULL)
{
printf("%d\t", temp->data);
n++;
/* Move the current pointer to next node */
temp = temp->next;
}}}

/* Function to insert node at the beginning of the list */
void insertAtBeginning(int data)
{
struct node * newNode;
if(head == NULL)
{
printf("Error, List is Empty!\n");
}
else
{
newNode = (struct node *)malloc(sizeof(struct node));
newNode->data = data;
newNode->next = head; // Point to next node which is currently head
newNode->prev = NULL; // Previous node of first node is NULL
/* Link previous address field of head with newNode */
head->prev = newNode;
/* Make the new node as head node */
head = newNode;
}
}
