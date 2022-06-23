* ## Level Order Traversal of a Binary Tree

```
Problem Statement: Level order traversal of a binary tree. Given the root node of the tree and you have to print the value of the level of the node by level.

Approach : The idea is to use queue to store nodes at every level by using size = queue.size() which marks the number of nodes at the current level.

Code :

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> lvls;
    if (!root)
        return lvls;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int _size = q.size();
        vector<int> lvl;
        while (_size--) {
            TreeNode* curr = q.front();
            q.pop();

            lvl.push_back(curr->val);

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        lvls.push_back(lvl);
    }

    return lvls;
}

vector<int> getLevelOrder(TreeNode<int> *root)
{
    //  Write your code here.
    vector<int> r;
    if (!root)
        return r;
    queue<TreeNode<int>*> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode<int> *cur = q.front();
        q.pop();
        r.push_back(cur->val);
        if (cur->left)
            q.push(cur->left);
        if (cur->right)
            q.push(cur->right);
    }
    return r;

}

Time Complexity : O(N)
Space Complexity : O(N)
```

* ## Maximum depth of a Binary Tree

```
Problem Statement: Find the Maximum Depth of Binary Tree. Maximum Depth is the count of nodes of the longest path from the root node to the leaf node.

# Recursive Version

Approach : Use the recurrence relation for every node , the height will be 1+max(height(left),height(right))

Code :

int maxDepth(TreeNode* root) {
    if(root==NULL){
        return 0;
    } 
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    
    return 1+max(left,right);
    
}

Time Complexity : O(N)
Space Complexity : O(N)

# BFS Version 

Approach : Use the level order traversal and use queue of pair node , level which stores the level number so whenever you come across any node you check if this level is greater than previous encountered level , if yes then update as it will be the maximum depth.

Code :

int maxDepth(TreeNode* root) {
    if(root==NULL){
        return 0;
    }
    // node.level
    queue<pair<TreeNode*,int>> bfs;
    bfs.push({root,0});
    int height = 0;
    
    while(!bfs.empty()){
        TreeNode* curr = bfs.front().first;
        int level = bfs.front().second;
        bfs.pop();
        height = max(height,level);
        if(curr->left){
            bfs.push({curr->left,level+1});
        }
        if(curr->right){
            bfs.push({curr->right,level+1});
        }
    }
    return height+1;
}

Time Complexity : O(N)
Space Complexity : O(N)
```

* ## Calculate the Diameter of a Binary Tree

```
Problem Statement: Find the Diameter of a Binary Tree. Diameter is the length of the longest path between any 2 nodes in the tree and this path may or may not pass from the root.

Note : 
    - The diamter is the longest path between any 2 nodes
    - The path need not to pass via root


# Brute 

Approach : we will check for each node considering it as a curve point the maximum of left height + right height we are going on every node , calculating it's left path and right path and comparing with maximum as it is longest path between two nodes

Code :

int height(TreeNode<int> *root){
	if(root==NULL){
		return 0;
	}
	
	int leftHeight = height(root->left);
	int rightHeight = height(root->right);
	
	return 1+max(leftHeight,rightHeight);
}

void diameterHelper(TreeNode<int> *root,int &_max){
	if(root==NULL){
		return;
	}
	
	int leftHeight = height(root->left);
	int rightHeight = height(root->right);
	
	_max =  max(leftHeight+rightHeight,_max);
	diameterHelper(root->left,_max);
	diameterHelper(root->right,_max);
	
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
	// Write Your Code Here.
	int answer = 0;
	diameterHelper(root,answer);
	return answer;
}

Time Complexity : O(N^2)
Space Complexity : O(H)

# Optimal 
Approach : Instead of calculating height at every junction , we will calculate height and while calculating height we will keep track of maximum of (leftheight+rightheight)

Code :

int diameterHelper(TreeNode<int> *root,int &_max){
	if(root==NULL){
		return 0;
	}
	
	int leftHeight = diameterHelper(root->left,_max);
	int rightHeight = diameterHelper(root->right,_max);
	
	diameter =  max(leftHeight+rightHeight,diameter);
	
	return 1+max(leftHeight,rightHeight);
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
	// Write Your Code Here.
	int diameter = 0;
	diameterHelper(root,answer);
	return diameter;
}

Time Complexity : O(N)
Space Complexity : O(H)

```

* ## Check if the Binary Tree is Balanced Binary Tree

