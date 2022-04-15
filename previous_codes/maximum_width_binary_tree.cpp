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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int result = 1;
        while (!q.empty())
        {
            int size = q.size();
            int start = q.front().second;
            int end = q.back().second;
            result = max(result, end - start + 1);
            while (size--)
            {
                pair<TreeNode*, int> p = q.front();
                q.pop();
                int idx = p.second - start;
                if (p.first->left) q.push({p.first->left, 2 * idx + 1});
                if (p.first->right) q.push({p.first->right, 2 * idx + 2});
            }
        }
        return result;

    }
};
class Solution {
public:
    void preorder(TreeNode* root, map<int, int> &m, int level)
    {
        if (root == NULL)
            return ;
        m[level]++;
        preorder(root->left, m, level + 1);
        preorder(root->right, m, level + 1);
    }
    int widthOfBinaryTree(TreeNode* root) {
        int level = 0;
        map<int, int> m;
        preorder(root, m, level);
        queue<TreeNode*> q;
        q.push(root);
        int ans = INT_MIN, prev = INT_MAX;
        while (!q.empty())
        {
            int size = q.size();
            ans = max(ans, size);
            while (size--)
            {
                //if(q.front()->left)
                if (q.front() != NULL)
                {
                    q.push(q.front()->left);
                    //if(q.front()->right)
                    q.push(q.front()->right);
                }
                else
                {
                    q.push(NULL);
                    q.push(NULL);
                }
                q.pop();
            }
            // prev=min(ans,prev);

        }
        return ans;

    }
};
int getMaxWidth(Node* root)
{
    int ans = INT_MIN;
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        ans = max(ans, size);
        while (size--)
        {
            if (q.front()->left)
                q.push(q.front()->left);
            if (q.front()->right)
                q.push(q.front()->right);
            q.pop();
        }
    }
    return ans;

    // Your code here
}