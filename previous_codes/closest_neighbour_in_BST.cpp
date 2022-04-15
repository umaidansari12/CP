void inorder(Node* root, vector<int> &r)
{
    if (root == NULL)
        return;
    inorder(root->left, r);
    r.push_back(root->key);
    inorder(root->right, r);
}
int findMaxForN(Node* root, int N)
{
    vector<int> r;
    inorder(root, r);
    int ans = 0;
    for (int i = 0; i < r.size(); i++)
    {
        if (r[i] > N)
            break;
        ans = r[i];
    }
    return ans;
}

int findMaxForN(Node* root, int N)
{
    if (root == NULL)
        return -1;
    if (root->key == N)
        return N;
    else if (root->key < N)
    {
        int k = findMaxForN(root->right, N);
        if (k == -1)
            return root->key;
        else
            return k;
    }
    else if (root->key > N)
        return findMaxForN(root->left, N);
}