/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > values;
        queue<TreeNode *> current, next;
        bool leftToRight = true;
        if(!root)
        	return values;
        else
        	current.push(root);

        while(!current.empty()) {
        	vector<int> level;
        	while(!current.empty()) {
        		TreeNode * temp = current.front();
        		current.pop();
        		level.push_back(temp->val);
        		if(temp->left)	next.push(temp->left);
        		if(temp->right) next.push(temp->right);
        	}
        	if(!leftToRight) 
        		reverse(level.begin(), level.end());
        	values.push_back(level);
        	leftToRight = !leftToRight;
        	swap(current, next);
        }
        return values;
    }
};

