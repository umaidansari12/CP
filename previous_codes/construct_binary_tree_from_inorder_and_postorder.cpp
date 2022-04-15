Node* solve(int in[], int post[], int s, int e, int &pi)
{
    if (s > e)
        return NULL;
    Node* root = new Node(post[pi]);
    pi--;
    if (s == e)
        return root;
    int i;
    for (i = s; i <= e; i++)
        if (in[i] == root->data)
            break;
    if (i <= e)
    {
        root->right = solve(in, post, i + 1, e, pi);
        root->left = solve(in, post, s, i - 1, pi);
    }
    return root;
}
Node *buildTree(int in[], int post[], int n) {
    // Your code here
    int postindex = n - 1;
    return solve(in, post, 0, n - 1, postindex);
}
