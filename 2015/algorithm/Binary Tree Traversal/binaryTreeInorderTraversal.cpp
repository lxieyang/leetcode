/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> inorderTraversal(TreeNode* root) {
     	inorder(root);
        return values;
    }
    void inorder(TreeNode * root) {
    	if(!root)
    		return;
    	inorder(root->left);
    	values.push_back(root->val);
    	inorder(root->right);
    }
private:
	vector<int> values;
};


class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
    	vector<int> values;
    	stack<TreeNode *> nodeStack;
    	TreeNode * p = root;
    	while(!nodeStack.empty() || p) {
    		if(p) {
    			nodeStack.push(p);
    			p = p->left;
    		} else {
    			p = nodeStack.top(); nodeStack.pop();
    			values.push_back(p->val);
    			p = p->right;
    		}
    	}
    	return values;
    }
};



