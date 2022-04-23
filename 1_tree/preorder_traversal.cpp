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
    void preorder(TreeNode* root, vector<int> &answer) {
        if (root == NULL) {
            return;
        }
        // root left right
        answer.push_back(root->val);
        preorder(root->left, answer);
        preorder(root->right, answer);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> answer;
        preorder(root, answer);
        return answer;
    }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> recursive_stack;
        vector<int> answer;
        while (true) {
            if (root != NULL) {
                answer.push_back(root->val);
                recursive_stack.push(root);
                root = root->left;
            }
            else {
                if (recursive_stack.empty()) {
                    break;
                }

                root = recursive_stack.top();
                recursive_stack.pop();

                root = root->right;

            }
        }
        return answer;
    }
};

//easy to understand code , processing root first then it's right and left right first because it will be below left in stack.

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> answer;
        if (root == NULL)
            return answer;

        stack<TreeNode*> recursive_stack;

        recursive_stack.push(root);

        while (!recursive_stack.empty()) {
            TreeNode* curr = recursive_stack.top();
            recursive_stack.pop();

            answer.push_back(curr->val);

            if (curr->right != NULL)
                recursive_stack.push(curr->right);
            if (curr->left != NULL)
                recursive_stack.push(curr->left);
        }

        return answer;
    }
};