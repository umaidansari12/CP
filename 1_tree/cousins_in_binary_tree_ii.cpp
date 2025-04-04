#include <bits/stdc++.h>

using namespace std;

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
	void dfs_level_sum(TreeNode* root, int lvl, unordered_map<int, int> &lvl_sum) {
		if (!root)
			return;
		lvl_sum[lvl] += root->val;
		dfs_level_sum(root->left, lvl + 1, lvl_sum);
		dfs_level_sum(root->right, lvl + 1, lvl_sum);
	}
	void dfs(TreeNode* root, int lvl, int sibling, unordered_map<int, int> &lvl_sum) {
		if (!root)
			return;
		root->val = lvl_sum[lvl] - sibling - root->val;
		int left_child = 0;
		int right_child = 0;
		if (root->left)
			left_child = root->left->val;
		if (root->right)
			right_child = root->right->val;
		dfs(root->left, lvl + 1, right_child, lvl_sum);
		dfs(root->right, lvl + 1, left_child, lvl_sum);
	}
	TreeNode* replaceValueInTree(TreeNode* root) {
		unordered_map<int, int> lvl_sum;
		// precompute sum
		// every node's cousin is lvl_sum - current node value - it's sibling
		dfs_level_sum(root, 0, lvl_sum);
		dfs(root, 0, 0, lvl_sum);
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
	TreeNode* replaceValueInTree(TreeNode* root) {
		if (!root)
			return root;
		root->val = 0;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			vector<TreeNode*> buf;
			int _size = q.size(), sum = 0;
			while (_size--) {
				TreeNode* node = q.front();
				q.pop();
				buf.push_back(node);
				if (node->left) {
					q.push(node->left);
					sum += node->left->val;
				}
				if (node->right) {
					q.push(node->right);
					sum += node->right->val;
				}
			}
			for (auto node : buf) {
				int t = sum;
				if (node->left)
					t -= node->left->val;
				if (node->right)
					t -= node->right->val;
				if (node->left)
					node->left->val = t;
				if (node->right)
					node->right->val = t;
			}
		}
		return root;
	}
};
Console



int main() {

	return 0;
}