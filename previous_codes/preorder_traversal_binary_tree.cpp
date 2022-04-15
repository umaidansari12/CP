void solve(vector<int>&r, Node* root)
{
	if (root == NULL)
		return;
	r.push_back(root->data);
	solve(r, root->left);
	solve(r, root->right);
}

/*1. Preorder traversal is Data, Left, Right. So recursively traverse the tree in this fashion.*/

void preorderUtil(struct Node* root, vector <int> &res)
{
	//Preorder is Data Left Right
	if (root == NULL) //If root is null then we simply return
		return;
	res.push_back (root->data);
	preorderUtil(root->left, res);  //recurse left
	preorderUtil(root->right, res); //recurse right
}

vector <int> preorder (Node *root)
{
	vector <int> res;
	preorderUtil (root, res);
	return res;
}

vector <int> preorder(Node* root)
{
	// Your code here
	vector<int> r;
	solve(r, root);
	return r;
}
vector <int> preorder(Node* root)
{
	// Your code here
	vector<int> r;
	Node* current = root;
	stack<Node*> s;
	s.push(root);
	while (!s.empty())
	{
		current = s.top();
		s.pop();
		r.push_back(current->data);
		if (current->right)
			s.push(current->right);
		if (current->left)
			s.push(current->left);

	}
	return r;
}
//correct
vector <int> preorder(Node* root)
{
	// Your code here
	vector<int> r;
	Node* current = root;
	stack<Node*> s;
	while (current != NULL || !s.empty())
	{
		while (current != NULL)
		{
			s.push(current);
			r.push_back(current->data);
			current = current->left;
		}
		current = s.top()->right;
		s.pop();
	}
	return r;
}