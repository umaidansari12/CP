class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> answer;

        while (root != NULL) {
            // that means there is no left subtree for the root
            if (root->left == NULL) {
                // as there is no subtree just push root node value in the inorder traversal and move to right subtree
                answer.push_back(root->val);
                root = root->right;
            }
            else {
                // there is left subtree we need to move into rightmost node of current left subtree so that we can connect that rightmost node to the current root to create a threaded binary tree then traverse its subtree to create another thread
                TreeNode* previous = root->left;
                while (previous->right != NULL and previous->right != root) {
                    previous = previous->right;
                }

                // if thread is not there create a thread and move into left subtree and before moving into left subtree print the current root node value in preorder traversal
                if (previous->right == NULL) {
                    previous->right = root;
                    answer.push_back(root->val);
                    root = root->left;
                }
                // if thread is there remove the thread and then as the left subtree is completed and move to right subtree
                else {
                    previous->right = NULL;
                    root = root->right;
                }
            }
        }

        return answer;
    }
};