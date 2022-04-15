void solve(vector<int>&r, Node* root)
{
	if (root == NULL)
		return;
	solve(r, root->left);
	solve(r, root->right);
	r.push_back(root->data);
}

vector <int> postOrder(Node* root)
{
	// Your code here
	vector<int> r;
	solve(r, root);
	return r;
}

vector <int> postOrder(Node* root)
{
	// Your code here
	vector<int> r;
	stack<Node*> s;
	Node* current = root;
	s.push(current);
	while (!s.empty())
	{
		current = s.top();
		s.pop();

		if (current->left)
			s.push(current->left);
		if (current->right)
			s.push(current->right);
		r.push_back(current->data);


	}
	reverse(r.begin(), r.end());
	return r;
}