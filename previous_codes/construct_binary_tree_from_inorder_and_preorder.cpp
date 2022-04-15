Node* buildTree(int in[], int pre[], int l, int h)
{
	if (l > h)
		return NULL;

	Node* root = newNode(pre[preIndex++]);

	if (l == h)
		return root;

	int i;
	for (i = l; i <= h; i++)
		if (root->data == in[i])
			break;

	if (i <= h)
	{
		root->left = buildTree(in, pre, l, i - 1);

		root->right = buildTree(in, pre, i + 1, h);
	}

	return root;
}


Node* solve(int in[], int pre[], int s, int e, int &preindex)
{
	if (s > e)
		return NULL;
	Node* tNode = new Node(pre[preindex++]);
	if (s == e)
		return tNode;
	int i;
	for (i = s; i <= e; i++)
		if (in[i] == tNode->data)
			break;
	if (i <= e)
	{
		tNode->left = solve(in, pre, s, i - 1, preindex);
		tNode->right = solve(in, pre, i + 1, e, preindex);
		return tNode;
	}
	//return NULL;
}

Node* buildTree(int in[], int pre[], int n)
{
//add code here.
	int preindex = 0;
	return solve(in, pre, 0, n - 1, preindex);
}