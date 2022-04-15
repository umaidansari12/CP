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
    int maxLevelSum(TreeNode* root) {
        if (root == NULL)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> r;
        while (!q.empty())
        {
            int size = q.size(), sum = 0;
            while (size--)
            {
                TreeNode* t = q.front();
                q.pop();
                sum += t->val;
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
            r.push_back(sum);
        }
        int mx = INT_MIN, ans = 0;
        for (int i = 0; i < r.size(); i++)
        {
            if (mx < r[i])
            {
                mx = r[i];
                ans = i;
            }
        }
        return ans + 1;


    }
}; p