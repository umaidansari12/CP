bool solve(Node* r1, Node* r2)
{
	if (r1 == NULL && r2 == NULL)
		return true;
	if (r1 && r2 && (r1->data == r2->data))
		return (solve(r1->left, r2->right) && solve(r1->right, r2->left));
	return false;
}
bool isSymmetric(struct Node* root)
{
	// Code here
	return solve(root, root);
}
class Solution {
public:
	bool solve(TreeNode* r1, TreeNode* r2)
	{
		if (r1 == NULL && r2 == NULL)
			return true;
		if (r1 != NULL && r2 != NULL && r1->val == r2->val)
			return (solve(r1->left, r2->right) && solve(r1->right, r2->left));
		return false;
	}
	bool isSymmetric(TreeNode* root) {
		return solve(root, root);

	}
};


bool isSymmetric(struct Node* root)
{
	// Code here
	if (root == NULL)
		return true;
	if (!root->left && !root->right)
		return true;
	queue<Node*> q;
	q.push(root);
	q.push(root);
	while (!q.empty())
	{
		Node* lnode = q.front();
		q.pop();
		Node* rnode = q.front();
		q.pop();
		if (lnode->data != rnode->data)
			return false;
		if (lnode->left && rnode->right)
		{
			q.push(lnode->left);
			q.push(rnode->right);
		}
		else if (lnode->left || rnode->right)
			return false;
		if (lnode->right && rnode->left)
		{
			q.push(lnode->right);
			q.push(rnode->left);
		}
		else if (lnode->right || rnode->left)
			return false;

	}
	return true;
}