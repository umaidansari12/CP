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

* ## Preorder Traversal of Binary Tree

```
Problem Statement: Given a binary tree print the preorder traversal of binary tree.

# Recursive Version 

Approach : The idea is to use recursion to first visit root node then move into left subtree and the left subtree is over move into right subtree.

Code : 

void preorder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    // root left right
    cout<<(root->val)<<endl;
    preorder(root->left);
    preorder(root->right);
}

Time Complexity : O(N)
Space Complexity : O(N) // recursive stack space

Note : root is the first node in postorder

# Iterative Version

Approach : The idea is to simulate the recursion using extra stack space so we will push the current node into the stack until it doesn't becomes NULL , also printing the current node and as it becomes null we need to take out the last element in stack and move to its right subtree.

Code :

vector<int> preorderTraversal(TreeNode* root) {
    stack<TreeNode*> recursive_stack;
    vector<int> answer;
    while(true){
        if(root!=NULL){
            answer.push_back(root->val);
            recursive_stack.push(root);
            root = root->left;
        }
        else{
            if(recursive_stack.empty()){
                break;
            }
            
            root = recursive_stack.top();
            recursive_stack.pop();
            
            root = root->right;
            
        }
    }
    return answer;
}

Time Complexity : O(N)
Space Complexity : O(N) // auxilliary stack space

# Iterative Version 2

Approach : use auxilliary stack to first push root node into then process the top of the stack until the stack doesn't becomes empty , first process the top node of stack then push it's right node into the stack first and then left node as the one which go first in stack will be processed in last that is why we are pushing right into stack first then left stack.

Code :

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> answer;
    if (root == NULL)
        return answer;

    stack<TreeNode*> recursive_stack;

    recursive_stack.push(root);

    while (!recursive_stack.empty()) {
        TreeNode* curr = recursive_stack.top();
        recursive_stack.pop();

        answer.push_back(curr->val);

        if (curr->right != NULL)
            recursive_stack.push(curr->right);
        if (curr->left != NULL)
            recursive_stack.push(curr->left);
    }

    return answer;
}

Time Complexity : O(N)
Space Complexity : O(N) // auxilliary stack space
```

* ## Post-Order Traversal Of Binary Tree

```
Problem Statement: Postorder Traversal of a binary tree. Write a program for the postorder traversal of a binary tree.

# Recursive Version

Approach : The idea is to use recursion and move to left subtree then right subtree and then visit the root node.

Code :

void postorder(TreeNode* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout<<(root->val)<<endl;
}

Time Complexity : O(N)
Space Complexity : O(N) // recursive stack space 

# Iterative Version - Using 2 Stacks

Approach : The idea is to visit root but don't process it and process it's left and right subtree first , and move root into another stack ds to process it later.
The fundamental problem we face in this scenario is that there is no way that we can move from a child to the parent using as our node points to only children and not to the parent. To solve this problem, we use an explicit stack data structure. While traversing we can insert node values to the stack in such a way that we always get the next node value at the top of the stack.
we insert in stack 1 in root left right manner , right one is placed at last so that after root it can be processed first and lie below left so that when we pop out from second stack left comes at top after that right and then root.

Note : root is the last node in postorder


Code :

// process left subtree and right subtree first and then process root by pushing them into another stack

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> answer;
    if (root == NULL)
        return answer;

    stack<TreeNode*> recursive_stack;
    stack<TreeNode*> root_process;

    recursive_stack.push(root);

    while (!recursive_stack.empty()) {
        TreeNode* curr = recursive_stack.top();
        recursive_stack.pop();

        root_process.push(curr);

        if (curr->left) {
            recursive_stack.push(curr->left);
        }
        if (curr->right) {
            recursive_stack.push(curr->right);
        }

    }

    while (!root_process.empty()) {
        answer.push_back(root_process.top()->val);
        root_process.pop();
    }

    return answer;
}

Time Complexity : O(N)
Space Complexity : O(N) + O(N) ~ O(N)

# Iterative Version - Using 1 Stack

Approach : The idea is to simulate the recursion by first going to left until it reaches null and then backtrack one step and move to right and again go to left until it reaches null then move to right and then return to root.

Code :


vector<int> postorderTraversal(TreeNode* root) {
    vector<int> answer;
    
    stack<TreeNode*> recursive_stack;
    
    while(root!=NULL or !recursive_stack.empty()){
        if(root!=NULL){
            recursive_stack.push(root);
            root = root->left;
        }
        else{
            TreeNode* right_node = recursive_stack.top()->right;
            // recursive_stack.pop();
            
            // if right subtree is null that means right node is processed and we need to move to root parent                
            if(right_node==NULL){
                right_node = recursive_stack.top();
                recursive_stack.pop();
                answer.push_back(right_node->val);
                
                // the condition to go back to parent
                while(!recursive_stack.empty() and right_node == recursive_stack.top()->right){
                    right_node = recursive_stack.top();
                    recursive_stack.pop();
                    answer.push_back(right_node->val);
                }
                
            }
            // else right subtree is not over and we need to process it
            else
                root = right_node;
        }
    }
    return answer;
}

Time Complexity : O(2N)
Space Complexity : O(N)
```

