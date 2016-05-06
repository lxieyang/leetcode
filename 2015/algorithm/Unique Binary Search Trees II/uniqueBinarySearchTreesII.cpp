/*
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
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
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) 	return vector<TreeNode*>();
        return generate(1, n);
    }

    vector<TreeNode *> generate(int start, int end) {
    	vector<TreeNode *> subTree;
    	if(start > end) {
    		subTree.push_back(nullptr);
    		return subTree;
    	} 
    	for(int k = start; k <= end; k++) {
    		vector<TreeNode *> leftSubTree = generate(start, k - 1);
    		vector<TreeNode *> rightSubTree = generate(k + 1, end);
    		for(auto i : leftSubTree)
    			for(auto j : rightSubTree) {
    				TreeNode * node = new TreeNode(k);
    				node->left = i;
    				node->right = j;
    				subTree.push_back(node);
    			}
    	}
    	return subTree;
    }
};




