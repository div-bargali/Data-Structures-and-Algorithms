#include <stdio.h> 
#include <stdlib.h> 
  
/* Link list node */
struct Node { 
    int data; 
    struct Node* next; 
}; 
  
/* Function to remove loop. Used by detectAndRemoveLoop() */
void removeLoop(struct Node*, struct Node*); 
  
/* This function detects and removes loop in the list 
  If loop was there in the list then it returns 1, 
  otherwise returns 0 */
int detectAndRemoveLoop(struct Node* list) 
{ 
    struct Node *slow_p = list, *fast_p = list; 
  
    while (slow_p && fast_p && fast_p->next) { 
        slow_p = slow_p->next; 
        fast_p = fast_p->next->next; 
  
        /* If slow_p and fast_p meet at some point then there 
           is a loop */
        if (slow_p == fast_p) { 
            removeLoop(slow_p, list); 
  
            /* Return 1 to indicate that loop is found */
            return 1; 
        } 
    } 
  
    /* Return 0 to indeciate that ther is no loop*/
    return 0; 
} 
  
/* Function to remove loop. 
 loop_node --> Pointer to one of the loop nodes 
 head -->  Pointer to the start node of the linked list */
void removeLoop(struct Node* loop_node, struct Node* head) 
{ 
    struct Node* ptr1; 
    struct Node* ptr2; 
  
    /* Set a pointer to the beginning of the Linked List and 
      move it one by one to find the first node which is 
      part of the Linked List */
    ptr1 = head; 
    while (1) { 
        /* Now start a pointer from loop_node and check if it ever 
       reaches ptr2 */
        ptr2 = loop_node; 
        while (ptr2->next != loop_node && ptr2->next != ptr1) 
            ptr2 = ptr2->next; 
  
        /* If ptr2 reahced ptr1 then there is a loop. So break the 
        loop */
        if (ptr2->next == ptr1) 
            break; 
  
        /* If ptr2 did't reach ptr1 then try the next node after ptr1 */
        ptr1 = ptr1->next; 
    } 
  
    /* After the end of loop ptr2 is the last node of the loop. So 
     make next of ptr2 as NULL */
    ptr2->next = NULL; 
} 
  
/* Function to print linked list */
void printList(struct Node* node) 
{ 
    while (node != NULL) { 
        printf("%d  ", node->data); 
        node = node->next; 
    } 
} 
  
struct Node* newNode(int key) 
{ 
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); 
    temp->data = key; 
    temp->next = NULL; 
    return temp; 
} 
  
/* Drier program to test above function*/
int main() 
{ 
    struct Node* head = newNode(50); 
    head->next = newNode(20); 
    head->next->next = newNode(15); 
    head->next->next->next = newNode(4); 
    head->next->next->next->next = newNode(10); 
  
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next; 
  
    detectAndRemoveLoop(head); 
  
    printf("Linked List after removing loop \n"); 
    printList(head); 
    return 0; 
} 
