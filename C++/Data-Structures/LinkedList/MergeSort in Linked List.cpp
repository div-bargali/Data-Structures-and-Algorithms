/* 
This program will sort a linked list in nlog(n) time using merge sort. There are certain helper
functions like merging two sorted linked lists, breaking a linked list into two equal sized linked 
lists for the recursion, inserting in the linked list, and printing the linked list.
*/


#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* next;
};
void insert(int data,node** head){    // function for inserting an element in the linked list
    if(*head==NULL){
        node* n=new node;
        n->data=data;
        n->next=NULL;
        *head=n;
        return;
    }
    node* current=*head;
    while(current->next!=NULL){
        current=current->next;
    }
    node* n=new node;
    n->data=data;
    n->next=NULL;
    current->next=n;
}
void print(node* head){           // function to print the linked list in linear order
    node* current=head;
    while(current!=NULL){
        cout<<current->data<<" ";
        current=current->next;
    }
    cout<<endl;
}
node* split(node* head){        // function to split the linked list into two halves for the recursion to be called to both
    node* hare=head;
    node* tortoise=head;
    while(hare->next !=NULL && hare->next->next!=NULL){
        hare=hare->next->next;
        tortoise=tortoise->next;
    }
    if(hare->next==NULL){
        node* r=tortoise->next;
        tortoise->next=NULL;
        return r;
    }
    else{
        node* r=tortoise->next;
        tortoise->next=NULL;
        return r;
    }
}
node* converge(node* head1,node* head2){        // merging two sorted linked list
    if(!head1){
        return head2;
    }
    if(!head2){
        return head1;
    }
    if(head1->data<=head2->data){
        head1->next=converge(head1->next,head2);
        return head1;
    }
    else{
        head2->next=converge(head1,head2->next);
        return head2;
    }
}
node* mergeSort(node* head){                // function for the merge sort algorithm
    if(!head || head->next==NULL){
        return head;
    }
    node* node1=head;
    node* node2=split(head);
    return converge(mergeSort(node1),mergeSort(node2));
}
// Driver function
int main(){
    node* head=NULL;
    insert(2,&head);
    insert(4,&head);
    insert(3,&head);
    insert(1,&head);
    print(head);
    head=mergeSort(head);
    print(head);
}
