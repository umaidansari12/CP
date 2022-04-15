#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


void saveLeafNodes(Node* root, vector<Node*> &leaf)
{
    if (!root)return;
    saveLeafNodes(root->left, leaf);
    if (root->left == NULL && root->right == NULL)leaf.push_back(root);
    saveLeafNodes(root->right, leaf);
}

void linkLeafNodes(Node* root)
{
    vector<Node*> leaf;
    saveLeafNodes(root, leaf);
    if (leaf.size() <= 1)return;
    for (int i = 0; i < leaf.size(); i++)
    {
        if (i == 0)
        {
            leaf[i]->right = leaf[i + 1];
            leaf[i]->left = leaf[leaf.size() - 1];
        }
        else if (i == leaf.size() - 1)
        {
            leaf[i]->right = leaf[0];
            leaf[i]->left = leaf[i - 1];
        }
        else
        {
            leaf[i]->right = leaf[i + 1];
            leaf[i]->left = leaf[i - 1];
        }
    }
    return;
}

int findTreeHeight(Node* node);

int main()
{

    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        linkLeafNodes(root);
        int h = findTreeHeight(root);
        cout << h << endl;
    }
    return 1;
}// } Driver Code Ends


/*Structure of the node of the binary tree

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// Return the height of the given special binary tree

// given a special binary tree whose leaf nodes are connected and are in the form of circular doubly linked list that is left pointer acts as previous pointer and right pointer acts as next pointer
// so to check if a node is leaf we need to check if current root's left right is equal to the current node that means we go one step back and then come one step forward and we check the same for root right left.


bool isLeaf(Node* node) {

    return node->left and node->left->right == node and node->right and node->right->left == node;
}

int height(Node* root) {
    if (root == NULL)
        return 0;

    if (isLeaf(root))
        return 1;

    return 1 + max(height(root->left), height(root->right));
}

int findTreeHeight(Node* root)
{
    // Code here
    return height(root);
}