* ## Morris Inorder Traversal of a Binary tree
```
Problem Statement: Write a program for Morris Inorder Traversal of a Binary Tree.

Approach : The idea is to move into left subtree of every root node and then pointing the rightmost node of that left subtree to point to the root node , this tree is called as threaded binary tree.

Code :

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> answer;
    
    while(root!=NULL){
        // that means there is no left subtree for the root 
        if(root->left==NULL){
            // as there is no subtree just push root node value in the inorder traversal and move to right subtree
            answer.push_back(root->val);
            root = root->right;
        }
        else{
            // there is left subtree we need to move into rightmost node of current left subtree so that we can connect that rightmost node to the current root to create a threaded binary tree then traverse its subtree to create another thread
            TreeNode* previous = root->left;
            while(previous->right!=NULL and previous->right!=root){
                previous = previous->right;
            }
            
            // if thread is not there create a thread and move into left subtree
            if(previous->right==NULL){
                previous->right = root;
                root = root->left;
            }
            // if thread is there remove the thread and then as the left subtree is completed print current root and move to right subtree
            else{
                previous->right = NULL;
                answer.push_back(root->val);
                root = root->right;
            }
        }
    }
    
    return answer;
    
}

Time Complexity : O(N) -> as at every subtree max we are moving is height
Space Complexity : O(1)
```

* ## Morris Preorder Traversal of a Binary Tree

```
Problem Statement: Morris Preorder Traversal of a Binary tree. Given a Binary Tree, find the Morris preorder traversal of Binary Tree.

Approach : The idea is to move into left subtree of every root node and then pointing the rightmost node of that left subtree to point to the root node , this tree is called as threaded binary tree.

Code :

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> answer;

    while (root != NULL) {
        // that means there is no left subtree for the root
        if (root->left == NULL) {
            // as there is no subtree just push root node value in the inorder traversal and move to right subtree
            answer.push_back(root->val);
            root = root->right;
        }
        else {
            // there is left subtree we need to move into rightmost node of current left subtree so that we can connect that rightmost node to the current root to create a threaded binary tree then traverse its subtree to create another thread
            TreeNode* previous = root->left;
            while (previous->right != NULL and previous->right != root) {
                previous = previous->right;
            }

            // if thread is not there create a thread and move into left subtree and before moving into left subtree print the current root node value in preorder traversal
            if (previous->right == NULL) {
                previous->right = root;
                answer.push_back(root->val);
                root = root->left;
            }
            // if thread is there remove the thread and then as the left subtree is completed and move to right subtree
            else {
                previous->right = NULL;
                root = root->right;
            }
        }
    }

    return answer;
}

Time Complexity : O(N) -> as at every subtree max we are moving is height
Space Complexity : O(1)
```

