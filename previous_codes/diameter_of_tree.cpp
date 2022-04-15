int height(Node* node, int &ans)
{
    if (node == NULL)
        return 0;
    int left = height(node->left, ans);
    int right = height(node->right, ans);
    ans = max(ans, 1 + left + right);
    return 1 + max(left, right);
}
int diameter(Node* node) {
    // Your code here
    if (node == NULL)
        return 0;
    int ans = INT_MIN;
    int h = height(node, ans);
    return ans;
}

class Solution {
public:
    int height(TreeNode* root, int &ans)
    {
        if (root == NULL)
            return 0;
        int left = height(root->left, ans);
        int right = height(root->right, ans);
        ans = max(ans, left + right);
        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;
        int ans = INT_MIN;
        int h = height(root, ans);
        return ans;
    }
};