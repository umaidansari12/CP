/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<int> &answer) {
        if (root == NULL) {
            return;
        }
        // left -> root -> right
        inorder(root->left, answer);
        answer.push_back(root->val);
        inorder(root->right, answer);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> answer;
        inorder(root, answer);
        return answer;

    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> recursive_stack;
        vector<int> answer;
        while (true) {
            // if root is not null move to left subtree
            if (root != NULL) {
                recursive_stack.push(root);
                root = root->left;
            }
            // if root is NULL and stack is not empty then move to right subtree else break out
            else {
                if (recursive_stack.empty()) {
                    break;
                }

                root = recursive_stack.top();
                recursive_stack.pop();
                answer.push_back(root->val);
                root = root->right;

            }
        }

        return answer;

    }
};