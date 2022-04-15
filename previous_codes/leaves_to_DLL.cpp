/*We need to traverse all leaves and connect them by changing their left and right pointers.
We also need to remove them from Binary Tree by changing left or right pointers in parent nodes.
Add the leaves at the beginning of current linked list and update head of the list using pointer to head pointer.
Since we insert at the beginning, we need to process leaves in reverse order
For reverse order, we first traverse the right subtree then the left subtree.
We use return values to update left or right pointers in parent nodes*/


class Solution {
private:
    Node* head;
    Node *convertToDLL_util(Node *root) {
        if (root == NULL)
            return NULL;
        if (root->left == NULL && root->right == NULL) {
            root->right = head;
            if (head != NULL)
                (head)->left = root;
            head = root;
            return NULL;
        }
        root->right = convertToDLL_util(root->right);
        root->left = convertToDLL_util(root->left);
        return root;
    }

public:
    Node * convertToDLL(Node *root) {
        head = NULL;
        root = convertToDLL_util(root);
        return head;
    }

};
