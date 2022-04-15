void inorder(Node* root, vector<Node*>&r)
{
    if (root == NULL)
        return;
    inorder(root->left, r);
    r.push_back(root);
    inorder(root->right, r);
}
Node * inOrderSuccessor(Node *root, Node *x)
{
    //Your code here
    vector<Node*> r;
    inorder(root, r);
    int i = 0;
    for (i = 0; i < r.size(); i++)
        if (r[i] == x)
            break;
    return (i + 1) == r.size() ? NULL : r[i + 1];
}

Node * inOrderSuccessor(Node *root, Node *x)
{
    //Your code here
    if (root == NULL)
        return NULL;
    Node* suc = NULL;
    while (root != NULL)
    {
        if (root == x)
        {
            if (root->right)
            {
                Node* temp = root->right;
                while (temp->left)
                    temp = temp->left;
                suc = temp;
            }
        }
        if (root->data > x->data)
        {
            suc = root;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return suc;
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
TreeNode* Solution::getSuccessor(TreeNode* A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    TreeNode* suc = NULL;
    while (A != NULL)
    {
        if (A->val == B)
        {
            if (A->right != NULL)
            {
                TreeNode* tmp = A->right;
                while (tmp->left)
                    tmp = tmp->left;
                suc = tmp;
            }
        }
        if (A->val > B)
        {
            suc = A;
            A = A->left;
        }
        else
        {
            A = A->right;
        }
    }
    return suc;
}

class Solution {
public:
    TreeNode* Find(TreeNode *root, int data) {
        while (root != NULL && root->val != data) {
            if (data < root->val) root = root->left;
            else root = root->right;
        }
        if (root != NULL && root->val == data) return root;
        return NULL;
    }

    TreeNode* FindMin(TreeNode *root) {
        while (root->left != NULL) root = root->left;
        return root;
    }

    TreeNode* getSuccessor(TreeNode* root, int data) {
        // Search the node O(h)
        TreeNode* current = Find(root, data);
        if (current == NULL) return NULL;
        if (current->right != NULL)  { // Case 1 : Node has right subtree
            return FindMin(current->right);
        } else {
            TreeNode *successor = NULL, *ancestor = root;
            while (ancestor != current) {
                if (data < ancestor->val) {
                    successor = ancestor; // so far this is the deepest node for which current node is in left.
                    ancestor = ancestor->left;
                } else
                    ancestor = ancestor->right;
            }
            return successor;
        }
    }
};