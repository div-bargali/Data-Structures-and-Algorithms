#include<bits/stdc++.h>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *node1 = head;
        ListNode *node2 = head->next;
        
        head = head->next;
        while(1){
            node1->next = node2->next;
            node2->next = node1;
            if(node1->next!= NULL)
                node1 = node1->next;
            else
                break;
            if(node1->next != NULL){
                ListNode *temp = node1;
                node2 = node2->next;
                node2->next = temp->next;
                node2 = node2->next;
            }
            else
                break;
            
        }
        return head;
    }