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
    void inorder(TreeNode* root, vector<int>&r)
    {
        if (root == NULL)
            return;
        inorder(root->left, r);
        r.push_back(root->val);
        inorder(root->right, r);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> r;
        inorder(root, r);
        int i = 0, j = r.size() - 1;
        while (i < j)
        {
            int sum = r[i] + r[j];
            if (sum == k)
                return true;
            else if (sum < k)
                i++;
            else
                j--;
        }
        return false;
    }
};