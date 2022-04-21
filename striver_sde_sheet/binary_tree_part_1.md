* ## Inorder Traversal of Binary Tree

```
Problem Statement: Given a Binary Tree. Find and print the inorder traversal of Binary Tree.

# Recursive Version 

Approach : The idea is to use recursion to first move into the left subtree and after coming from the left subtree need to print root's value and move into right subtree.

Code :

void inorder(TreeNode* root){
    if(root==NULL){
        return;
    }
    // left -> root -> right
    inorder(root->left);
    cout<<(root->val)<<endl;
    inorder(root->right);
}

Time Complexity : O(N)
Space Complexity : O(N) // Recursive stack space

# Iterative Version

Approach : We need to simulate the stack trace as being done in recursion , so push the current node into the stack until it's left pointer becomes null, if the current node becomes null then you need to pop out the last node in stack print it and make the current node equals to it's right so that it can move to its right subtree , we need to do the above steps until it stack becomes empty.

Code : 

vector<int> inorderTraversal(TreeNode* root) {
    stack<TreeNode*> recursive_stack;
    vector<int> answer;
    while(true){
        if(root!=NULL){
            recursive_stack.push(root);
            root=root->left;
        } 
        else{
            if(recursive_stack.empty()){
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

Time Complexity : O(N)
Space Complexity : O(N) // Auxilliary stack space
```