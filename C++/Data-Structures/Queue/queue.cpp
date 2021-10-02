#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define N 10
int A[N];
int Front = -1;
int Rear = -1;

bool IsEmpty() {
    if(Front==-1 && Rear==-1) return true;
    return false;
}

void Enqueue(int x) {
    if((Rear+1)%N==Front)   return;
    else if(IsEmpty())  Front=Rear=0;
    else    Rear=(Rear+1)%N;
    A[Rear]=x;
}

void Dequeue() {
    if(IsEmpty())   return;
    else if(Front==Rear)    Front=Rear=-1;
    else    Front=(Front+1)%N;
}

int FrontElement(){
    if(Front!=-1)
        return A[Front];
    return -1;
}

int main() {
    Enqueue(2);
    Enqueue(4);
    cout<<FrontElement()<<endl;
    Dequeue();
    cout<<FrontElement();
}
