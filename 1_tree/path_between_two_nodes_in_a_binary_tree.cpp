#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Node {
public:
	Node* left;
	Node* right;
	int data;
	Node(int d) {
		left = NULL;
		right = NULL;
		data = d;
	}
};


Node* buildTree() {
	int d;
	cin >> d;
	if (d == -1) {
		return NULL;
	}

	Node* node = new Node(d);
	node->left = buildTree();
	node->right = buildTree();
	return node;
}

void preorder(Node* root) {
	if (!root)
		return;
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

void levelOrder(Node* root) {
	if (!root)
		return;

	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			Node* node = q.front();
			q.pop();

			cout << node->data << " ";
			if (node->left)
				q.push(node->left);
			if (node->right)
				q.push(node->right);
		}
		cout << endl;
	}
}

bool getPath(Node* root, int node, vector<int> &path) {
	if (!root)
		return false;


	path.push_back(root->data);

	if (root->data == node)
		return true;

	if (getPath(root->left, node, path) or getPath(root->right, node, path))
		return true;

	path.pop_back();
	return false;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	cin >> t;
	while (t--) {
		Node* root = buildTree();
		levelOrder(root);
		cout << endl;
		int n1, n2;
		cin >> n1 >> n2;

		vector<int> path1, path2;

		getPath(root, n1, path1);
		getPath(root, n2, path2);

		for (int i = 0; i < path1.size(); i++) {
			cout << path1[i] << " ";
		}
		cout << endl;
		for (int i = 0; i < path2.size(); i++) {
			cout << path2[i] << " ";
		}
		cout << endl;

		int intersection = -1;

		for (int i = 0; i < min(path1.size(), path2.size()); i++) {
			if (path1[i] != path2[i]) {
				intersection = i - 1;
				break;
			}
		}

		for (int i = path1.size() - 1; i > intersection; i--) {
			cout << path1[i] << " ";
		}

		for (int i = intersection; i < path2.size(); i++) {
			cout << path2[i] << " ";
		}

		cout << endl;



	}


	return 0;
}

