int height(TreeNode<int> *root) {
	if (root == NULL) {
		return 0;
	}

	int leftHeight = height(root->left);
	int rightHeight = height(root->right);

	return 1 + max(leftHeight, rightHeight);
}

void diameterHelper(TreeNode<int> *root, int &_max) {
	if (root == NULL) {
		return;
	}

	int leftHeight = height(root->left);
	int rightHeight = height(root->right);

	_max =  max(leftHeight + rightHeight, _max);
	diameterHelper(root->left, _max);
	diameterHelper(root->right, _max);

}

int diameterOfBinaryTree(TreeNode<int> *root)
{
	// Write Your Code Here.
	int answer = 0;
	diameterHelper(root, answer);
	return answer;
}

int diameterHelper(TreeNode<int> *root, int &_max) {
	if (root == NULL) {
		return 0;
	}

	int leftHeight = diameterHelper(root->left, _max);
	int rightHeight = diameterHelper(root->right, _max);

	diameter =  max(leftHeight + rightHeight, diameter);

	return 1 + max(leftHeight, rightHeight);
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
	// Write Your Code Here.
	int diameter = 0;
	diameterHelper(root, answer);
	return diameter;
}