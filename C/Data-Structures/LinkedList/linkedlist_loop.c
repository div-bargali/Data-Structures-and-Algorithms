#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

int detectLoop(struct ListNode *list1)
{
    struct ListNode *S = list1, *F = list1;
    while (S && F && F->next)
    {
        S = S->next;
        F = F->next->next;
        if (F == S)
            return 1;
    }
    return 0;
}

int main()
{
    struct ListNode *head = malloc(sizeof(struct ListNode));
    head->val = 5;
    struct ListNode *l1 = malloc(sizeof(struct ListNode));
    l1->val = 10;
    head->next = l1;
    struct ListNode *l2 = malloc(sizeof(struct ListNode));
    l2->val = 20;
    l1->next = l2;
    struct ListNode *l3 = malloc(sizeof(struct ListNode));
    l3->val = 30;
    l2->next = l3;
    struct ListNode *l4 = malloc(sizeof(struct ListNode));
    l4->val = 40;
    l3->next = l4;
    l4->next = l1;
    struct ListNode *l5 = malloc(sizeof(struct ListNode));
    l5->val = 50;

    //      5 -> 10-> 20  50
    //            ↑    |
    //            |    ↓
    //           40 <- 30

    if (detectLoop(head))
        printf("\n\nLoop is present in the linked list.\n\n");
    else
        printf("\n\nLoop is not present in the linked list\n\n");
    return 0;
}
