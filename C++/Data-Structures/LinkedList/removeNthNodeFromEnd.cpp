#include<bits/stdc++.h>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *node = head;
        ListNode *nodeToRemove = head;
        int count = 1;
        while(node->next!= NULL){
            if(count <=n){
                node = node->next;
            }
            else{
                node = node->next;
                nodeToRemove = nodeToRemove->next;
            }
            count ++;
        }
        if(n == count){
            head = head->next;
        }
        else if(nodeToRemove->next->next!= NULL){
            nodeToRemove->next = nodeToRemove->next->next;
        }
        else{
            nodeToRemove->next = NULL;
        }
        return head;
}
