int height(BinaryTreeNode<int> *root) {
	if (root == NULL) {
		return 0;
	}

	int leftHeight = height(root->left);
	int rightHeight = height(root->right);

	return 1 + max(leftHeight, rightHeight);
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
	// Write your code here.
	if (root == NULL) {
		return true;
	}

	int leftHeight = height(root->left);
	int rightHeight = height(root->right);

	if (abs(leftHeight - rightHeight) <= 1 and isBalancedBT(root->left) and isBalancedBT(root->right))
		return true;

	return false;
}

pair<int, bool> isBalancedBTHelper(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return {0, true};
	}

	pair<int, bool> leftHeight = isBalancedBTHelper(root->left);
	pair<int, bool> rightHeight = isBalancedBTHelper(root->right);

	if (abs(leftHeight.first - rightHeight.first) <= 1 and leftHeight.second and rightHeight.second) {
		return {1 + max(leftHeight.first, rightHeight.first), true};
	}

	return {1 + max(leftHeight.first, rightHeight.first), false};
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
	// Write your code here.
	return isBalancedBTHelper(root).second;
}

int isBalancedBTHelper(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return 0;
	}

	int leftHeight = isBalancedBTHelper(root->left);
	int rightHeight = isBalancedBTHelper(root->right);

	if (leftHeight == -1 or rightHeight == -1)
		return -1;


	if (abs(leftHeight - rightHeight) > 1) {
		return -1;
	}

	return 1 + max(leftHeight, rightHeight);
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
	// Write your code here.
	return isBalancedBTHelper(root) != -1;
}