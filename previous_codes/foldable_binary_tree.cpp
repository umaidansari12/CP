bool solve(Node* r1, Node* r2)
{
	if (r1 == NULL && r2 == NULL)
		return true;
	if (r1 && r2)
	{
		return (solve(r1->left, r2->right) && solve(r1->right, r2->left));
	}
	return false;
}

bool IsFoldable(Node* root)
{
	// Your code goes here
	solve(root, root);
}