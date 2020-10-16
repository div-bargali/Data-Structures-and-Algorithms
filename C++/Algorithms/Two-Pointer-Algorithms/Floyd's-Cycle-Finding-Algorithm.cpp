#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node *next;
};
// each data is inserted in the front of linkedlist
Node* push(Node *head, int data) {
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}
void detectLoop(Node *head) {
    Node *slow_ptr = head, *fast_ptr = head;
    while(slow_ptr && fast_ptr && fast_ptr->next) {
        slow_ptr = slow_ptr->next;           // moves one step at a time
        fast_ptr = fast_ptr->next->next;     // moves two steps at a time
        if(slow_ptr == fast_ptr) {           // when both the pointers intersect each other 
            cout << "Loop Detected" << endl;
            return;
        }
    }
    cout << "No Loop Detected" << endl;
    return;
}
int main() {
    // initially list is empty
    Node *head = NULL;  // head -> NULL
    head = push(head, 1);     // head -> 1 -> NULL
    head = push(head, 2);     // head -> 2 -> 1 -> NULL
    head = push(head, 3);     // head -> 3 -> 2 -> 1 -> NULL
    head = push(head, 4);     // head -> 4 -> 3 -> 2 -> 1 -> NULL
    head = push(head, 5);     // head -> 5 -> 4 -> 3 -> 2 -> 1 -> NULL
    // to create a loop
    head->next->next->next->next->next = head;  // head -> 5 -> 4 -> 3 -> 2 -> 1 -> head
    detectLoop(head);
    return 0;
}