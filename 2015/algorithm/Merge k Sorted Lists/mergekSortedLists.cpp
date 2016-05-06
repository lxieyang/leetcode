/*

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

    ListNode * mergeTwo(ListNode * l1, ListNode * l2){
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode dummy(-1);
        ListNode * p = &dummy;
        for(; l1 && l2; p = p->next){
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

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;

        // multi pass
        deque<ListNode *> dq(lists.begin(), lists.end());
        while(dq.size() > 1){
            ListNode * first = dq.front(); dq.pop_front();
            ListNode * second = dq.front(); dq.pop_front();
            dq.push_back(mergeTwo(first,second));
        }

        return dq.front();

        // single pass will execeed the runtime
        /*
        ListNode * p = lists[0];
        for(int i = 1; i < (int)lists.size(); ++i){
            p = mergeTwo(p, lists[i]);
        }
        return p;
        */
    }
};

int main(){

    node_ptr l9 = new ListNode(9);
    node_ptr l8 = new ListNode(6);
    node_ptr l7 = new ListNode(3);
    l8->next = l9;
    l7->next = l8;

    node_ptr l6 = new ListNode(8);
    node_ptr l5 = new ListNode(5);
    node_ptr l4 = new ListNode(2);
    l5->next = l6;
    l4->next = l5;

    node_ptr l3 = new ListNode(7);
    node_ptr l2 = new ListNode(4);
    node_ptr l1 = new ListNode(1);
    l2->next = l3;
    l1->next = l2;

    Solution sol;

    vector<ListNode *> nodes{l1, l4, l7};
    printf("\nThe original lists are: \n");
    for(int i = 0; i < (int)nodes.size(); i++){
        auto x = nodes[i];
        auto tmp = x;
        while(tmp){cout << tmp->val << " "; tmp = tmp->next;} cout << "\n";
    }
    printf("\nThe merged list is given by:\n");
    auto tmp3 = sol.mergeKLists(nodes);
    while(tmp3){cout << tmp3->val << " "; tmp3 = tmp3->next;} cout << "\n\n";



    return 0;
}
