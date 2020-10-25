#include <iostream>
using namespace std;
class Node
{
	public:
	char data;
	Node* next;
};
class single_linked_list
{
	public:
  //insert node at the end of list
	Node* insert_end(Node* head,char a)
	{
		Node *t,*temp;
		t = new Node();
		t->data = a;
		t->next = NULL;
		if(head==NULL)
		{
			head = t;
			return head;
		}
		temp = head;
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next=t;
		return head;
	}
  //insert noe at the start
	Node* insert_before(Node* head,char a)
	{
		Node* t;
		t= new Node();
		t->data = a;
		t->next = head;
		return t;
	}
	void print_list(Node * head)
	{
		Node *t;
		t = head;
		while(t != NULL)
		{
			cout << t->data << "  ";
			t = t->next;
		}
		cout << endl;
	}
	Node* deletenode(Node* head,char a)
	{
		Node *prev,*temp;
		prev = NULL;
		temp = head;
		while(temp->data!=a)
		{
			prev = temp;
			temp = temp->next;
		}
		prev->next = temp->next;
		free(temp);
		return head;
	}
	
	bool is_empty(Node* head)
	{
		return head==NULL;
	}
	

};
