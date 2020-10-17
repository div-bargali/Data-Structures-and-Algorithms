#include <iostream>

using namespace std;

struct Node {
        int data;
        Node* next;
};



//==================================================================================================================
//                                          HELPER FUNCTIONS
//function for printing the linked list
void Print(Node* head){
        Node* temp= head;
        while (temp!=NULL){
                cout<<(temp->data)<<" ";
                temp= temp->next;

        }
        cout<<endl;


}

//function for inserting at the end
Node* InsertEnd(Node* head, int data){
        Node* temp= new Node;
        temp->data= data;
        temp->next=NULL;
        if (head==NULL){
                head= temp;
                return head;
        }
        Node* temp1= head;
        while (temp1->next!=NULL){
                temp1= temp1->next;
        }
        temp1->next= temp;
        return head;

}


//==================================================================================================================







//==================================================================================================================
//                                           MAIN PART
//function for reversing a list iteratively

Node* reverseLinkIter(Node* head){
        Node* temp= head;
        Node* prev= NULL;
        Node* folw;
        while (temp!=NULL){
                folw= temp->next;
                temp->next= prev;
                prev= temp;
                temp= folw;

        }
        head= prev;
        return head;

}

//function for the recursive part

void reverseLinkRec(Node* p, Node* &head){
        if (p->next==NULL){
                head= p;
                return;

        }
        reverseLinkRec(p->next, head);
        Node* q= p->next; 
        q->next= p;
        p->next= NULL;// this assignment is required for the last call stack or the last element in reversed list
        return;


}

//==================================================================================================================







//==================================================================================================================
//                                         DRIVER FUNCTION
int main(){
        //initially empty
        Node* head= NULL;
        head= InsertEnd(head,4);
        head= InsertEnd(head,5);
        head= InsertEnd(head,3);
        head= InsertEnd(head,2);
        head= InsertEnd(head,1);
        Print(head);
        cout<<endl<<"Reversed"<<endl;
        head= reverseLinkIter(head);
        Print(head);
        cout<<"Reversed using recursion, thus changes to original form"<<endl;
        reverseLinkRec(head, head);//one head for the initial pointer, one to store the value of the head variable
        Print(head);
        
        return 0;
}


//==================================================================================================================




//==================================================================================================================


//                               TIME AND SPACE COMPLEXITY ANALYSIS(asymptotic)
//Iterative case:
//      Time complexity: There is a single for loop which will run for n nodes, thus 
//                       time complexity is O(n)
//      Space complexity: There are 3 extra variables for any input, thus 
//                       space complexity is O(1), constant space

//Recursive case:
//      Time complexity: There will be 'n' function calls for 'n' nodes, thus
//                       time complexity is O(n)
//      Space complexity: In the base case, there will be total 'n' call stacks open at the same time, thus
//                       space complexity is O(n)


//==================================================================================================================