class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        int lvl = 0;
        q.push(make_pair(root, lvl));
        map<int, vector<int>> r;
        while (!q.empty())
        {
            TreeNode* t = q.front().first;
            lvl = q.front().second;
            r[lvl].push_back(t->val);
            q.pop();
            if (t->left)
                q.push(make_pair(t->left, lvl + 1));
            if (t->right)
                q.push(make_pair(t->left, lvl + 1));
        }
        auto i = r.begin();
        vector<vector<int>> m(lvl, vector<int>());
        while (i != r.end())
        {
            //vector<int> s;
            for (int j = 0; j < i->second.size(); i++)
            {
                m[i->first].push_back(i->second[j]);// s.push_back(i->second[j]);
            }
            //m.push_back(s);
            i++;
        }
        return m;

    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> r;
        if (root == NULL)
            return r;
        queue<TreeNode*> q;
        //int lvl=0;
        q.push(root);
        q.push(NULL);

        vector<int> m;
        while (!q.empty())
        {
            TreeNode* t = q.front();
            q.pop();
            if (t == NULL)
            {
                //q.push(NULL);
                r.push_back(m);
                m.clear();
                //lvl++;
                if (q.size() > 0)
                    q.push(NULL);

            }
            else
            {
                m.push_back(t->val);
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
        }
        return r;

    }
};