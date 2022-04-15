#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Node {
public:
	int data;
	Node* left;
	Node* right;
	Node(int data) {
		this->data = data;
		this->left = this->right = NULL;
	}
};

Node* buildTree() {

	int d;
	cin >> d;


	if (d == -1) {
		return NULL;
	}

	Node* n = new Node(d);
	n->left = buildTree();
	n->right = buildTree();

	return n;
}

void printLevelOrder(Node* root) {
	if (!root)
		return;
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			Node* curr = q.front();
			cout << curr->data << " ";
			q.pop();
			if (curr->left)
				q.push(curr->left);
			if (curr->right)
				q.push(curr->right);
		}
		cout << endl;
	}
}


void findSum(Node* root, int k, deque<int> &q, int &sum) {
	if (!root)
		return;
	if (q.size() == k) {
		if (q.front() % 2 == 0) {
			sum += root->data;
		}
		q.pop_front();
	}
	q.push_back(root->data);
	findSum(root->left, k, q, sum);
	findSum(root->right, k, q, sum);

}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Node* root = buildTree();
	printLevelOrder(root);
	int k, sum = 0;
	cin >> k;
	//cout << k << endl;
	deque<int> q;
	findSum(root, k, q, sum);
	cout << sum << endl;
	return 0;
}