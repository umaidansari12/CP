class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return 1 + max(left, right);

    }
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        queue<TreeNode*> bfs;
        bfs.push(root);
        int height = 0;

        while (!bfs.empty()) {
            int size = bfs.size();
            height++;
            for (int i = 0; i < size; i++) {
                TreeNode* curr = bfs.front();
                bfs.pop();

                if (curr->left) {
                    bfs.push(curr->left);
                }
                if (curr->right) {
                    bfs.push(curr->right);
                }
            }
        }
        return height;
    }
};