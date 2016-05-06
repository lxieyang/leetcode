/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
        	return NULL;
        TreeNode * temp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(temp);
        return root;
    }
};



#include <queue>
class Solution2 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)	return NULL;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
        	TreeNode * node = q.front(); 
        	q.pop();
        	TreeNode * temp = node->left;
        	node->left = node->right;
        	node->right = temp;
        	if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        return root;
    }
};