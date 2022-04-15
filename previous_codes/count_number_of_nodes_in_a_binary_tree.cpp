/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	int countNodes(TreeNode* root) {
		if (root == NULL)
			return 0;
		return countNodes(root->left) + countNodes(root->right) + 1;

	}
};

class Solution {
public:
	void preorder(TreeNode* root, int &count)
	{
		if (root == NULL)
			return ;
		count++;
		preorder(root->left, count);
		preorder(root->right, count);
	}
	int countNodes(TreeNode* root) {
		if (root == NULL)
			return 0;
		int count = 0;
		preorder(root, count);
		return count;

	}
};