/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 #include "../global.h"

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

typedef ListNode * node_ptr;

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr)    return head;
        ListNode dummy(-1);
        dummy.next = head;

        for(ListNode * prev = &dummy, * curr = prev->next, * next = curr->next;
            next;
            prev = curr, curr = curr->next, next = curr ? curr->next : nullptr){
                prev->next = next;
                curr->next = next->next;
                next->next = curr;
        }
        return dummy.next;
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

    printf("The original list is:\n");
    auto tmp = l1;
    while(tmp){cout << tmp->val << " "; tmp = tmp->next;} cout << "\n";

    Solution sol;
    printf("The modified list is:\n");
    auto tmp2 = sol.swapPairs(l1);
    while(tmp2){cout << tmp2->val << " "; tmp2 = tmp2->next;} cout << "\n";


    return 0;
}
