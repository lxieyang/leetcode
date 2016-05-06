/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
*/


#include "../global.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

typedef ListNode * node_ptr;

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k < 2)   return head;
        ListNode dummy(-1);
        dummy.next = head;

        for(ListNode * prev = &dummy, * end = head; end; end =prev->next){
            for(int i = 1; i < k && end; i++){
                end = end->next;
            }
            if(end == nullptr) break;

            prev = reverse(prev, prev->next, end);
        }
        return dummy.next;
    }

    ListNode * reverse(ListNode * prev, ListNode * begin, ListNode * end){
        ListNode * end_next = end->next;
        for(ListNode * p = begin, * curr = p->next, * next = curr->next;
            curr != end_next;
            p = curr, curr = next, next = next ? next->next : nullptr){
                curr->next = p;
        }
        begin->next = end_next;
        prev->next = end;
        return begin;
    }
};

int main(){
    // node_ptr l4 = new ListNode(8);
    node_ptr l3 = new ListNode(7);
    node_ptr l2 = new ListNode(4);
    node_ptr l1 = new ListNode(1);
    // l3->next = l4;
    l2->next = l3;
    l1->next = l2;

    int seed = 3;

    printf("The original list is:\n");
    auto tmp = l1;
    while(tmp){cout << tmp->val << " "; tmp = tmp->next;} cout << "\n";

    Solution sol;
    printf("The modified list is:\n");
    auto tmp2 = sol.reverseKGroup(l1, seed);
    while(tmp2){cout << tmp2->val << " "; tmp2 = tmp2->next;} cout << "\n";

    return 0;
}
