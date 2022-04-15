void preorder(Node* root, vector<int>&r)
{
    if (root == NULL)
        return;
    r.push_back(root->data);
    preorder(root->left, r);
    preorder(root->right, r);
}

bool isIdentical(Node *r1, Node *r2)
{
    //Your Code here
    vector<int> p1, p2;
    preorder(r1, p1);
    preorder(r2, p2);
    if (p1.size() != p2.size())
        return false;
    for (int i = 0; i < p1.size() && i < p2.size(); i++)
    {
        if (p1[i] != p2[i])
            return false;
    }
    return true;
}

bool isIdentical(Node *r1, Node *r2)
{
    //Your Code here
    if (r1 == NULL && r2 == NULL)
        return true;
    if (r1 != NULL && r2 != NULL)
    {
        return r1->data == r2->data && isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);
    }

    return false;
}

/*Wrong Answer
Details
Input
[1,2]
[1,null,2]
Output
true
Expected
false*/

class Solution {
public:
    void preorder(TreeNode* r, vector<int>&re)
    {
        if (r == NULL)
            return;
        re.push_back(r->val);
        preorder(r->left, re);
        preorder(r->right, re);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> p1;
        vector<int> p2;
        preorder(p, p1);
        preorder(q, p2);
        if (p1.size() != p2.size())
            return false;
        for (int i = 0; i < p1.size(); i++)
            if (p1[i] != p2[i])
                return false;
        return true;

    }
};
class Solution {
public:
    void preorder(TreeNode* r, vector<int>&re)
    {
        if (r == NULL)
            return;
        re.push_back(r->val);
        preorder(r->left, re);
        preorder(r->right, re);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL)
            return true;
        if (p != NULL && q != NULL)
        {
            return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
        }
        return false;
    }
};