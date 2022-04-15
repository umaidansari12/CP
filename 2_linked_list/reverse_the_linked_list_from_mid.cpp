#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Node {
public:
	int data;
	Node* next;
	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

Node* reverseFromMid(Node* head, Node* mid, int k, int f) {
	if (!head)
		return NULL;
	Node* current = head;
	Node* prev = NULL;
	Node* next = NULL;
	int count = 0;
	while (current != NULL and count < k) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		count++;
	}
	if (next != NULL and f) {
		head->next = reverseFromMid(next, mid, k, f);
	}
	else if (next != NULL and !f) {
		head->next = reverseFromMid(next, mid, k, f);
	}
	return prev;
}


int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n;
		Node* head = NULL;
		Node* prev = NULL;
		Node* mid = NULL;
		for (int i = 1; i <= n; i++) {
			cin >> x;
			if (head == NULL) {
				head = new Node(x);
				prev = head;
			}
			else {
				prev->next = new Node(x);
				prev = prev->next;
			}
			if (i == (n / 2)) {
				mid = prev;
			}
		}
		head = reverseFromMid(head, mid, n / 2, n % 2 == 0);
		Node* curr = head;
		while (curr) {
			cout << curr->data << " ";
			curr = curr->next;
		}
		cout << endl;
	}

	return 0;
}