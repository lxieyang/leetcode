#include <iostream>
using namespace std;

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
    int maxDepth(TreeNode* root) {
    	if(!root)
    		return 0;
    	if(!root->left && !root->right)
    		return 1;
    	int left = INT_MAX, right = INT_MAX;
    	if(root->left)
    		left = 1 + minDepth(root->left);
    	if(root->right)
    		right = 1 + minDepth(root->right);

    	return left < right ? left : right;  
    }
};

