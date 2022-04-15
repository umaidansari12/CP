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
    void inorder(TreeNode* root, vector<TreeNode*>& r)
    {
        if (root == NULL)
            return;
        inorder(root->left, r);
        r.push_back(root);
        inorder(root->right, r);
    }
    TreeNode* bstToGst(TreeNode* root) {
        vector<TreeNode*> r;
        inorder(root, r);
        // reverse(r.begin(),r.end());
        int total = 0;
        for (int i = r.size() - 1; i >= 0; i--)
        {
            total += (r[i]->val);
            r[i]->val = total;
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
    TreeNode* solve(TreeNode* root, int &total)
    {
        if (root == NULL)
            return NULL;
        solve(root->right, total);
        total += root->val;
        root->val = total;
        solve(root->left, total);
        return root;
    }
    TreeNode* bstToGst(TreeNode* root) {
        int total = 0;
        return solve(root, total);


    }
};