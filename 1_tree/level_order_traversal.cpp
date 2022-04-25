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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> lvls;
        if (!root)
            return lvls;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int _size = q.size();
            vector<int> lvl;
            while (_size--) {
                TreeNode* curr = q.front();
                q.pop();

                lvl.push_back(curr->val);

                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            lvls.push_back(lvl);
        }

        return lvls;
    }
};

vector<int> getLevelOrder(TreeNode<int> *root)
{
    //  Write your code here.
    vector<int> r;
    if (!root)
        return r;
    queue<TreeNode<int>*> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode<int> *cur = q.front();
        q.pop();
        r.push_back(cur->val);
        if (cur->left)
            q.push(cur->left);
        if (cur->right)
            q.push(cur->right);
    }
    return r;

}