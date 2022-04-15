int countNodes(Node* root) {
	if (root == NULL)
		return 0;
	return countNodes(root->left) + countNodes(root->right) + 1;

}
int countLeaves(Node* root)
{
	// Your code here
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return countLeaves(root->left) + countLeaves(root->right);
}
int countNonLeafNodes(Node* root)
{
	// Code here
	int total = countNodes(root);
	int leaf = countLeaves(root);
	return total - leaf;

}

//method-2

int countNonLeafNodes(Node* root)
{
	// Code here
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 0;
	return 1 + countNonLeafNodes(root->left) + countNonLeafNodes(root->right);
}