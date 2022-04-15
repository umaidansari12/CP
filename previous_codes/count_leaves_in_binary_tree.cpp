
void preorder(Node* root, int &count)
{
	if (root == NULL)
		return ;
	if (root->left == NULL && root->right == NULL)
		count++;
	preorder(root->left, count);
	preorder(root->right, count);
}
int countLeaves(Node* root)
{
	// Your code here
	int count = 0;
	preorder(root, count);
	return count;
}

//MEthhod-2

int countLeaves(Node* root)
{
	// Your code here
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return countLeaves(root->left) + countLeaves(root->right);
}