* ## Left view of binary tree
```
Problem Statement: Given a Binary Tree, find the Left view of it. The left view of a Binary Tree is a set of nodes visible when the tree is viewed from the left side.

# Brute

Approach : Use queue to traverse the tree in Bfs manner levelwise and print the first element of every level.

Code :

vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
	vector<int> leftView;
	if(root==NULL){
		return leftView;
	}
	
	queue<TreeNode<int>*> bfs;
	bfs.push(root);
	while(!bfs.empty()){
		int queue_size = bfs.size();
		for(int size = 0;size<queue_size;size++){
			TreeNode<int>* curr_element = bfs.front();
			bfs.pop();
			
			if(size==0){
				leftView.push_back(curr_element->data);
			}
			
			if(curr_element->left)
				bfs.push(curr_element->left);
			if(curr_element->right)
				bfs.push(curr_element->right);			
		}
	}
	return leftView;
}

Time Complexity : O(N)
Space Complexity : O(N)

# Optimal

Approach : The idea is to use recursive level order traversal and simulate(root left right) and as we reach to the first element of the level we will update the maxlevel and push the current root node value into our answer

Code :

void leftViewHelper(TreeNode<int> *root,vector<int> &leftView,int level,int &maxLevel){
	if(root==NULL)
		return;
	
	if(level>maxLevel){
		leftView.push_back(root->data);
		maxLevel = max(level,maxLevel);
	}
	
	leftViewHelper(root->left,leftView,level+1,maxLevel);
	leftViewHelper(root->right,leftView,level+1,maxLevel);
}

vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
	vector<int> leftView;
	int level=0,maxLevel = -1;
	leftViewHelper(root,leftView,level,maxLevel);
	return leftView;
}

Time Complexity : O(N)
Space Complexity : O(H)

```

* ## Right view of binary tree
```
Problem Statement: Given a Binary Tree, find the Right view of it. The right view of a Binary Tree is a set of nodes visible when the tree is viewed from the right side.

# Brute

Approach : The idea is to use level order traversal levelwise and at every level push the last node into the answer.

Code :

//Function to return list containing elements of right view of binary tree.
vector<int> rightView(Node *root)
{
    // Your Code here
    vector<int> rightView;
    if (root == NULL) {
        return rightView;
    }

    queue<Node*> bfs;
    bfs.push(root);
    while (!bfs.empty()) {
        int queue_size = bfs.size();
        for (int size = 0; size < queue_size; size++) {
            Node* curr_element = bfs.front();
            bfs.pop();

            if (size == queue_size - 1) {
                rightView.push_back(curr_element->data);
            }

            if (curr_element->left)
                bfs.push(curr_element->left);
            if (curr_element->right)
                bfs.push(curr_element->right);
        }
    }
    return rightView;
}

Time Complexity : O(N)
Space Complexity : O(N)

# Optimal

Approach : The idea is to use recursive level order traversal and simulate(root right left) and as we reach to the first(here first means rightmost as we doing root right left) element of the level we will update the maxlevel and push the current root node value into our answer

Code :

//Function to return list containing elements of right view of binary tree.
void rightViewHelper(Node *root, vector<int> &rightView, int level, int &maxLevel) {
    if (root == NULL)
        return;

    if (level > maxLevel) {
        rightView.push_back(root->data);
        maxLevel = max(level, maxLevel);
    }

    rightViewHelper(root->right, rightView, level + 1, maxLevel);
    rightViewHelper(root->left, rightView, level + 1, maxLevel);
}
vector<int> rightView(Node *root)
{
    // Your Code here
    vector<int> right_view;
    int level = 0, maxLevel = -1;
    rightViewHelper(root, right_view, level, maxLevel);
    return right_view;
}

Time Complexity : O(N)
Space Complexity : O(H)
```

* ## Bottom view of a Binary Tree

