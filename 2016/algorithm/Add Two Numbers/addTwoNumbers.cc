/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    Output: 7 -> 0 -> 8
*/


#include <iostream>
#include <vector>
#include <string>

using namespace std;


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *      int val;
 *      ListNode *next;
 *      ListNode(int x) : val(x), next(NULL) {}
 * };
 */


struct ListNode {
    int val;
    ListNode * next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Thoughts:
        //      maintain carry bit
        
        int carry = 0;
        int a, b;
        ListNode head(-1);
        ListNode * temp = &head;
        while(l1 || l2 || carry != 0) {
            a = (l1) ? getValAndIncrementPointer(l1) : 0;
            b = (l2) ? getValAndIncrementPointer(l2) : 0;
            int realSum = a + b + carry;
            carry = (realSum) / 10;
            int val = (realSum) % 10;

            temp->next = new ListNode(val);
            temp = temp->next;
        }

        return head.next;
    }

private:
    int getValAndIncrementPointer(ListNode * &node) {
        int val = node->val;
        // cout << "val is: " << val << "\n";
        node = node->next;
        return val;
    }
};


void printList(ListNode * head) {
    cout << "Printing List:\n";
    int count = 0;
    while(head) {
        cout << head->val << " - ";
        head = head->next;
        ++count;
    }
    cout << "\n";
    cout << "Digits: " << count << "\n";
}


int main() {
    ListNode a(2);
    ListNode b(4);
    ListNode c(3);

    ListNode d(5);
    ListNode e(6);
    ListNode f(4);
    
    ListNode h(9);
    ListNode i(9);
    ListNode j(9);
    ListNode k(9);

    a.next = &b;
    b.next = &c;
    d.next = &e;
    e.next = &f;
    h.next = &i;
    i.next = &j;
    j.next = &k;
    
    cout << "Original lists:\n";
    printList(&a);
    printList(&d);

    Solution sol;
    ListNode * ret = sol.addTwoNumbers(&a, &h);
    printList(ret);

    return 0;

}


