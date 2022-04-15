int height(Node* root)
{
    if (root == NULL)
        return 0;
    int left = height(root->left);
    int right = height(root->right);
    return max(left, right) + 1;
}
bool isBalanced(Node *root)
{
    //  Your Code here
    if (root == NULL)
        return true;
    int left = height(root->left);
    int right = height(root->right);
    if (abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return true;
    return false;
}
int height(Node* root)
{
    if (root == NULL)
        return 0;
    int left = height(root->left);
    int right = height(root->right);
    return max(left, right) + 1;
}
bool isBalanced(Node *root)
{
    // Code here
    if (root == NULL)
        return 1;
    int left = height(root->left);
    int right = height(root->right);
    int ans = abs(left - right);
    return ans <= 1 && isBalanced(root->left) && isBalanced(root->right) ? true : false;
}


int height(Node* root)
{
    if (root == NULL)
        return 0;
    int left = height(root->left);
    int right = height(root->right);
    return max(left, right) + 1;
}
bool isBalanced(Node *root)
{
    // Code here
    if (root == NULL)
        return 1;
    int left = height(root->left);
    int right = height(root->right);
    int ans = abs(left - right);
    return ans <= 1 && isBalanced(root->left) && isBalanced(root->right) ? true : false;
}

//O(N) solution calculating height and difference simultaneously

int checkHeight(Node* root)
{
    if (root == NULL)
        return 0;
    int left = checkHeight(root->left);
    if (left == INT_MIN)
        return INT_MIN;
    int right = checkHeight(root->right);
    if (right == INT_MIN)
        return INT_MIN;
    if (abs(left - right) > 1)
        return INT_MIN;
    else
        return max(left, right) + 1;
}
bool isBalanced(Node *root)
{
    //  Your Code here
    return checkHeight(root) != INT_MIN;
}


pair<int, bool> isHeightBalanced(node *root) {

    pair<int, bool> p, Left, Right;

    if (root == NULL) {
        p.first = 0; //height
        p.second = true; // balanced
        return p;
    }

    //rec case (Postorder Traversal)
    Left = isHeightBalanced(root->left);
    Right = isHeightBalanced(root->right);

    int height = max(Left.first, Right.first) + 1;

    if (abs(Left.first - Right.first) <= 1 and Left.second and Right.second) {
        return make_pair(height, true);
    }
    return make_pair(height, false);
}


int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(6);
    root->left->right->left = new node(7);
    root->left->right->right = new node(8);
    //root->left->right->right->left = new node(9);
    //root->left->right->right->right = new node(10);
    pair<int, bool> p = isHeightBalanced(root);
    if (p.second) {
        cout << "Yes, its height balanced";
    }
    else {
        cout << "Not a height balanced tree";
    }


}