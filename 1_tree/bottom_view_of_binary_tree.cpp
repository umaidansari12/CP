#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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


vector <int> bottomView(Node *root);

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



int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s , ch;
        getline(cin, s);
        Node* root = buildTree(s);

        vector <int> res = bottomView(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends


/* Tree node class

struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references

    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
}; */

// Method that returns the bottom view.


vector <int> bottomView(Node *root)
{
    // Your Code Here
    map<int, int> m;
    queue<pair<Node*, int>> q;
    int hd = 0;
    q.push(make_pair(root, hd));
    while (!q.empty())
    {
        Node* t = q.front().first;
        hd = q.front().second;
        m[hd] = t->data;
        q.pop();
        if (t->left)
        {
            q.push(make_pair(t->left, hd - 1));
        }
        if (t->right)
        {
            q.push(make_pair(t->right, hd + 1));
        }
    }
    auto i = m.begin();
    vector<int> r;
    while (i != m.end())
    {
        r.push_back(i->second);
        i++;
    }
    return r;
}

void preorder(Node* root, map<int, int> &res, int lvl)
{
    if (!root)
        return;

    res[lvl] = root->data;

    preorder(root->left, res, lvl - 1);
    preorder(root->right, res, lvl + 1);

}

vector <int> bottomView(Node *root) {
    // Your Code Here
    map<int, int> res;
    vector<int> r;
    preorder(root, res, 0);
    for (auto i : res)
    {
        r.push_back(i.second);
    }
    return r;
}

class Solution {
public:
    //      1
    //   /    \ 
    //  4     2
    // /     /
    // 5    3
    //  \ 
    //    6
    //     \
    //      7
    // recursive version fails for this case because first it will go down in left subtree and line 0th when we go down we will the bottom most node will be
    // 7 but as we go down the right subtree it will change to 3 because it is also lying on 0th line but according to question this will be incorrect because this is not at the bottom most level but since our logic is to include last node on any line
    // so we need to make changes and introduce height into our logic as well
    // so we will use a pair in map which contains height as well so we will compare if the current row is greater than the encountered row then only we will update the answer otherwise leave it as it is
    void bottomViewHelper(Node *root, map<int, int> &level, int current_level) {
        if (root == NULL)
            return;

        level[current_level] = root->data;
        bottomViewHelper(root->left, level, current_level - 1);
        bottomViewHelper(root->right, level, current_level + 1);
    }

    vector <int> bottomView(Node *root) {
        // Your Code Here
        map<int, int> level;
        int current_level = 0;
        bottomViewHelper(root, level, current_level);
        vector<int> bottom_view;
        for (auto lvl : level) {
            bottom_view.push_back(lvl.second);
        }
        return bottom_view;
    }

    void bottomViewHelper(Node *root, map<int, pair<int, int>> &level, int current_level, int current_height) {
        if (root == NULL)
            return;
        // if height of current node is greater than previously stored then only update the answer to encounter the bottom most node
        if (current_height >= level[current_level].second)
            level[current_level] = {root->data, current_height};
        bottomViewHelper(root->left, level, current_level - 1, current_height + 1);
        bottomViewHelper(root->right, level, current_level + 1, current_height + 1);
    }

    vector<int> bottomView(Node * root) {
        // map will be <line,<node value,height>>
        // similar to <x-axis,<node value,y-axis>>
        // /Structur of map: colum_no={data,rownumber}
        map<int, pair<int, int>> level;
        int current_level = 0, current_height = 0;
        bottomViewHelper(root, level, current_level, current_height);
        vector<int> bottom_view;
        for (auto lvl : level) {
            bottom_view.push_back(lvl.second.first);
        }
        return bottom_view;
    }

};

class Solution {
public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> bottom_view;
        if (root == NULL)
            return bottom_view;
        map<int, int> level;
        queue<pair<Node*, int>> bfs;

        bfs.push({root, 0});

        while (!bfs.empty()) {
            Node* current_node = bfs.front().first;
            int hd = bfs.front().second;

            bfs.pop();

            level[hd] = current_node->data;

            if (current_node->left) {
                bfs.push({current_node->left, hd - 1});
            }
            if (current_node->right) {
                bfs.push({current_node->right, hd + 1});
            }
        }

        for (auto lvl : level) {
            bottom_view.push_back(lvl.second);
        }

        return bottom_view;
    }
};