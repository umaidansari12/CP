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
    bool solve(TreeNode* root, long long int mi, long long int mx)
    {
        if (root == NULL)
            return true;
        if ((mi != LLONG_MIN && root->val <= mi) || (mx != LLONG_MAX && root->val >= mx))
            return false;
        if (!solve(root->left, mi, root->val) || !solve(root->right, root->val, mx))
            return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        long long int mx = LLONG_MAX, mi = LLONG_MIN;
        return solve(root, mi, mx);

    }
};