```
Problem Statement: Given a binary tree, print the bottom view from left to right. A node is included in the bottom view if it can be seen when we look at the tree from the bottom.

# BFS Approach 

Approach : Use the vertical order traversal which makes use the concept of line so what we will do is mark an imaginary line on each x-axis and on that we can say that the last node on the line is the bottom view of that x-axis.If there are 2 nodes that are lying on the same x-axis as well as y-axis , we will use the right one into our account.using level order traversal so as to keep the correct level into our answer.

Code :

vector <int> bottomView(Node *root) {
    // Your Code Here
    vector<int> bottom_view;
    if (root == NULL)
        return bottom_view;
    map<int, int> level;
    queue<pair<Node*, int>> bfs;

    bfs.push({root, 0});

    while (!bfs.empty()) {
        Node* current_node = bfs.front().first;
        int hd = bfs.front().second;

        bfs.pop();

        level[hd] = current_node->data;

        if (current_node->left) {
            bfs.push({current_node->left, hd - 1});
        }
        if (current_node->right) {
            bfs.push({current_node->right, hd + 1});
        }
    }

    for (auto lvl : level) {
        bottom_view.push_back(lvl.second);
    }

    return bottom_view;
}

Time Complexity : O(NlogN) -> as used map also and insertion in map takes logn times 
Space Complexity : O(N)

# Recursive Version

Approach : Use the vertical order traversal which makes use the concept of line so what we will do is mark an imaginary line on each x-axis and on that we can say that the last node on the line is the bottom view of that x-axis.If there are 2 nodes that are lying on the same x-axis as well as y-axis , we will use the right one into our account. The recursive fails when left subtree has greater height than right subtree , so we will first traverse the left subtree and include height as well and check if we have the height of current node greater than the height already stored then only we update.


void bottomViewHelper(Node *root, map<int, pair<int, int>> &level, int current_level, int current_height) {
    if (root == NULL)
        return;
    // if height of current node is greater than previously stored then only update the answer to encounter the bottom most node
    if (current_height >= level[current_level].second)
        level[current_level] = {root->data, current_height};
    bottomViewHelper(root->left, level, current_level - 1, current_height + 1);
    bottomViewHelper(root->right, level, current_level + 1, current_height + 1);
}

vector<int> bottomView(Node * root) {
    // map will be <line,<node value,height>>
    // similar to <x-axis,<node value,y-axis>>
    // /Structur of map: colum_no={data,rownumber}
    map<int, pair<int, int>> level;
    int current_level = 0, current_height = 0;
    bottomViewHelper(root, level, current_level, current_height);
    vector<int> bottom_view;
    for (auto lvl : level) {
        bottom_view.push_back(lvl.second.first);
    }
    return bottom_view;
}

Time Complexity : O(NlogN) -> as used map also and insertion in map takes logn times 
Space Complexity : O(N) --> recursive stack space
```

* ## Top view of a Binary Tree

```
Problem Statement: Given below is a binary tree. The task is to print the top view of the binary tree. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.

Approach : Use BFS Traversal to move down every x-axis(line/horizontal distance) and check if the value at this level is present or not , if not then this is the top most node seen on that line , append it to our answer

Code :

vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
	vector<int> topView;
	if(root==NULL)
		return topView;
	
	queue<pair<TreeNode<int> *,int>> bfs;
	bfs.push({root,0});
	
	map<int,int> level;
	
	while(!bfs.empty()){
		TreeNode<int> * current_element = bfs.front().first;
		int hd = bfs.front().second;
		bfs.pop();
		
		if(level.find(hd)==level.end()){
			level[hd] = current_element->val;
		}
		
		if(current_element->left){
			bfs.push({current_element->left,hd-1});
		}
		if(current_element->right){
			bfs.push({current_element->right,hd+1});
		}
	}
	
	for(auto lvl:level){
		topView.push_back(lvl.second);
	}
	
	return topView;
}
Time Complexity : O(NlogN) -> as used map also and insertion in map takes logn times 
Space Complexity : O(N)

# Recursive Approach

Approach : The idea here is to do the traversal in a recursive way but what we need to do is to introduce height into our current logic because we are traversing the left subtree first we encounter the node which are on some line that is not encountered yet so we store it in our answer but as we move to right subtree if we have found a node which are on the similar line but least height so practically that should be included into our answer.

Code :

void topViewHelper(TreeNode<int> *root, map<int, pair<int, int>> &level, int current_level, int current_height) {
	if (root == NULL)
		return;


	if (level.find(current_level)==level.end() or level[current_level].second >= current_height) {
		level[current_level] = {root->val, current_height};
	}

	topViewHelper(root->left, level, current_level - 1, current_height + 1);
	topViewHelper(root->right, level, current_level + 1, current_height + 1);
}

vector<int> getTopView(TreeNode<int> *root) {
	// Write your code here.
	vector<int> topView;
	if (root == NULL)
		return topView;

	// structure => line,<node value,height>
	// x-axis,<node value,y-axis>
	map<int, pair<int, int>> level;

	topViewHelper(root, level, 0, 0);

	for (auto lvl : level) {
		topView.push_back(lvl.second.first);
	}

	return topView;
}

Time Complexity : O(NlogN)
Space Complexity : O(N)
```

