/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a 
binary tree in which the depth of the two subtrees 
of every node never differ by more than 1.
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
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return isBalancedUntil(root, height);
    }

    bool isBalancedUntil(TreeNode * root, int & height) {
    	if(!root) {
    		height = 0;
    		return true;
    	}
    	int leftHeight = 0, rightHeight = 0;
    	bool leftIsBalanced = isBalancedUntil(root->left, leftHeight);
    	bool rightIsBalanced = isBalancedUntil(root->right, rightHeight);
    	height = max(leftHeight, rightHeight) + 1;
    	return (abs(leftHeight - rightHeight) <= 1 && leftIsBalanced && rightIsBalanced);
    }
};



