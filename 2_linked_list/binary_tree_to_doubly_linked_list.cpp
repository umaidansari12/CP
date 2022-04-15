#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

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
    Node* root = newNode(stoi(ip[0]));

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
            currNode->left = newNode(stoi(currVal));

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
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}



// } Driver Code Ends
/* Structure for tree and linked list

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// This function should return head to the DLL
class Solution
{
public:
    //Function to convert binary tree to doubly linked list and return it.
    vector<Node*> res;
    void inorder(Node* root) {
        if (!root)
            return;
        inorder(root->left);
        res.push_back(root);
        inorder(root->right);
    }
    Node * bToDLL(Node *root)
    {
        // your code here
        if (!root)
            return NULL;
        inorder(root);
        for (int i = 0; i < res.size(); i++) {
            Node* tmp = res[i];
            if (i - 1 < 0)
                tmp->left = NULL;
            else
                tmp->left = res[i - 1];
            if (i + 1 == res.size())
                tmp->right = NULL;
            else
                tmp->right = res[i + 1];
        }
        return res[0];
    }
    Node* prev = NULL;
    // Changes left pointers to work as
    // previous pointers in converted DLL
    // The function simply does inorder
    // traversal of Binary Tree and updates
    // left pointer using previously visited node
    void fixPrevPtr(Node* root) {
        if (root != NULL) {
            fixPrevPtr(root->left);
            root->left = prev;
            prev = root;
            fixPrevPtr(root->right);
        }
    }
    // Changes right pointers to work
    // as next pointers in converted DLL
    Node* fixNextPtr(Node* root) {
        Node* prev = NULL;
        // Find the right most node
        // in BT or last node in DLL
        while (root and root->right != NULL)
            root = root->right;
        // Start from the rightmost node,
        // traverse back using left pointers.
        // While traversing, change right pointer of nodes.
        while (root and root->left != NULL) {
            prev = root;
            root = root->left;
            root->right = prev;
        }
        // The leftmost node is head
        // of linked list, return it
        return root;

    }
    Node * bToDLL(Node *root)
    {
        // your code here
        // Set the previous pointer
        fixPrevPtr(root);
        // Set the next pointer and return head of DLL
        return fixNextPtr(root);
    }
};



// { Driver Code Starts.


/* Function to print nodes in a given doubly linked list */
void printList(Node *node)
{
    Node *prev = NULL;
    while (node != NULL)
    {
        cout << node->data << " ";
        prev = node;
        node = node->right;
    }
    cout << endl;
    while (prev != NULL)
    {
        cout << prev->data << " ";
        prev = prev->left;
    }
    cout << endl;
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data;
        inorder(root->right);
    }
}

/* Driver program to test size function*/
int main()
{
    int t;
    cin >> t;
    getchar();

    while (t--)
    {
        string inp;
        getline(cin, inp);
        Node *root = buildTree(inp);

        Solution ob;
        Node *head = ob.bToDLL(root);
        printList(head);

    }
    return 0;
}

// } Driver Code Ends