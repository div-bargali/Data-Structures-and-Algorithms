//demonstration of adding nodes in a doubly linked list

#include <iostream>
using namespace std;

// A linked list node  
struct Node {  
    int data;  
    struct Node* next;  
    struct Node* prev;  
};  
  
void push(Node** head_ref, int new_data)  
{  
    /* 1. allocate node */
    Node* new_node = new Node();  
  
    Node* last = *head_ref; /* used in step 5*/
  
    /* 2. put in the data */
    new_node->data = new_data;  
  
    /* 3. This new node is going to be the last node, so  
        make next of it as NULL*/
    new_node->next = NULL;  
  
    /* 4. If the Linked List is empty, then make the new  
        node as head */
    if (*head_ref == NULL) 
    {  
        new_node->prev = NULL;  
        *head_ref = new_node;  
        return;  
    }  
  
    /* 5. Else traverse till the last node */
    while (last->next != NULL)  
        last = last->next;  
  
    /* 6. Change the next of last node */
    last->next = new_node;  
  
    /* 7. Make last node as previous of new node */
    new_node->prev = last;  
  
    return;  
}  

/* Function to delete a node in a Doubly Linked List. 
   head_ref --> pointer to head node pointer. 
   del  -->  pointer to node to be deleted. */
void deleteNode(struct Node** head_ref, struct Node* del) 
{ 
    /* base case */
    if (*head_ref == NULL || del == NULL) 
        return; 
  
    /* If node to be deleted is head node */
    if (*head_ref == del) 
        *head_ref = del->next; 
  
    /* Change next only if node to be deleted is NOT  
       the last node */
    if (del->next != NULL) 
        del->next->prev = del->prev; 
  
    /* Change prev only if node to be deleted is NOT  
       the first node */
    if (del->prev != NULL) 
        del->prev->next = del->next; 
  
    /* Finally, free the memory occupied by del*/
    free(del); 
} 

void deletepos(struct Node** head_ref, int n) 
{ 
    /* if list in NULL or invalid position is given */
    if (*head_ref == NULL || n <= 0) 
        return; 
  
    struct Node* current = *head_ref; 
    int i; 
  
    /* traverse up to the node at position 'n' from 
       the beginning */
    for (int i = 1; current != NULL && i < n; i++) 
        current = current->next; 
  
    /* if 'n' is greater than the number of nodes 
       in the doubly linked list */
    if (current == NULL) 
        return; 
  
    /* delete the node pointed to by 'current' */
    deleteNode(head_ref, current); 
} 

void printList(Node* node)  
{  
    Node* last;  
    cout<<"\nThe contents of list\n";  
    while (node != NULL)  
    {  
        cout<<" "<<node->data<<" ";  
        last = node;  
        node = node->next;  
    }  
  
}  
  
int main()
{
    int *arr;
    arr = new int[10];
    
    int n=0;
    int input;
    int i=0;
    
    while (true) {

	cin >> input;

    if (!cin.fail())
    {
    arr[i] = input;

    i++;
    }
    
    else break;
	}
	
	for(int j=0;j<i;j++)
	cout<<arr[j]<<" ";
    /* Start with the empty list */
    Node* head = NULL;  
  
    for(int n=0;n<i;n++)
    {
        push(&head,arr[n]);
    }
    
    cout << "Created DLL is: ";  
    printList(head);  
    
    deletepos(&head,2);
    printList(head);
    return 0;  
}
