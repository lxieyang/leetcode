/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].
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
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return values;
    }
    void preorder(TreeNode * root) {
    	if(!root)
    		return;
    	values.push_back(root->val);
    	preorder(root->left);
    	preorder(root->right);
    }
private:
	vector<int> values;
};

class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
    	vector<int> values;
    	vector<TreeNode *> nodes;
    	if(root) {
    		nodes.push_back(root);
    	}
    	while(nodes.size() > 0) {
    		TreeNode * temp = nodes.back();
    		values.push_back(temp->val);
    		nodes.pop_back();
    		if(temp->right)
    			nodes.push_back(temp->right);
    		if(temp->left)
    			nodes.push_back(temp->left);
    	}
    	return values;
    }
};

