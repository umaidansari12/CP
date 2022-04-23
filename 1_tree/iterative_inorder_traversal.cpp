// fails for this linked list [1,null,2,3,null,null,4,null,null] because the stack becomes empty after 1 is popped out and root = 2 , there is node left to be processed but as the linked list becomes empty then we break out of the loop

//   1
//    \
//     2
//    /
//   3
//    \
//     4

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> recursive_stack;
        vector<int> answer;
        recursive_stack.push(root);
        root = root->left;
        while (!recursive_stack.empty()) {
            while (root != NULL) {
                recursive_stack.push(root);
                root = root->left;
            }
            if (root == NULL) {
                root = recursive_stack.top();
                answer.push_back(root->val);
                recursive_stack.pop();
            }
            root = root->right;
        }

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
            // if root is NULL and stack is not empty then move to right subtree else break out because empty stack means that we have traversed the tree
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