/*An interesting property to note about elements on a specific diagonal
 is that the slope distance of every element present on a specific diagonal is same.*/
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

void diagonalPrintUtil(Node* root, int d,
                       map<int, vector<int>> &diagonalPrint)
{
	// Base case
	if (!root)
		return;

	// Store all nodes of same
	// line together as a vector
	diagonalPrint[d].push_back(root->data);

	// Increase the vertical
	// distance if left child
	diagonalPrintUtil(root->left,
	                  d + 1, diagonalPrint);

	// Vertical distance remains
	// same for right child
	diagonalPrintUtil(root->right,
	                  d, diagonalPrint);
}
vector<int> diagonal(Node *root)
{
	// your code here
	map<int, vector<int> > diagonalPrint;
	diagonalPrintUtil(root, 0, diagonalPrint);
	vector<int> r;
	//cout << "Diagonal Traversal of binary tree : \n";
	for (auto it : diagonalPrint)
	{
		vector<int> v = it.second;
		for (auto it : v)
			r.push_back(it);
	}
	return r;
}


vector<int> diagonal(Node *root)
{
	queue<Node*> Q;
	Node *p;
	Q.push(root);
	vector<int> diagonalNode;
	while (!Q.empty())
	{
		p = Q.front();
		Q.pop();
		while (p)
		{
			if (p->left)
				Q.push(p->left);
			//cout<<p->data<<" ";
			diagonalNode.push_back(p->data);
			p = p->right;
		}
	}
	return diagonalNode;

}
