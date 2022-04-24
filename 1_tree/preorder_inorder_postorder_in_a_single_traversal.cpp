vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root) {
	// Write your code here.
	vector<vector<int>> answer;
	if (root == NULL)
		return answer;
	vector<int> inorder, preorder, postorder;
	stack<pair<BinaryTreeNode<int>*, int>> traverse;
	traverse.push({root, 1}); //initially we will push root with the number 1 as we are going to visit it first time

	while (!traverse.empty()) {
		BinaryTreeNode<int>* current_element = traverse.top().first;
		int number = traverse.top().second;

		if (number == 1) {
			preorder.push_back(current_element->data);
			traverse.top().second = number + 1;
			if (current_element->left)
				traverse.push({current_element->left, 1});
		}
		else if (number == 2) {
			inorder.push_back(current_element->data);
			traverse.top().second = number + 1;
			if (current_element->right)
				traverse.push({current_element->right, 1});
		}
		else if (number == 3) {
			postorder.push_back(current_element->data);
			traverse.pop();
		}
	}

	return {inorder, preorder, postorder};

}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root) {
	// Write your code here.
	vector<vector<int>> answer;
	if (root == NULL)
		return answer;
	vector<int> inorder, preorder, postorder;
	stack<pair<BinaryTreeNode<int>*, int>> traverse;
	traverse.push({root, 1}); //initially we will push root with the number 1 as we are going to visit it first time

	while (!traverse.empty()) {
		BinaryTreeNode<int>* current_element = traverse.top().first;
		int number = traverse.top().second;

		traverse.pop();

		if (number == 1) {
			preorder.push_back(current_element->data);
			traverse.push({current_element, number + 1});
			if (current_element->left)
				traverse.push({current_element->left, 1});
		}
		else if (number == 2) {
			inorder.push_back(current_element->data);
			traverse.push({current_element, number + 1});
			if (current_element->right)
				traverse.push({current_element->right, 1});
		}
		else if (number == 3) {
			postorder.push_back(current_element->data);
		}
	}

	return {inorder, preorder, postorder};

}