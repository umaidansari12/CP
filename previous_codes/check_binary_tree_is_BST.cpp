void solve(Node* root, vector<int> &r)
{
    if (root == NULL)
        return;
    solve(root->left, r);
    r.push_back(root->data);
    solve(root->right, r);
}
bool isBST(Node* root) {
    // Your code here
    vector<int> r;
    solve(root, r);
    for (int i = 0; i < r.size() - 1; i++)
        if (r[i] >= r[i + 1])
            return false;
    return true;
}

class Solution
{
public:
    bool inorder(Node* root, Node* &prev)
    {
        if (root)
        {
            if (!inorder(root->left, prev))
                return false;
            if (prev != NULL && root->data <= prev->data)
                return false;
            prev = root;
            if (!inorder(root->right, prev))
                return false;
        }
        return true;

    }
    bool isBST(Node* root)
    {
        // Your code here
        Node* prev = NULL;
        return inorder(root, prev);
    }
};

//Second solution uses the property that left->data <=current->data < right->data
class Solution {
public:
    bool solve(TreeNode* root, int mi, int mx)
    {
        if (root == NULL)
            return true;
        if ((mi != INT_MIN && root->val <= mi) || (mx != INT_MAX && root->val >= mx))
            return false;
        if (!solve(root->left, mi, root->val) || !solve(root->right, root->val, mx))
            return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        int mx = INT_MAX, mi = INT_MIN;
        return solve(root, mi, mx);

    }
};

class Solution {
public:
    bool solve(TreeNode * root, long long int mi, long long int mx)
    {
        if (root == NULL)
            return true;
        if ((mi != LLONG_MIN && root->val <= mi) || (mx != LLONG_MAX && root->val >= mx))
            return false;
        if (!solve(root->left, mi, root->val) || !solve(root->right, root->val, mx))
            return false;
        return true;
    }
    bool isValidBST(TreeNode * root) {
        long long int mx = LLONG_MAX, mi = LLONG_MIN;
        return solve(root, mi, mx);

    }
};

class Solution
{
public:
    bool solve(Node* root, long long int mi, long long int mx)
    {
        if (root == NULL)
            return true;
        if ((mi != LLONG_MIN && root->data <= mi) || (mx != LLONG_MAX && root->data >= mx))
            return false;
        if (!(solve(root->left, mi, root->data)) || !(solve(root->right, root->data, mx)))
            return false;
        return true;
    }
    bool isBST(Node* root)
    {
        // Your code here
        long long int mx = LLONG_MAX, mi = LLONG_MIN;
        return solve(root, mi, mx);
    }
};