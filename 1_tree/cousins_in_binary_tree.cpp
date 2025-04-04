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
    void dfs(TreeNode* root, int lvl, int par, unordered_map<int, pair<int, int>> &lvl_parent_map) {
        if (!root)
            return;
        lvl_parent_map[root->val] = {lvl, par};
        dfs(root->left, lvl + 1, root->val, lvl_parent_map);
        dfs(root->right, lvl + 1, root->val, lvl_parent_map);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        // find parent and level of nodes x and y
        // if parent is not same and is at same level return true otherwise false
        unordered_map<int, pair<int, int>> lvl_parent_map;
        dfs(root, 0, -1, lvl_parent_map);
        if (lvl_parent_map[x].first == lvl_parent_map[y].first and lvl_parent_map[x].second != lvl_parent_map[y].second)
            return true;
        return false;

    }
};

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
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root)
            return false;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int _size = q.size();
            bool x_exists = false, y_exists = false;
            while (_size--) {
                TreeNode* cur_node = q.front();
                q.pop();
                if (cur_node->val == x)
                    x_exists = true;
                if (cur_node->val == y)
                    y_exists = true;
                if (cur_node->left != NULL and cur_node->right != NULL) {
                    if (cur_node->left->val == x and cur_node->right->val == y)
                        return false;
                    if (cur_node->left->val == y and cur_node->right->val == x)
                        return false;
                }
                if (cur_node->left)
                    q.push(cur_node->left);
                if (cur_node->right)
                    q.push(cur_node->right);
            }
            // checking if either x and y exists at the same level and both of them is not coming from a same parent that is current_node
            if (x_exists and y_exists)
                return true;
        }
        return false;
    }
};

