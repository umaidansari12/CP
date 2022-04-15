void inorder(Node* root, vector<int>&r)
{
    if (root == NULL)
        return;
    inorder(root->left, r);
    r.push_back(root->data);
    inorder(root->right, r);
}
// Return the Kth smallest element in the given BST
int KthSmallestElement(Node *root, int K)
{
    //add code here.
    vector<int> r;
    inorder(root, r);
    if (K > r.size())
        return -1;
    return r[K - 1];

}

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int inorder(TreeNode* root, int* i, int k)
{
    if (root == NULL)
        return INT_MAX;
    int left = inorder(root->left, i, k);
    if (left != INT_MAX)
        return left;
    if (++*i == k)
        return root->val;
    return inorder(root->right, i, k);
}

int Solution::kthsmallest(TreeNode* A, int B) {
    int i = 0;
    return inorder(A, &i, B);
}


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<int>&r)
    {
        if (root == NULL)
            return;
        inorder(root->left, r);
        r.push_back(root->val);
        inorder(root->right, r);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> r;
        inorder(root, r);
        if (k > r.size())
            return -1;
        return r[k - 1];

    }
};