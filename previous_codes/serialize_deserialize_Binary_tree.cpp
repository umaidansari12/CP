class Solution {

public:
    int i = 0;
    void preorder(Node* root, vector<int> &pre)
    {
        if (root == NULL)
        {
            pre.push_back(-1);
            return;
        }
        pre.push_back(root->data);
        preorder(root->left, pre);
        preorder(root->right, pre);
    }
    vector<int> serialize(Node *root) {
        //Your code here
        vector<int> pre;
        preorder(root, pre);
        return pre;
    }
    /*this function deserializes
     the serialized vector A*/

    Node * deSerialize(vector<int> &A)
    {
        if (A[i] == -1 || i == A.size())
        {
            i++;
            return NULL;
        }
        Node* root = (Node*)malloc(sizeof(Node*));
        root->data = A[i++];
        root->left = deSerialize(A);
        root->right = deSerialize(A);
        return root;
    }

};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return !root ? " null" : " " + to_string(root->val) + serialize(root->left) + serialize(root->right);

    }
    TreeNode* buildTree(istringstream& ss)
    {
        string s;
        ss >> s;

        if (s == "null")
            return NULL;

        TreeNode* node = new TreeNode(stoi(s));
        node->left = buildTree(ss);
        node->right = buildTree(ss);

        return node;
    }
    // Decodes your encoded data to tree
    TreeNode* deserialize(string data) {

        istringstream ss(data);
        return buildTree(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));