/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
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
    void recoverTree(TreeNode* root) {
        inorder(root);
        for(auto x : nodes)
        	cout << x->val << " ";
        cout << endl;
        int first = 0, second = nodes.size() - 1;
        for(int i = 0; i < (int)nodes.size() - 1; i++) {
        	if(nodes[i] > nodes[i + 1]) {
        		first = i; break;
        	}
        }
        for(int j = nodes.size() - 1; j > 0; j--) {
        	if(nodes[j] < nodes[j - 1]) {
        		second = j; break;
        	}
        }
        cout << first << " " << second << endl;
        swap(nodes[first]->val, nodes[second]->val);
        for(auto x : nodes)
        	cout << x->val << " ";
        cout << endl;
    }

    void inorder(TreeNode * root) {
    	if(!root)
    		return;
    	inorder(root->left);
    	nodes.push_back(root);
    	inorder(root->right);
    }
private:
	vector<TreeNode *> nodes;
};

int main() {
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(3);
	b.left = &c;
	b.right = &a;
	Solution sol;
	sol.recoverTree(&b);
	cout << a.val << endl;
	cout << b.val << endl;
	cout << c.val << endl;

	return 0;
}
