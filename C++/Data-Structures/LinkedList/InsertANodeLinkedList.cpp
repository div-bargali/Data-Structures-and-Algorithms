/*
Insert a Node

Inserting an element in between the elements in an array requires you to shift the elements to the left but in Linked list it is just about modifying few links. Let's practice inserting a node in an array, but there is a rule : 
You are given a sorted linked list and you have to insert a node in the list in a sorted manner. 
For example - if the given list is 
HEAD->2->3->6->8->NULL and you have to insert 4, you will insert it after 3 and your modified list will look something like this 
HEAD  ->2->3->4->6->8->NULL.

Input Format
The first line contains an integer T, number of test cases. Then follows T test cases. Each test case consists of three lines. The first line contains N, 
size of the list. The second line contains N space-separated positive integers denoting elements of the list. 
The third line contains an integer denoting the data value to be inserted.

Output Format
The output contains T lines, each line containing the modified list.

Contributor = Ankit Surwade
*/

#include <bits/stdc++.h>
using namespace std;
typedef struct Node{                          //create class
  int data;
  struct Node* next;
}node;
  node* head=NULL;
void insertAtEnd(int data){                   //insert function (from beginning to end)
    node *nn=(node*) malloc(sizeof(node));
    nn->data=data;
    nn->next=NULL;
    node *temp=head;
    if(temp==NULL){
        head=nn;
        return;  
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=nn;
}
void insertAtMid(node* nn,node **head){        //insert mid
if((*head)==NULL || (*head)->data >= nn->data)
{
    nn->next=*head;
    *head=nn;
    return;
}
  node *temp=*head;
  while(temp->next!=NULL && temp->next->data < nn->data )
    temp=temp->next;
  
  nn->next=temp->next;
  temp->next=nn;
}

node* nen(int data)
{
    node* nn =(node*) malloc(sizeof(node));
    nn->data=data;
    nn->next=NULL;
    return nn;

}
void display()                                   //print function
{
  node* temp;
  temp=head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
}
int main()                                        //driver mode
  {
    //write your code here
    int  t;
    cin>>t;
while(t--)
{
  int n;
  cin>>n;
  int data;
  for(int i=0;i<n;i++)
  {
    cin>>data;
    insertAtEnd(data);                              //call insert function
  }
  int item;
  cin>>item;
  node* nn =nen(item);
  insertAtMid(nn,&head);                            //call insert middle function
  display();                                        //call print function
  nn=NULL;
  
 head=NULL;
  cout<<"\n";
}
    return 0;
  }

