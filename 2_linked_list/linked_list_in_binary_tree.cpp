/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!head) // head==NULL means all the nodes have been matched and there is nothing to match now so return true all nodes matched
            return true;
        if (!root) //tree is NULL means nothing to match means no node matched now.
            return false
                   //try matching head with root and if not then move to root->left and still it is not the case then move to root->right
                   return dfs(head, root) or isSubPath(head, root->left) or isSubPath(head, root->right);
    }
    bool dfs(ListNode* head, TreeNode* root) {
        if (!head)
            return true;
        if (!root)
            return false;
        // if roots->data is matched then we move on to match heads->next on root->left and root->right wherever it is found returns true;
        return head->val == root->val and (dfs(head->next, root->left) or dfs(head->next, root->right));
    }
};