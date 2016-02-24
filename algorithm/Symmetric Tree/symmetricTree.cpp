/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
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
    bool isSymmetric(TreeNode* root) {
        if(!root)
        	return true;
        return isSymmetric(root->left, root->right);
    }

    bool isSymmetric(TreeNode * p, TreeNode * q) {
    	if(!p && !q) 
    		return true;
    	if(!p || !q)
    		return false;
    	return p->val == q->val &&
    			isSymmetric(p->left, q->right) &&
    			isSymmetric(p->right, q->left);
    }
};










