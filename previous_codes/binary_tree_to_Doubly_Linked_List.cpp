// This function should return head to the DLL

//The idea is to do inorder traversal of the binary tree. While doing inorder traversal,
//keep track of the previously visited node in a variable say prev. For every visited node,
// make it next of prev and previous of this node as prev.
void in(Node* root, vector<Node*>&r)
{
    if (root == NULL)
        return;
    in(root->left, r);
    r.push_back(root);
    in(root->right, r);

}
Node * bToDLL(Node *root)
{
    // your code here
    vector<Node*> r;
    in(root, r);
    for (int i = 0; i < r.size(); i++)
    {
        Node* tmp = r[i];
        if (i - 1 < 0)
            tmp->left = NULL;
        else
            tmp->left = r[i - 1];
        if (i + 1 == r.size())
            tmp->right = NULL;
        else
            tmp->right = r[i + 1];
    }
    return r[0];
}


void bToDLLUtil(Node *root, Node **head_ref)
{
    // Base cases
    if (root == NULL)
        return;

    // Recursively convert right subtree
    bToDLLUtil(root->right, head_ref);

    // insert root into DLL
    root->right = *head_ref;

    // Change left pointer of previous head
    if (*head_ref != NULL)
        (*head_ref)->left = root;

    // Change head of Doubly linked list
    *head_ref = root;

    // Recursively convert left subtree
    bToDLLUtil(root->left, head_ref);
}

Node* bToDLL(Node *root)
{
    Node *head = NULL;
    bToDLLUtil(root, &head);
    return head;

}