```
Problem Statement: Check whether the given Binary Tree is a Balanced Binary Tree or not. A binary tree is balanced if, for all nodes in the tree, the difference between left and right subtree height is not more than 1.

# Brute

Approach : the empty tree is considered as height balanced which forms the base case and for every root node we calculate the height of left subtree of the root and right subtree of the root and then recursively check if the left subtree as well as right subtree is balanced or not.

Code :

int height(BinaryTreeNode<int> *root) {
	if (root == NULL) {
		return 0;
	}

	int leftHeight = height(root->left);
	int rightHeight = height(root->right);

	return 1 + max(leftHeight, rightHeight);
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
	// Write your code here.
	if (root == NULL) {
		return true;
	}

	int leftHeight = height(root->left);
	int rightHeight = height(root->right);

	if (abs(leftHeight - rightHeight) <= 1 and isBalancedBT(root->left) and isBalancedBT(root->right))
		return true;

	return false;
}

Time Complexity : O(N^2)
Space Complexity : O(H)

# Optimal 

Approach : We need to reduce extra N time we are taking to calculate the height at every root node , for this we need to use postorder traversal and ca1culate the height of the tree simultaneously as we move down the line

Code : 

int isBalancedBTHelper(BinaryTreeNode<int>* root){
	if(root==NULL){
		return 0;
	}
	
	int leftHeight = isBalancedBTHelper(root->left);
	int rightHeight = isBalancedBTHelper(root->right);
	
	if(leftHeight==-1 or rightHeight==-1)
		return -1;
	
	
	if(abs(leftHeight-rightHeight)>1){
		return -1;
	}
	
	return 1+max(leftHeight,rightHeight);
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
	return isBalancedBTHelper(root)!=-1;
}

pair<int, bool> isBalancedBTHelper(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return {0, true};
	}

	pair<int, bool> leftHeight = isBalancedBTHelper(root->left);
	pair<int, bool> rightHeight = isBalancedBTHelper(root->right);

	if (abs(leftHeight.first - rightHeight.first) <= 1 and leftHeight.second and rightHeight.second) {
		return {1 + max(leftHeight.first, rightHeight.first), true};
	}

	return {1 + max(leftHeight.first, rightHeight.first), false};
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
	// Write your code here.
	return isBalancedBTHelper(root).second;
}

Time Complexity : O(N)
Space Complexity : O(H)
```

* ## Lowest Common Ancestor for two given Nodes

```
# Brute

Approach : Find path of x from root node till x and path of y from root node till y and store in some data structure , now as lowest common ancestor is the deepest node that is matching so we will traverse the path ds to check for matching and break at the last matching point

Code :

bool findPath(Node* root, int n, vector<Node*> &r) {
    if (!root)
        return false;
    r.push_back(root);
    if (root->data == n)
        return true;
    if (findPath(root->left, n, r) or findPath(root->right, n, r))
        return true;
    r.pop_back();
    return false;

}
Node* lca(Node* root , int n1 , int n2 )
{
    //Your code here
    vector<Node*> p, q;
    if (!findPath(root, n1, p) or !findPath(root, n2, q))
        return NULL;
    Node* ans = NULL;
    for (int i = 0; i < min(p.size(), q.size()); i++) {
        if (p[i]->data != q[i]->data)
        {
            break;
        }
        else
            ans = p[i];
    }
    return ans;
}

Time Complexity : O(2N)
Space Complexity : O(2N)

# Optimal

Approach : We will use a single traversal technique to find both the nodes with value x and y , for every root node we will recur for it's left as well right subtree to find the x and y nodes if tne left subtree returns null that means we have'nt found x and y in left subtree of root node , so we will return right subtree which signifies that x and y is present in right subtree and if both the left and right subtree is not null that means x and y is found under the root node so we will return root as our answer.

Code :

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // if root is null or root's value is equal to x or root's value is equal to y return the root
    if (root == NULL or root->val == p->val or root->val == q->val) {
        return root;
    }

    // recur for left as well as right subtree for the current node
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    // if leftsubtree is null that means we have'nt found x and y in left subtree so it must lie in right subtree
    if (left == NULL)
        return right;
    // if rightsubtree is null that means we have'nt found x and y in right subtree so it must lie in left subtree
    else if (right == NULL)
        return left;
    // if both the subtrees are not null that means we have found x and y in left and right subtrees so the root is the lowest common ancestor
    else {
        return root;
    }
}
```