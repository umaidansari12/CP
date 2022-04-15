// C++ implementation to count pairs from two
#include <bits/stdc++.h>
using namespace std;

// structure of a node of BST
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if (!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if (val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if (val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}

int countPairs(Node* root1, Node* root2, int x);

// Driver code
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        Node* root1 = NULL;
        Node* root2 = NULL;
        int n1, n2, k;
        cin >> n1;
        for (int i = 0; i < n1; i++)
        {
            cin >> k;
            insert(&root1, k);
        }
        cin >> n2;
        for (int i = 0; i < n2; i++)
        {
            cin >> k;
            insert(&root2, k);
        }
        int s;
        cin >> s;
        cout << countPairs(root1, root2, s) << "\n";
    }
    return 0;
}


// } Driver Code Ends


//User function Template for C++
/*Structure of the Node of the BST is as
struct Node {
    int data;
    Node* left, *right;
};*/
// You are required to complete this function
void inorder(Node* root, vector<int>&r)
{
    if (root == NULL)
        return;
    inorder(root->left, r);
    r.push_back(root->data);
    inorder(root->right, r);
}

int countPairs(Node* root1, Node* root2, int x)
{
    // Code here
    vector<int> r1;
    vector<int> r2;
    inorder(root1, r1);
    inorder(root2, r2);
    int i = 0, j = r2.size() - 1, count = 0, n = r1.size();
    while (i < n && j >= 0)
    {
        int sum = r1[i] + r2[j];
        if (sum == x)
        {
            i++;
            j--;
            count++;
        }
        else if (sum > x)
            j--;
        else
            i++;
    }
    return count;
}