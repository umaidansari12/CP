/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void solve(Node* root, vector<int>&r)
    {
        if (root == NULL)
            return;
        for (auto i : root->children)
            solve(i, r);
        r.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        vector<int> r;
        solve(root, r);
        return r;

    }
};