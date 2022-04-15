/*The inorder traversal of a BST gives us the keys in sorted order.
Hence, you can generate a sorted array of keys and the question then reduces to finding the
 pair sum in a sorted array.
The O(N) solution for this is pretty straightforward using 2-pointers.

But, storing all the keys in an array requires O(N) extra space.
Can you use the same idea of the 2 - pointers without actually storing the node values in an array ?
 What about doing an iterative in - order traversal of the tree, one normal and the other reverse ?*/

void solve(struct Node* root, int key, map<int, int>& m, bool &f)
{
    if (root == NULL)
        return ;
    solve(root->left, key, m, f);
    if (m.find(key - root->data) != m.end())
    {
        f = true;
        return;
    }
    else
        m.insert(make_pair(root->data, 1));
    solve(root->right, key, m, f);

}
int isPairPresent(struct Node *root, int target)
{
//add code here.
    map<int, int>  m;
    bool f = false;
    solve(root, target, m, f);
    return f;
}

stack <Node*> forw, rev;

void pushRight (Node *rt)
{
    while (rt != NULL)
    {
        rev.push (rt);
        rt = rt->right;
    }
}

void pushLeft (Node *rt)
{
    while (rt != NULL)
    {
        forw.push (rt);
        rt = rt->left;
    }
}

int forwNext ()
{
    if (forw.empty ()) return INT_MIN;
    Node *res = forw.top ();
    forw.pop ();

    pushLeft (res->right);
    return res->data;
}

int revNext ()
{
    if (rev.empty ()) return INT_MIN;
    Node *res = rev.top ();
    rev.pop ();

    pushRight (res->left);
    return res->data;
}

int isPairPresent(Node* A, int B) {
    // clearing the stacks
    while (!forw.empty ()) forw.pop ();
    while (!rev.empty ()) rev.pop ();

    if (A == NULL) return 0;
    pushLeft(A);
    pushRight (A);

    int v1 = forwNext ();
    int v2 = revNext  ();
    int sum;

    while (v1 != INT_MIN and v2 != INT_MIN and v1 != v2)
    {
        sum = v1 + v2;
        if (sum == B)
        {
            return 1;
        }

        if (sum > B) // decrease the sum
            v2 = revNext ();

        else // increase the sum
            v1 = forwNext ();
    }

    return 0;
}
