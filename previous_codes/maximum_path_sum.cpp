class Solution {
public:
    int solve(TreeNode* root, int &res)
    {
        if (root == NULL)
            return 0;
        int l = solve(root->left, res);
        int r = solve(root->right, res);

        int m = max(max(l, r) + root->val, root->val);
        int ms = max(m, l + r + root->val);
        res = max(ms, res);
        return m;
    }
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        solve(root, res);
        return res;

    }
};