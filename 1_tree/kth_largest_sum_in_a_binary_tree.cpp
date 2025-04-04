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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (root == NULL)
            return -1;
        vector<long long int> level_sum;
        queue<TreeNode*> bfs;
        bfs.push(root);
        while (!bfs.empty()) {
            int _size = bfs.size();
            long long int sum = 0;
            while (_size--) {
                TreeNode* current_element = bfs.front();
                bfs.pop();
                sum += current_element->val;
                if (current_element->left) {
                    bfs.push(current_element->left);
                }
                if (current_element->right) {
                    bfs.push(current_element->right);
                }
            }
            level_sum.push_back(sum);
        }
        sort(level_sum.begin(), level_sum.end());
        if (k <= level_sum.size())
            return level_sum[level_sum.size() - k];
        return -1;
    }
};