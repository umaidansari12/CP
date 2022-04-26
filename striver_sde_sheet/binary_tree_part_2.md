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