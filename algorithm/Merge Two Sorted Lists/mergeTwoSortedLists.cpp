/*
Merge two sorted linked lists and return it as a new list.
The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // boundary conditions:
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode dummy(-1);
        ListNode * p = &dummy;
        for(; l1 && l2; p = p->next){
            // cout << p->val << endl;
            if(l1->val > l2->val){
                p->next = l2; l2 = l2->next;
            }
            else{
                p->next = l1; l1 = l1->next;
            }
        }
        p->next = l1 ? l1 : l2;
        return dummy.next;
    }
};


int main(){
    Solution sol;

    node_ptr l6 = new ListNode(6);
    node_ptr l5 = new ListNode(4);
    node_ptr l4 = new ListNode(2);
    l5->next = l6;
    l4->next = l5;

    node_ptr l3 = new ListNode(5);
    node_ptr l2 = new ListNode(3);
    node_ptr l1 = new ListNode(1);
    l2->next = l3;
    l1->next = l2;

    printf("\nThe original lists are: \n");
    printf("List 1: ");
    auto tmp = l1;
    while(tmp){cout << tmp->val << " "; tmp = tmp->next;} cout << "\n";
    printf("List 2: ");
    auto tmp2 = l4;
    while(tmp2){cout << tmp2->val << " "; tmp2 = tmp2->next;} cout << "\n";

    printf("\nThe merged list is given by:\n");
    auto tmp3 = sol.mergeTwoLists(l1, l4);
    while(tmp3){cout << tmp3->val << " "; tmp3 = tmp3->next;} cout << "\n\n";



    return 0;
}
