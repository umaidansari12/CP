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
	void preorder(TreeNode* root, vector<TreeNode*>& r)
	{
		if (root == NULL)
			return ;
		r.push_back(root);
		preorder(root->left, r);
		preorder(root->right, r);
	}
	void flatten(TreeNode* root) {
		vector<TreeNode*> r;
		if (root == NULL)
			return;
		preorder(root, r);
		for (int i = 0; i < r.size() - 1; i++)
		{
			TreeNode* t = r[i];
			t->left = NULL;
			t->right = r[i + 1];
		}
		//return root;
	}
};

class Solution {
public:
	void flatten(TreeNode *root) {

		if (!root) return;

		TreeNode* node = root;
		while (node) {

			// Attatches the right sub-tree to the rightmost leaf of the left sub-tree:
			if (node->left) {

				TreeNode *rightMost = node->left;
				while (rightMost->right) {

					rightMost = rightMost->right;
				}
				rightMost->right = node->right;

				// Makes the left sub-tree to the right sub-tree:
				node->right = node->left;
				node->left = NULL;
			}

			// Flatten the rest of the tree:
			node = node->right;
		}
	}
};


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::flatten(TreeNode* A)
{
	if (A == NULL)
		return NULL;
	TreeNode *node = A;
	while (node != NULL)
	{
		if (node->left != NULL)
		{
			TreeNode *rtmost = node->left;
			while (rtmost->right != NULL)
				rtmost = rtmost->right;
			rtmost->right = node->right;
			node->right = node->left;
			node->left = NULL;
		}
		node = node->right;
	}
	return A;
}

