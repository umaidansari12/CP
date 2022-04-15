class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (!root)
            return res;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            vector<int> r;
            while (size--)
            {
                r.push_back(q.front()->val);
                if (q.front()->left)
                    q.push(q.front()->left);
                if (q.front()->right)
                    q.push(q.front()->right);
                q.pop();
            }
            res.push_back(r);
        }
        reverse(res.begin(), res.end());
        return res;

    }
};