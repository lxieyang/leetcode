/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(begin(inorder), end(inorder), begin(postorder), end(postorder));
    }

    template<typename BidiIt>
    TreeNode * buildTree(BidiIt in_first, BidiIt in_last, BidiIt post_first, BidiIt post_last) {
    	if(in_first == in_last) 
    		return nullptr;
    	if(post_first == post_last)
    		return nullptr;

    	TreeNode * root = new TreeNode(*prev(post_last));
    	auto inRootPos = find(in_first, in_last, *prev(post_last));
    	auto leftSize = distance(in_first, inRootPos);
    	auto postLeftLast = next(post_first, leftSize);

    	root->left = buildTree(in_first, inRootPos, post_first, postLeftLast);
    	root->right = buildTree(next(inRootPos), in_last, postLeftLast, prev(post_last));

    	return root;
    }
};



