class Solution
{
public:
    void inorder(Node* root, vector<int> &r)
    {
        if (root == NULL)
            return ;
        inorder(root->left, r);
        r.push_back(root->data);
        inorder(root->right, r);

    }
    int minDiff(Node *root, int K)
    {
        //Your code here
        vector<int> r;
        inorder(root, r);
        int ans = INT_MAX;
        for (int i = 0; i < r.size(); i++)
            ans = min(ans, abs(r[i] - K));
        //*min_element(r.begin(),r.end());
        return ans;
    }
};

class Solution
{
public:
    void solve(Node* root, int k, int& m)
    {
        if (root == NULL)
            return ;
        m = min(m, abs(root->data - k));
        if (k < root->data)
            solve(root->left, k, m);
        else
            solve(root->right, k, m);
    }
    int minDiff(Node *root, int K)
    {
        //Your code here
        int m = INT_MAX;
        solve(root, K, m);
        return m;
    }
};