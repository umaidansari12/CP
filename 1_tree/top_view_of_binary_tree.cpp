#include <bits/stdc++.h>

vector<int> getTopView(TreeNode<int> *root) {
	// Write your code here.
	vector<int> topView;
	if (root == NULL)
		return topView;

	queue<pair<TreeNode<int> *, int>> bfs;
	bfs.push({root, 0});

	map<int, int> level;

	while (!bfs.empty()) {
		TreeNode<int> * current_element = bfs.front().first;
		int hd = bfs.front().second;
		bfs.pop();

		if (level.find(hd) == level.end()) {
			level[hd] = current_element->val;
		}

		if (current_element->left) {
			bfs.push({current_element->left, hd - 1});
		}
		if (current_element->right) {
			bfs.push({current_element->right, hd + 1});
		}
	}

	for (auto lvl : level) {
		topView.push_back(lvl.second);
	}

	return topView;
}

//      1
//   /    \ 
//  4     2
// /     /
// 5    3
//  \ 
//    6
//     \
//      7
//		 \
//		  8
// recursive version fails for this case because first it will go down in left subtree and line 0th when we go down we will the top most node will be
// 8 but as we go down the right subtree it will not change to 2 because it is also lying on 1th line but according to logic this will be the topmost node but since our logic is to include first node encountered on any line
// so we need to make changes and introduce height into our logic as well
// so we will use a pair in map which contains height as well so we will compare if the current row is greater than the encountered row then only we will update the answer otherwise leave it as it is

#include <bits/stdc++.h>

void topViewHelper(TreeNode<int> *root, map<int, int> &level, int current_level) {
	if (root == NULL)
		return;
	if (level.find(current_level) == level.end()) {
		level[current_level] = root->val;
	}

	topViewHelper(root->left, level, current_level - 1);
	topViewHelper(root->right, level, current_level + 1);
}

vector<int> getTopView(TreeNode<int> *root) {
	// Write your code here.
	vector<int> topView;
	if (root == NULL)
		return topView;

	map<int, int> level;

	topViewHelper(root, level, 0);

	for (auto lvl : level) {
		topView.push_back(lvl.second);
	}

	return topView;
}


#include <bits/stdc++.h>

void topViewHelper(TreeNode<int> *root, map<int, pair<int, int>> &level, int current_level, int current_height) {
	if (root == NULL)
		return;

	// if either current_line is not present in map or the height of current line is greater than current_height encountered then update
	if (level.find(current_level) == level.end() or level[current_level].second >= current_height) {
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