#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

void sort_and_print(vector <int> &v)
{
    sort( v.begin() , v.end() );
    for ( int i = 0 ; i < v.size() ; i++ )
        cout << v[i] << " ";
    v.clear();
}

void printLevelOrder(struct Node* root)
{
    vector <int> v;
    queue <Node*> q;

    q.push(root);

    Node* next_row = NULL;

    while (!q.empty())
    {
        Node* n = q.front();
        q.pop();

        if (n == next_row)
        {
            sort_and_print(v);
            next_row = NULL;
        }

        v.push_back(n->data);

        if (n->left)
        {
            q.push(n->left);
            if (next_row == NULL) next_row = n->left;
        }

        if (n->right)
        {
            q.push(n->right);
            if (next_row == NULL) next_row = n->right;
        }
    }
    sort_and_print(v);
}

Node *createTree(int parent[], int n);

/* Driver program to test above function*/
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for ( int i = 0 ; i < n ; i++ )
            cin >> a[i];

        struct Node *res = createTree(a, n);

        printLevelOrder(res);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends


/* node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */


//Function to construct binary tree from parent array.
Node *createTree(int parent[], int N)
{
    // Your code here
    vector<int> adj[N + 1];
    int r = -1;
    for (int i = 0; i < N; i++)
    {
        if (parent[i] != -1)
        {
            adj[parent[i]].push_back(i);
        }
        else
            r = i;
    }
    Node* root = new Node(r);
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        Node* curr = q.front();
        q.pop();
        if (adj[curr->data].size() == 2)
        {
            curr->left = new Node(adj[curr->data][0]);
            q.push(curr->left);
            curr->right = new Node(adj[curr->data][1]);
            q.push(curr->right);
        }
        else if (adj[curr->data].size() == 1)
        {
            curr->left = new Node(adj[curr->data][0]);
            q.push(curr->left);
        }
    }
    return root;

}