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
