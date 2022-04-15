#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Node {
public:
	int data;
	Node* next;
	Node(int x)
	{
		this->data = x;
		this->next = NULL;
	}
};

class LinkedList
{
public:
	Node* head = NULL;
	void insert(int x)
	{
		if (head == NULL)
		{
			head = new Node(x);
		}
		else
		{
			Node* node = new Node(x);
			node->next = head;
			head = node;
		}
	}
	void pop()
	{
		if (head == NULL)
			return;
		else
		{
			Node* node = head;
			head = head->next;
			delete node;
		}
	}
	int peek()
	{
		if (head != NULL)
			return head->data;
		return 0;
	}
	void display()
	{
		Node* node = head;
		while (node != NULL)
		{
			cout << node->data << " ";
			node = node->next;
		}
		cout << endl;
	}
};

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q;
	cin >> q;
	LinkedList l;
	while (q--)
	{
		int i;
		cin >> i;
		l.insert(i);
		l.display();
	}
	l.pop();
	l.display();
	l.insert(6);
	l.display();
	l.pop();
	l.display();
	l.insert(7);
	l.display();


	return 0;
}