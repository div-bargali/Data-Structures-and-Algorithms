

//Deletion of cll
// C program to delete a given key from 
// linked list. 
#include <stdio.h> 
#include <stdlib.h> 

/* structure for a node */
struct Node { 
	int data; 
	struct Node* next; 
}; 

/* Function to insert a node at the beginning of 
a Circular linked list */
void push(struct Node** head_ref, int data) 
{ 
	// Create a new node and make head as next 
	// of it. 
	struct Node* ptr1 = (struct Node*)malloc(sizeof(struct Node)); 
	ptr1->data = data; 
	ptr1->next = *head_ref; 

	/* If linked list is not NULL then set the 
	next of last node */
	if (*head_ref != NULL) { 
		// Find the node before head and update 
		// next of it. 
		struct Node* temp = *head_ref; 
		while (temp->next != *head_ref) 
			temp = temp->next; 
		temp->next = ptr1; 
	} 
	else
		ptr1->next = ptr1; /*For the first node */

	*head_ref = ptr1; 
} 

/* Function to print nodes in a given 
circular linked list */
void printList(struct Node* head) 
{ 
	struct Node* temp = head; 
	if (head != NULL) { 
		do { 
			printf("%d ", temp->data); 
			temp = temp->next; 
		} while (temp != head); 
	} 

	printf("\n"); 
} 

/* Function to delete a given node from the list */
void deleteNode(struct Node* head, int key) 
{ 
	if (head == NULL) 
		return; 

	// Find the required node 
	struct Node *curr = head, *prev; 
	while (curr->data != key) { 
		if (curr->next == head) { 
			printf("\nGiven node is not found"
				" in the list!!!"); 
			break; 
		} 

		prev = curr; 
		curr = curr->next; 
	} 

	// Check if node is only node 
	if (curr->next == head) { 
		head = NULL; 
		free(curr); 
		return; 
	} 

	// If more than one node, check if 
	// it is first node 
	if (curr == head) { 
		prev = head; 
		while (prev->next != head) 
			prev = prev->next; 
		head = curr->next; 
		prev->next = head; 
		free(curr); 
	} 

	// check if node is last node 
	else if (curr->next == head) { 
		prev->next = head; 
		free(curr); 
	} 
	else { 
		prev->next = curr->next; 
		free(curr); 
	} 
} 

/* Driver program to test above functions */
int main() 
{ 
	/* Initialize lists as empty */
	struct Node* head = NULL; 

	/* Created linked list will be 2->5->7->8->10 */
	push(&head, 2); 
	push(&head, 5); 
	push(&head, 7); 
	push(&head, 8); 
	push(&head, 10); 

	printf("List Before Deletion: "); 
	printList(head); 

	deleteNode(head, 7); 

	printf("List After Deletion: "); 
	printList(head); 

	return 0; 
} 

