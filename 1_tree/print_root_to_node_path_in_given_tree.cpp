/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool helper(TreeNode* root, int node, vector<int> &path) {
    // if the root is null then means node not found return false
    if (root == NULL) {
        return false;
    }

    // first push the root node value into ds

    path.push_back(root->val);

    // if the root node's value is equal to the value we are searching then return true indicating the node has been found
    if (root->val == node) {
        return true;
    }

    // if above is not the case then we go to both the subtree's of the current root node and check if it can be found in any of the subtree, if yes return true
    if (helper(root->left, node, path) or helper(root->right, node, path))
        return true;
    // otherwise indicating that the element has not been found the subtree of current root node remove this node from path and return false
    path.pop_back();
    return false;


}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> path;
    if (A == NULL)
        return path;
    // do the inorder traversal to get the path
    helper(A, B, path);

    return path;
}
