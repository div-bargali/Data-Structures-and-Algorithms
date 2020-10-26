#include<stdio.h>
#include<stdlib.h>

// To track the size of the linked list
int SIZE = 0;

// Node for doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* top = NULL;

// A function to push a given element into the Doubly-Linked Stack.
void stack_push(int value) {
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->data = value;
    new->prev = NULL;
    new->next = NULL;
    if(top != NULL) {
        new->prev = top;
    }
    top = new;
    SIZE++;
}

// A function to pop the top most element of the Doubly-Linked Stack.
int stack_pop() {
    if(top == NULL) {
        return 0;
    }
    int popped_value = top->data;
    top = top->prev;
    printf("The value %d was popped!\n", popped_value);
    SIZE--;
    return popped_value;
}

// A function to peek the top most element of the Doubly-Linked Stack.
void stack_peek() {
    if(top == NULL) {
        return;
    }
    printf("%d\n", top->data);
}

// A function to get the element at a given index(idx) in the Doubly-Linked Stack.
int stack_get_at(int idx) {
    if(idx < 0 || idx >= SIZE){
        return 0;
    }
    if(top == NULL) {
        printf("Underflow! Stack is Empty!\n");
        return -1;
    }
    struct Node* temp = top;
    for(int i = 0; i < idx; i++) {
        temp = temp->prev;
    }
    printf("Value at index %d is %d.\n", idx, temp->data);
    return idx;
}

// A function to insert the given element(value) at a given index(idx) in the Doubly-Linked Stack.
void stack_insert_at(int idx, int value) {
    if(idx == 0) {
        // When the given index is 0, that basically means to push an element.
        stack_push(value);
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->prev = NULL;
    new_node->next = NULL;
    struct Node* temp = top;
    for(int i = 0; i < idx - 1; i++) {
        temp = temp->prev;
    }
    new_node->next = temp;
    new_node->prev = temp->prev;
    temp->prev = new_node;
    SIZE++;
    printf("The value %d was inserted at index %d of the stack.\n", value, idx);
}

// A function to print all the elements in the Doubly-Linked Stack.
void stack_show_all_elements() {
    if(top == NULL) return;

    struct Node* temp;
    temp = top;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp -> prev;
    }
    printf("\n");
}

// A function to get the size(number of elements) of the Doubly-Linked Stack.
int get_stack_size() {
    printf("Size of Stack : %d\n", SIZE);
    return SIZE;
}

// A function to prompt the user with instructions.
void stack_prompt() {
    int value, given;
    printf("1 => Push a value in Stack\n");
    printf("2 => Peek the top of the stack\n");
    printf("3 => Pop an element from Stack\n");
    printf("4 => Display all elements in Stack\n");
    printf("5 => Get Element at Index\n");
    printf("6 => Enter element at index\n");
    printf("7 => Get the size of the Stack\n");
    printf("8 => Exit\n");
    do {
        printf(">>> ");
        scanf("%d", &given);
        switch(given) {
            case 1: {
                printf("Value: ");
                scanf("%d", &value);
                stack_push(value);
                break;
            }
            case 2: {
                stack_peek();
                break;
            }
            case 3: {
                stack_pop();
                break;
            }
            case 4: {
                stack_show_all_elements();
                break;
            }
            case 5: {
                int idx;
                printf("Enter the index: ");
                scanf("%d", &idx);
                stack_get_at(idx);
                break;
            }
            case 6: {
                int idx, data;
                printf("Enter the index: ");
                scanf("%d", &idx);

                if(idx > SIZE) {
                    break;
                }
                printf("Enter the data: ");
                scanf("%d", &data);
                stack_insert_at(idx, data);
                break;
            }
            case 7: {
                get_stack_size();
                break;
            }
            case 8: {
                break;
            }
            default: {
                printf("Not a valid input!\n");
            }
        }
    } while(given!=8);
}

int main() {
    stack_prompt();
    return 0;
}

