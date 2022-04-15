vector<int> findSpiral(Node *root)
{
    //Your code here
    vector<int> r;
    if (root == NULL)
        return r;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    vector<vector<int>> re;
    while (!q.empty())
    {
        Node* t = q.front();
        q.pop();
        if (t == NULL)
        {
            if (q.size() > 0)
            {
                q.push(NULL);
            }
            re.push_back(r);
            r.resize(0);
        }
        else
        {
            r.push_back(t->data);
            if (t->left)
                q.push(t->left);
            if (t->right)
                q.push(t->right);
        }
    }
    r.resize(0);
    for (int i = 0; i < re.size(); i++)
    {
        if (i % 2 == 0)
        {
            for (int j = re[i].size() - 1; j >= 0; j--)
            {
                r.push_back(re[i][j]);
            }
        }
        else
        {
            for (int j = 0; j < re[i].size(); j++)
            {
                r.push_back(re[i][j]);
            }
        }

    }
    return r;
}


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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL)
            return res;

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty())
        {
            int size = q.size();
            vector<int> r;
            for (int i = 0; i < size; i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                if (curr != NULL)
                    r.push_back(curr->val);
                if (curr->left != NULL)
                    q.push(curr->left);
                if (curr->right != NULL)
                    q.push(curr->right);
            }
            if (level % 2)
            {
                reverse(r.begin(), r.end());
                res.push_back(r);
            }
            else
            {
                res.push_back(r);
            }
            level++;
        }
        return res;
    }
};
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> r;
        if (root == NULL)
            return r;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> re;
        while (!q.empty())
        {
            TreeNode* t = q.front();
            q.pop();
            if (t == NULL)
            {
                if (q.size() > 0)
                    q.push(NULL);
                r.push_back(re);
                re.clear();
            }
            else
            {
                re.push_back(t->val);
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }

        }
        for (int i = 0; i < r.size(); i++)
        {
            if (i % 2 != 0)
                reverse(r[i].begin(), r[i].end());
        }
        return r;
    }
};