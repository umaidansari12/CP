class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
            return 0;
        int left = 0;
        if (root->left)
            left += root->left->val + sumOfLeftLeaves(root->left);
        int right = sumOfLeftLeaves(root->right);
        return left + right;

    }
};

class Solution {
public:
    bool isLeaf(TreeNode* root)
    {
        if (root == NULL)
            return false;
        if (root->left == NULL && root->right == NULL)
            return true;
        return false;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int res = 0;
        if (root != NULL)
        {
            if (isLeaf(root->left))
            {
                res += root->left->val;
            }
            else
                res += sumOfLeftLeaves(root->left);
            res += sumOfLeftLeaves(root->right);
        }
        return res;
    }
};

//recursive method
bool isLeaf(Node *node)
{
    if (node == NULL)
        return false;
    if (node->left == NULL && node->right == NULL)
        return true;
    return false;
}
int leftLeavesSum(Node *root)
{
    // Code here
    int res = 0;

    // Update result if root is not NULL
    if (root != NULL)
    {
        // If left of root is NULL, then add key of
        // left child
        if (isLeaf(root->left))
            res += root->left->data;
        else // Else recur for left child of root
            res += leftLeavesSum(root->left);

        // Recur for right child of root and update res
        res += leftLeavesSum(root->right);
    }

    // return result
    return res;
}

//correct method

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int sum = 0;
        while (!q.empty())
        {
            TreeNode* t = q.front();
            q.pop();
            if (t->left)
            {
                q.push(t->left);
                if (t->left->left == NULL && t->left->right == NULL)
                    sum += t->left->val;
            }
            if (t->right)
                q.push(t->right);
        }
        return sum;

    }
};