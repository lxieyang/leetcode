/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, INT_MIN, INT_MAX);
    }

    bool isValidBST(TreeNode * root, int lower, int upper) {
    	if(root == nullptr)	
    		return true;
    	return root->val > lower && root->val < upper
    		&& isValidBST(root->left, lower, root->val)
    		&& isValidBST(root->right, root->val, upper);
    }
};

class Solution2 {
public:
	bool isValidBST(TreeNode * root) {
		inorder(root);
		return is_sorted(values.begin(), values.end(), cmp());
	}
	void inorder(TreeNode * root) {
    	if(!root)
    		return;
    	inorder(root->left);
    	values.push_back(root->val);
    	inorder(root->right);
    }
private:
	struct cmp {
		bool operator()(const int & first, const int & second) {
			return first <= second;
		}
	};
	vector<int> values;
};



