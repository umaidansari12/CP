bool path(Node* root, int k, vector<Node*>& r)
{
  if (root == NULL)
    return false;
  r.push_back(root);
  if (root->data == k)
    return true;
  if ((root->left && path(root->left, k, r)) || (root->right && path(root->right, k, r)))
    return true;
  r.pop_back();
  return false;
}
Node* LCA(Node *root, int n1, int n2)
{
  //Your code here
  vector<Node*> p1, p2;

  if (!path(root, n1, p1) || !path(root, n2, p2))
    return NULL;
  int i = 0;
  for (i = 0; i < p1.size() && i < p2.size(); i++)
    if (p1[i] != p2[i])
      break;
  return p1[i - 1];
}

Node* LCA(Node *root, int n1, int n2)
{
  //Your code here
  if (n1 < root->data && n2 < root->data)
    return LCA(root->left, n1, n2);
  else if (n1 > root->data && n2 > root->data)
    return LCA(root->right, n1, n2);
  else
    return root;
  return NULL;
}

class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    while (root != NULL)
    {
      if (p->val < root->val && q->val < root->val)
        root = root->left;
      else if (p->val > root->val && q->val > root->val)
        root = root->right;
      else
        return root;
    }
    return NULL;

  }
};
Node* LCA(Node *root, int n1, int n2)
{
  //Your code here
  while (root)
  {
    if (n1 < root->data && n2 < root->data)
      root = root->left;
    else if (n1 > root->data && n2 > root->data)
      root = root->right;
    else
      return root;
  }
  return NULL;
}