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
    void preorder(TreeNode* root, int level, map<int, int> &m)
    {
        if (root == NULL)
            return ;
        if (m[level] == 0)
            m[level] = root->val;
        else
            m[level] += root->val;
        preorder(root->left, level + 1, m);
        preorder(root->right, level + 1, m);
    }
    int maxLevelSum(TreeNode* root) {
        map<int, int> m;
        int level = 0;
        preorder(root, level, m);
        int ans = INT_MIN, mx = INT_MIN;
        for (auto i : m)
        {
            if (mx < i.second)
            {
                mx = i.second;
                ans = i.first;
            }
        }

        return ans + 1;

    }
};

int maxLevelSum(Node* root) {
    // Your code here
    int mx = INT_MIN;
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size(), sum = 0;
        while (size--)
        {
            sum += (q.front()->data);
            if (q.front()->left)
                q.push(q.front()->left);
            if (q.front()->right)
                q.push(q.front()->right);
            q.pop();
        }
        mx = max(sum, mx);
    }
    return mx;
}
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