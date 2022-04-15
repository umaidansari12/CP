void inorder(struct node* root, vector<struct node*>&r)
{
	if (root == NULL)
		return;
	inorder(root->left, r);
	r.push_back(root);
	inorder(root->right, r);
}

void populateNext(struct node* p)
{

// Your code goes here
	vector<struct node*> r;
	inorder(p, r);
	int n = r.size();
	for (int i = 0; i < n - 1; i++)
	{
		r[i]->next = r[i + 1];
	}
	r[n - 1]->next = NULL;
}

//using reverse inorder traversal

void inorder(struct node*&root, struct node*& prev)
{
	if (root == NULL)
		return ;
	inorder(root->right, prev);
	root->next = prev;
	prev = root;
	inorder(root->left, prev);
}
void populateNext(struct node* p)
{

// Your code goes here
	struct node* prev = NULL;
	inorder(p, prev);

}