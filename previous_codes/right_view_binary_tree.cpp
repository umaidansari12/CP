/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */


/*1. The problem can also be solved using simple recursive traversal. We can keep track of level of a node by passing
 a parameter to all recursive calls. The idea is to keep track of maximum level also. And traverse the tree in a manner
 that right subtree is visited before left subtree. Whenever we see a node whose level is more than maximum level so far
  we print the node because this is the last node in its level (Note that we traverse the right subtree before left
  subtree). Following is C implementation of this approach.*/

//Back-end complete function template for C++
class Solution {

public:
    void rightViewUtil(vector<int> &vec, struct Node *root, int level, int *max_level)
    {
        // Base Case
        if (root == NULL)  return;

        // If this is the last Node of its level
        if (*max_level < level)
        {
            vec.push_back(root->data);
            *max_level = level;
        }

        // Recur for right subtree first, then left subtree
        rightViewUtil(vec, root->right, level + 1, max_level);
        rightViewUtil(vec, root->left, level + 1, max_level);
    }

// A wrapper over rightViewUtil()
    vector<int> rightView(struct Node *root)
    {
        int max_level = 0;
        vector<int> vec;
        rightViewUtil(vec, root, 1, &max_level);
        return vec;
    }

};


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
    void solve(TreeNode* root, vector<int>&r, int lvl, int& m)
    {
        if (root == NULL)
            return;
        if (m < lvl)
        {
            r.push_back(root->val);
            m = lvl;
        }
        solve(root->right, r, lvl + 1, m);
        solve(root->left, r, lvl + 1, m);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> r;
        int m = 0;
        solve(root, r, 1, m);
        return r;
    }
};

// Should return  right view of tree
vector<int> rightView(Node *root)
{
    // Your Code here

    vector<int> r;
    if (!root)
        return r;
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 1; i <= n; i++)
        {
            Node* prev = q.front();
            q.pop();
            if (prev->left)
                q.push(prev->left);
            if (prev->right)
                q.push(prev->right);
            if (i == n)
                r.push_back(prev->data);
        }
    }
    return r;
}