* ## Preorder Inorder Postorder Traversals in One Traversal

```
Problem Statement: Preorder Inorder Postorder Traversals in One Traversal. Write a program to print Preorder, Inorder, and Postorder traversal of the tree in a single traversal.

Approach : use stack data structure and at every level you need to store pair<Node,int> int is the number that levels the number of time the current node is being visited

    if num == 1: preorder num++ push left (because of root left right so as root is processed it's time to process left)
    if num == 2: inorder num++ push right (becuase of left root right) so as root is processed it's time to process right)
    if num == 3: postorder (because of left right root as left and right subtree is processed just push root node into your answer)

Code :


vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
	vector<vector<int>> answer;	
	if(root==NULL)
		return answer;
	vector<int> inorder,preorder,postorder;
	stack<pair<BinaryTreeNode<int>*,int>> traverse;
	traverse.push({root,1});//initially we will push root with the number 1 as we are going to visit it first time
	
	while(!traverse.empty()){
		BinaryTreeNode<int>* current_element = traverse.top().first;
		int number = traverse.top().second;
		
		if(number ==1){
			preorder.push_back(current_element->data);
			traverse.top().second = number + 1;
			if(current_element->left)
				traverse.push({current_element->left,1});
		}
		else if(number ==2){
			inorder.push_back(current_element->data);
			traverse.top().second = number + 1;
			if(current_element->right)
				traverse.push({current_element->right,1});
		}
		else if(number == 3){
			postorder.push_back(current_element->data);
			traverse.pop();
		}
	}
	
	return {inorder,preorder,postorder};
	
}

Time Complexity : O(3N)
Space Complexity : O(3N)
```

* ## Vertical Order Traversal of Binary Tree

```
Problem Statement: Vertical Order Traversal Of A Binary Tree. Write a program for Vertical Order Traversal order of a Binary Tree.

# BFS Version

Approach : The idea is to use queue of {root,x,y} and do the traversal and while traversing maintain a ds that will store the nodes in order.

Code :

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
	//    Write your code here.
	vector<int> verticalOrder;

	if (root == NULL)
		return verticalOrder;

	map<int, map<int, vector<int>>> ds;

	queue<pair<TreeNode<int>*, pair<int, int>>> bfs;

	bfs.push({root, {0, 0}});
	while (!bfs.empty()) {
		TreeNode<int>* curr = bfs.front().first;
		int x = bfs.front().second.first;
		int y = bfs.front().second.second;

		ds[x][y].push_back(curr->data);

		bfs.pop();
		if (curr->left) {
			bfs.push({curr->left, {x - 1, y + 1}});
		}
		if (curr->right) {
			bfs.push({curr->right, {x + 1, y + 1}});
		}
	}

	for (auto x : ds) {
		for (auto y : x.second)
			for (auto z : y.second)
				verticalOrder.push_back(z);
	}

	return verticalOrder;
}

Time Complexity : O(NlogN)
Space Complexity : O(N)

# DFS Version

Approach : use any of the traversal and use a ds to store the nodes in order and whenever we move to left change x to x-1 and in right change y to y+1 and all the time y will be increasing.

Code :

void verticalOrderHelper(TreeNode<int>* root, map<int, map<int, vector<int>>> &ds, int x, int y) {
	if (root == NULL)
		return;
	ds[x][y].push_back(root->data);
	verticalOrderHelper(root->left, ds, x - 1, y + 1);
	verticalOrderHelper(root->right, ds, x + 1, y + 1);
}

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
	//    Write your code here.
	vector<int> verticalOrder;

	if (root == NULL)
		return verticalOrder;

	map<int, map<int, vector<int>>> ds;

	verticalOrderHelper(root, ds, 0, 0);

	for (auto x : ds) {
		for (auto y : x.second)
			for (auto z : y.second)
				verticalOrder.push_back(z);
	}

	return verticalOrder;
}


Time Complexity : O(NlogN)
Space Complexity : O(N)
```

