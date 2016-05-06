/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
click to show hints.

Hints:
If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.
*/


#include "../global.h"


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root)	return;
        stack<TreeNode *> s;
        s.push(root);

        while(!s.empty()) {
        	TreeNode * p = s.top();
        	s.pop();

        	if(p->right)
        		s.push(p->right);
        	if(p->left)
        		s.push(p->left);

        	p->left = nullptr;
        	if(!s.empty()) {
        		p->right = s.top();
        	}
        }
    }
};






