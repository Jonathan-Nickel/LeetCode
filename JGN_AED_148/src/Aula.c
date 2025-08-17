/*
Jonathan Goulart Nickel - 23200579
Given the head of a linked list, return the list after sorting it in ascending order.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    return 0;
}

/*
*/
struct ListNode {
    int val;
    struct ListNode *next;
};

/*
*/
struct ListNode* merge(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode ahead;
    struct ListNode *tail = &ahead;
    ahead.next = NULL;

    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return ahead.next;
};

/*
*/
struct ListNode* sortList(struct ListNode* head) {
    if (!head || !head->next){
        return head;
    }

    struct ListNode *primeiro = head, *proximo = head->next;
    while (proximo && proximo->next) {
        primeiro = primeiro->next;
        proximo = proximo->next->next;
    }
    struct ListNode *mid = primeiro->next;
    primeiro->next = NULL;

    struct ListNode *left = sortList(head);
    struct ListNode *right = sortList(mid);

    return merge(left, right);
}


