/*
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
        	return true;
        if(!p || !q)
        	return false;
        return p->val == q->val &&
        		isSameTree(p->left, q->left) &&
        		isSameTree(p->right, q->right);
    }
};

class Solution2 {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode *> nodes;
        nodes.push(p);
        nodes.push(q);
        while(!nodes.empty()) {
        	p = nodes.top(); nodes.pop();
        	q = nodes.top(); nodes.pop();
        	if(!p && !q)
        		continue;
        	if(!p || !q)
        		return false;
        	if(p->val != q->val)
        		return false;

        	nodes.push(p->left);
        	nodes.push(q->left);
        	nodes.push(p->right);
        	nodes.push(q->right);
        }
        return true;
    }
};




