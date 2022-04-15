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
	TreeNode* searchBST(TreeNode* root, int val) {
		while (root != NULL && root->val != val)
		{
			root = (val < root->val) ? root->left : root->right;
		}
		return root;
	}
};

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
	TreeNode* searchBST(TreeNode* root, int val) {
		TreeNode* node = new TreeNode();
		if (root)
		{
			if (root->val == val)
				node = root;
			else if (root->val < val)
				node = searchBST(root->left, val);
			else
				node = searchBST(root->right, val);
		}

		return node;

	}
};