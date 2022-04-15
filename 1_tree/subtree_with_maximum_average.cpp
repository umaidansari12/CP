/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

pair<int, int> average(Tree* root, double &ans) {
    if (!root)
        return {0, 0};

    pair<int, int> left = average(root->left, ans);
    pair<int, int> right = average(root->right, ans);
    pair<int, int> curr;
    curr.first = left.first + right.first + root->val;
    curr.second = left.second + right.second + 1;
    ans = max(ans, curr.first / (double)curr.second);

    return curr;
}
double solve(Tree* root) {
    double ans = 0.0;
    average(root, ans);
    return ans;
}

/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
      public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include <bits/stdc++.h>

pair<int, int> solve(TreeNode<int>* root, double &ans) {
    if (!root)
        return {0, 0};
    pair<int, int> left = solve(root->left, ans);
    pair<int, int> right = solve(root->right, ans);
    pair<int, int> curr;
    curr.first = left.first + right.first + root->data;
    curr.second = left.second + right.second + 1;
    ans = max(ans, curr.first / (double)(curr.second));
    return curr;
}

double maxSubtreeAverage(TreeNode<int> *root) {
    // Write your code here.
    double ans = -340282346638528859811704183484516925440.0000000000000000;
    if (!root)
        return ans;
    solve(root, ans);
    return ans;
}