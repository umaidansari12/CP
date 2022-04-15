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

Node* lca(Node* root , int n1 , int n2 )
{
  //Your code here
  vector<Node*> p1;
  vector<Node*> p2;

  if (!path(root, n1, p1) || !path(root, n2, p2))
    return NULL;

  int i = 0;
  for (i = 0; i < p1.size() && p2.size(); i++)
  {
    if (p1[i] != p2[i])
      break;
  }
  return p1[i - 1];
}

class Solution
{
public:
  bool path(Node* root, vector<Node*>&p, int k)
  {
    if (root == NULL)
      return false;
    p.push_back(root);
    if (root->data == k)
      return true;
    if (path(root->left, p, k) || path(root->right, p, k))
      return true;
    p.pop_back();
    return false;
  }
  Node* lca(Node* root , int n1 , int n2 )
  {
    //Your code here
    vector<Node*> p1;
    vector<Node*> p2;
    if (!path(root, p1, n1) || !path(root, p2, n2))
      return NULL;
    int i = 0;
    for (i = 0; i < p1.size() && i < p2.size(); i++)
    {
      if (p1[i] != p2[i])
        break;
    }
    return p1[i - 1];
  }
};


class Solution {
public:
  bool path(TreeNode* root, TreeNode* k, vector<TreeNode*>&r)
  {
    if (root == NULL)
      return false;
    r.push_back(root);
    if (root == k)
      return true;
    if ((root->left && path(root->left, k, r)) || (root->right && path(root->right, k, r)))
      return true;
    r.pop_back();
    return false;
  }
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> p1, p2;
    if (!path(root, p, p1) || !path(root, q, p2))
      return NULL;
    int i = 0;
    for (i = 0; i < p1.size() && i < p2.size(); i++)
      if (p1[i] != p2[i])
        break;
    return p1[i - 1];
  }
};

class Solution
{
public:
  Node* lca(Node* root , int n1 , int n2)
  {
    //Your code here
    Node *lnode, *rnode;
    if (!root) {
      return NULL;
    }

    if (root->data == n1 || root->data == n2) {
      return root;
    }

    lnode = lca(root->left, n1, n2);
    rnode = lca(root->right, n1, n2);
    if (lnode && rnode) {
      return root;
    }

    return (lnode != NULL) ? lnode : rnode;
  }
};

class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* lnode;
    TreeNode* rnode;
    if (!root)
      return NULL;
    if (root == p || root == q)
      return root;
    lnode = lowestCommonAncestor(root->left, p, q);
    rnode = lowestCommonAncestor(root->right, p, q);
    if (lnode && rnode)
      return root;
    return (lnode != NULL) ? lnode : rnode;

  }
};

class Solution
{
public:
  //Function to return the lowest common ancestor in a Binary Tree.
  Node* lca(Node* root , int n1 , int n2 )
  {
    //Your code here
    if (root == NULL)
      return NULL;
    if (root->data == n1 || root->data == n2)
      return root;
    Node* left = lca(root->left, n1, n2);
    Node* right = lca(root->right, n1, n2);

    if (left and right)
      return root;

    return (left != NULL) ? left : right;
  }
};
