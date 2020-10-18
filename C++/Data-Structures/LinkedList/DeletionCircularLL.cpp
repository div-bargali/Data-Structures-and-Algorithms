#include <bits/stdc++.h>
using namespace std;


//Test cases:
//1
//5
//1 2 3 4 5
//Expected Output:
//2 3 4 5
//input (index = 3)
//2 3 4
//2 3


//Class for creation of a Node
class Node{
    public:
      int data;
      Node* next;
      Node(int data)
      {
        this->data = data;
        this->next = NULL;
      }
};

//Class for implementation of CLL
class CLL{
    public:
    //to keep track of head of the LL
    Node* head;
    //to keep track of the last node of LL.
    Node* tail;
    CLL()
    {
      this -> head = NULL;
      this -> tail = NULL;
    }
    //Since this code is to demonstrate deletion, we will only use InsertAtEnd in the CLL
    void insertAtEnd(int data)
    {

      //Create new node
      Node* newNode = new Node(data);

      //If list is empty
      if(head == NULL)
      {
        head = newNode;
        tail = newNode;
        tail -> next = head;
      }

      //If there are elements already present in the list
      else
      {
        tail -> next = newNode;
        tail = newNode;
        tail -> next = head;
      }
    }


    //Delete node from the beginning
    void deleteFromBeg()
    {
        Node* temp = head;
        if(temp == NULL)
        {
            cout<<"LL is empty!"<<endl;
            return;
        }
        else if(temp->next == temp)
        {
            head = NULL;
            tail = NULL;
            free(temp);
            return;
        }
        head = head -> next;
        tail -> next = head;
        free(temp);
    }

    //Delete Node from middle given the index
    void deleteFromMid(int index)
    {
        if(index == 0)
        {
            deleteFromBeg();
            return;
        }
        Node* temp = head;
        if(temp == NULL)
        {
            cout<<"LL is empty!"<<endl;
            return;
        }
        if(temp -> next == temp)
        {
            head = NULL;
            tail = NULL;
            free(temp);
            return;
        }
        int count = 0;

        //Traverse to the node to be deleted
        while(count != index - 1 && temp->next != tail)
        {
            temp = temp -> next;
            count++;
        }

        //If node to be deleted is the next node
        if(count == index - 1)
        {
            Node* temp1 = temp->next;
            temp->next = temp1->next;
            if(temp1 == tail)
            {
                tail = temp;
            }
            free(temp1);
        }

        //If last node has been reached but index has not been found
        if(temp->next == tail && count!=index-1)
        {
            cout<<"Index out of bounds!"<<endl;
            return;
        }

    }

    //Delete last node
    void deleteFromEnd()
    {
        Node* temp = head;

        //If LL is empty
        if(temp == NULL)
        {
            cout<<"LL is empty"<<endl;
            return;
        }

        //If LL has just one element
        else if(temp -> next == temp)
        {
            head = NULL;
            tail = NULL;
            free(temp);
            return;
        }

        //Otherwise
        while(temp -> next != tail)
        {
            temp = temp -> next;
        }
        Node* temp1 = temp->next;
        temp -> next = temp1 -> next;
        tail = temp;
        free(temp1);

    }
    //To display the CLL
    void display()
    {
      Node* temp = head;
      if(temp == NULL)
      {
          cout<<"Empty LL!"<<endl;
          return;
      }
      cout<<temp->data<<" ";
      temp = temp->next;
      while(temp != head)
      {
        cout<<temp->data<<" ";
        temp = temp->next;
      }
      cout<<endl;
    }

  };
  int main()
  {
    int test_cases;
    cout<<"Enter number of test cases:"<<endl;
    cin>>test_cases;
    while(test_cases--)
    {
      cout<<"Enter number of elements:"<<endl;
      int n;
      cin>>n;
      int index;
      CLL* linkedList = new CLL();
      cout<<"Enter elements: "<<endl;
      while(n--)
      {
        int data;
        cin>>data;

        linkedList->insertAtEnd(data);
      }
      cout<<"Current LL is:"<<endl;
      linkedList -> display();
      cout<<"Deleting first node:"<<endl;
      linkedList -> deleteFromBeg();
      linkedList -> display();
      cout<<"Enter index to delete element from (0-based indexing):"<<endl;
      cin>>index;
      cout<<"Deleting node at index "<<index<<":"<<endl;
      linkedList -> deleteFromMid(index);
      linkedList -> display();
      cout<<"Deleting last node:"<<endl;
      linkedList -> deleteFromEnd();
      linkedList -> display();
    }

    return 0;
  }
