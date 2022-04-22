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