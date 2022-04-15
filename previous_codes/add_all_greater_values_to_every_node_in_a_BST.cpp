Node* solve(Node *node, int &total)
{
    if (node == NULL)
        return NULL;
    solve(node->right, total);
    total += node->data;
    node->data = total;
    solve(node->left, total);
    return node;
}
Node* modify(Node *root)
{
    // Your code here
    int total = 0;
    return solve(root, total);
}

void inorder(Node* root, vector<Node*>& r)
{
    if (root == NULL)
        return;
    inorder(root->left, r);
    r.push_back(root);
    inorder(root->right, r);
}
Node* modify(Node *root)
{
    vector<Node*> r;
    inorder(root, r);
    // reverse(r.begin(),r.end());
    int total = 0;
    for (int i = r.size() - 1; i >= 0; i--)
    {
        total += (r[i]->data);
        r[i]->data = total;
    }

    return root;
}