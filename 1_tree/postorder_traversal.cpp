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
    void postorder(TreeNode* root, vector<int> &answer) {
        if (root == NULL)
            return;

        postorder(root->left, answer);
        postorder(root->right, answer);
        answer.push_back(root->val);

    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> answer;
        postorder(root, answer);

        return answer;

    }
};


// process left subtree and right subtree first and then process root by pushing them into another stack
// The fundamental problem we face in this scenario is that there is no way that we can move from a child to the parent using as our node points to only children and not to the parent. To solve this problem, we use an explicit stack data structure. While traversing we can insert node values to the stack in such a way that we always get the next node value at the top of the stack.

// Using two stacks
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> answer;
        if (root == NULL)
            return answer;

        stack<TreeNode*> recursive_stack;
        stack<TreeNode*> root_process;

        recursive_stack.push(root);

        while (!recursive_stack.empty()) {
            TreeNode* curr = recursive_stack.top();
            recursive_stack.pop();

            root_process.push(curr);

            if (curr->left) {
                recursive_stack.push(curr->left);
            }
            if (curr->right) {
                recursive_stack.push(curr->right);
            }

        }

        while (!root_process.empty()) {
            answer.push_back(root_process.top()->val);
            root_process.pop();
        }

        return answer;
    }
};

// Using 1 Stack

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> answer;

        stack<TreeNode*> recursive_stack;

        while (root != NULL or !recursive_stack.empty()) {
            if (root != NULL) {
                recursive_stack.push(root);
                root = root->left;
            }
            else {
                TreeNode* right_node = recursive_stack.top()->right;
                // recursive_stack.pop();

                // if right subtree is null that means right node is processed and we need to move to root parent
                if (right_node == NULL) {
                    right_node = recursive_stack.top();
                    recursive_stack.pop();
                    answer.push_back(right_node->val);

                    while (!recursive_stack.empty() and right_node == recursive_stack.top()->right) {
                        right_node = recursive_stack.top();
                        recursive_stack.pop();
                        answer.push_back(right_node->val);
                    }

                }
                // else right subtree is not over and we need to process it
                else
                    root = right_node;
            }
        }
        return answer;
    }
};