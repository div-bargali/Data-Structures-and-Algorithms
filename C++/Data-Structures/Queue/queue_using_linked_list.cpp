#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

struct Node* Front = NULL;
struct Node *Rear = NULL;

void Enqueue(int x) {
    struct Node *temp = new Node;
    temp->data = x;
    temp->next = NULL;

    if(Front == NULL && Rear == NULL){
        Front=Rear=temp;
        return;
    }
    Rear->next = temp;
    Rear = temp;
}

void Dequeue() {
    struct Node *temp = Front;
    if(Front == NULL){
        return;
    }
    if(Front == Rear){
        Front=Rear=NULL;
    }
    else{
        Front=Front->next;
    }
    free(temp);
}

int FrontElement(){
    if(Front!=NULL)
        return Front->data;
    return -1;
}

int main() {
    Enqueue(2);
    Enqueue(4);
    Enqueue(6);
    cout<<FrontElement()<<endl;
    Dequeue();
    cout<<FrontElement()<<endl;
    Dequeue();
    cout<<FrontElement()<<endl;
    Dequeue();
    cout<<FrontElement()<<endl;
}