* ## Print Root to Node Path in a Binary Tree


```
Problem Statement: Print Root to Node Path In A Binary Tree. Write a program to print path from root to a given node in a binary tree.


Note : If the reference of node to found is given and introduced a parent pointer then we will just start from the root node and move to its parent pointer recursively and get the path.

Approach : The idea is to find the node into left and right subtree and ifto found include that node in path otherwise remove the node from path and return false.

Code :

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

Time Complexity : O(N)
Space Complexity : O(N)
```

* ## Maximum Width of a Binary Tree

```
Problem Statement: Write a program to find the Maximum Width of A Binary Tree.

Note : 
- In problem you just need not to count the maximum number of nodes at the level.
- Here width means the number of nodes in a level between any two nodes.(We are not considering the nodes which don't have left as well as right subtree)

Approach : The idea is to use level order traversal as the width is dependent on level and width on every level is equal to the number of nodes present between the starting and ending node on the level (we will include imaginary node as well if it's parent contain either of the subtree). So to efficiently count the number of nodes at every level we will mark every level with some index so that we just need to do (index of end node - index of start node)+1 to get the width of level. The intuition of this approach comes from segment trees and this approach of marking index with 0 based indexing (where left root will 2*i+1 and right root will be 2*i+2) or 1 based indexing (where left root will be 2*i and right root will be 2*i+1) fails in case of skewed tree because the number of nodes can be as large as 10^5 and doing 2*10^5 can give overflow error and to get rid of this overflow error either we can use unsigned long long int or we can just take out the minimum from every level and while marking index to next level we need to use index = (index - min) so that at next level we start with minimum of previous level and at every 1 can not be minimum as in take the case where at root node we don't have left subtree but has right subtree so at that very moment minimum will be 2.
Edit : We need not to subtract minimum index but we need to subtract maximum index so that at every level we can get minimum.

Code :

int widthOfBinaryTree(TreeNode* root) {
    if(root==NULL)
        return 0;
    // structure of queue is node,index
    queue<pair<TreeNode*,unsigned long long int>> bfs;
    bfs.push({root,0});
    
    int ans = 0;
    
    while(!bfs.empty()){
        int size = bfs.size();
        // int _min = bfs.front().second; // at every level we will have the minimum in front to make the index staring from 0
        int _max_index = bfs.back().second;
        int start_index,end_index;
        
        for(int i=0;i<size;i++){
            
            int curr_index = bfs.front().second - _max_index;
            
            TreeNode* curr_element = bfs.front().first;
            bfs.pop();
            
            if(i==0)
                start_index = curr_index;
            if(i==size-1)
                end_index = curr_index;
            
            if(curr_element->left){
                bfs.push({curr_element->left,2*curr_index+1});
            }
            if(curr_element->right){
                bfs.push({curr_element->right,2*curr_index+2});
            }   
        }
        ans = max(ans,end_index-start_index+1);
    }
    return ans;
}

Time Complexity : O(N)
Space Complexity : O(N)

```