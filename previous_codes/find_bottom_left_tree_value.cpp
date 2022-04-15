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
    int findBottomLeftValue(TreeNode* root) {
        if (!root)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> r;
        while (!q.empty())
        {
            int size = q.size();
            vector<int> re;
            while (size--)
            {
                re.push_back(q.front()->val);
                if (q.front()->left)
                {
                    q.push(q.front()->left);
                }
                if (q.front()->right)
                {
                    q.push(q.front()->right);
                }
                q.pop();
            }
            r.push_back(re);
        }
        return r[r.size() - 1][0];
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

    void dfs(TreeNode* root, int depth, int &maxDepth, int &leftVal)
    {
        if (!root)
            return;
        dfs(root->left, depth + 1, maxDepth, leftVal);
        dfs(root->right, depth + 1, maxDepth, leftVal);
        if (depth > maxDepth)
        {
            maxDepth = depth;
            leftVal = root->val;
        }

    }
    int findBottomLeftValue(TreeNode* root) {
        int leftVal = root->val, maxDepth = 0;
        dfs(root, 0, maxDepth, leftVal);
        return leftVal;
    }
};