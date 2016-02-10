/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

#include <iostream>

using namespace std;

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

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int x = 0, y = 0, carry = 0, sum = 0;
        ListNode * prev = nullptr;
        ListNode * head = nullptr;
        while(l1 || l2){
            x = getCurrentValueAndMoveToTheNext(l1);
            y = getCurrentValueAndMoveToTheNext(l2);
            // cout << x << " + " << y << "\n";
            sum = x + y + carry;
            carry = sum / 10;
            ListNode * temp = new ListNode(sum % 10);
            if(prev){
                prev->next = temp;
                prev = temp;
            }
            else{
                head = temp;
                prev = temp;
            }
        }
        if(carry > 0){
            ListNode * tail = new ListNode(carry % 10);
            prev->next = tail;
        }
        return head;
    }
private:
    int getCurrentValueAndMoveToTheNext(ListNode * &node){
        int val = 0;
        if(node){
            val = node->val;
            node = node->next;
        }
        return val;
    }
};

int main(){
    ListNode l6(4);
    ListNode l5(6);
    ListNode l4(5);
    l4.next = &l5;
    l5.next = &l6;

    ListNode l3(3);
    ListNode l2(4);
    ListNode l1(2);
    l1.next = &l2;
    l2.next = &l3;

    Solution sol;
    ListNode * ret = sol.addTwoNumbers(&l1, &l4);
    while(ret){
        cout << ret->val << " ";
        ret = ret->next;
    }
    cout << endl;

}
