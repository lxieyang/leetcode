/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int target) {
        ListNode dummy(-1);
        ListNode * idx = &dummy;	idx->next = head;
        while(head){
            if(head->val != target){
                idx = idx->next;
                idx->val = head->val;
            }
            head = head->next;
        }
        idx->next = nullptr;
        return dummy.next;
    }
};

