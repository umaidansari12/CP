#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};




// } Driver Code Ends
class Solution
{
public:
    //Function to check whether a Binary Tree is BST or not.
    vector<Node*> in;
    void inorder(Node* root) {
        if (!root)
            return;
        inorder(root->left);
        in.push_back(root);
        inorder(root->right);
    }
    bool isBSTBrute(Node* root)
    {
        // Your code here
        inorder(root);
        for (int i = 0; i < in.size() - 1; i++) {
            if (in[i]->data >= in[i + 1]->data)
                return false;
        }
        return true;
    }
    bool isBSTHelper(Node* root, int _min, int _max) {
        if (!root)
            return true;

        /*
        if(root->data<=_min or root->data>=_max){
            return false;
        }
        */
        if (!(root->data > _min and root->data < _max)) {
            return false;
        }

        bool left = isBSTHelper(root->left, _min, root->data);

        bool right = isBSTHelper(root->right, root->data, _max);

        return left and right;
    }
    bool isBST(Node* root)
    {
        // Your code here
        int _min = INT_MIN, _max = INT_MAX;
        return isBSTHelper(root, _min, _max);
    }
};




// { Driver Code Starts.

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

void inorder(Node *root, vector<int> &v)
{
    if (root == NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        if (ob.isBST(root))
            cout << "1\n";

        else
            cout << "0\n";
    }
    return 0;
}


//Position this line where user code will be pasted
// } Driver Code Ends