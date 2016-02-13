/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Solution:
// Create two pointers p, q pointing at the head. Let q moves along the linked list for n steps.
// Then move p and q together. Delete p->next

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

typedef ListNode * node_ptr;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(-1); dummy.next = head;
        ListNode * p = &dummy, * q = &dummy;

        // first move q
        for(int i = 0; i < n; ++i)  q = q->next;

        // move p & q together
        while(q->next){
            p = p->next;    q = q->next;
        }

        ListNode * tmp = p->next;
        p->next = tmp->next;
        delete tmp;
        return dummy.next;
    }
};


int main(){
    node_ptr l5 = new ListNode(5);
    node_ptr l4 = new ListNode(4);
    node_ptr l3 = new ListNode(3);
    node_ptr l2 = new ListNode(2);
    node_ptr l1 = new ListNode(1);
    l4->next = l5;
    l3->next = l4;
    l2->next = l3;
    l1->next = l2;

    Solution sol;
    int TOBEDELETED = 2;
    printf("The original list is given by:\n");
    node_ptr tmp = l1;
    while(tmp){
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    printf("\n");

    printf("The modified list is given by: \n");
    node_ptr tmp2 = sol.removeNthFromEnd(l1, TOBEDELETED);
    while(tmp2){
        cout << tmp2->val << " ";
        tmp2 = tmp2->next;
    }
    printf("\n");

    return 0;
}
