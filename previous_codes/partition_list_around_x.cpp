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

class LinkedList {
private:
	Node* head;
public:
	LinkedList()
	{
		head = NULL;
	}
	void insert(int x)
	{
		Node* newNode = new Node(x);
		if (head == NULL)
		{
			head = newNode;
		}
		else
		{
			Node* current = head;
			while (current->next != NULL)
			{
				current = current->next;
			}
			current->next = newNode;
		}

	}
	void print()
	{
		Node* current = head;
		while (current != NULL)
		{
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}

	void partition(int x)
	{
		Node* current = head;
		Node* right = NULL;
		Node* left = NULL;
		while (current != NULL)
		{
			if (current->data >= x)
			{
				if (right == NULL)
				{
					Node* p = new Node(current->data);
					right = p;
				}
				else
				{
					Node* p = right;
					Node* newNode = new Node(current->data);
					while (p->next != NULL)
						p = p->next;
					p->next = newNode;
				}
			}
			else
			{
				if (left == NULL)
				{
					Node* p = new Node(current->data);
					left = p;
				}
				else
				{
					Node* newNode = new Node(current->data);
					Node* p = left;
					while (p->next != NULL)
						p = p->next;
					p->next = newNode;
				}
			}
			current = current->next;
		}
		if (left == NULL)
		{
			left = right;
		}
		else
		{
			Node* p = left;
			while (p->next != NULL)
				p = p->next;
			p->next = right;
		}
		head = left;
	}


};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		ListNode* beforeStart = NULL;
		ListNode* beforeEnd = NULL;
		ListNode* afterStart = NULL;
		ListNode* afterEnd = NULL;
		ListNode* next = NULL;
		while (head)
		{
			next = head->next;
			ListNode * node = new ListNode(head->val);
			head->next = NULL;
			if (head->val < x)
			{
				if (beforeStart == NULL)
				{
					beforeStart = node;
					beforeEnd = beforeStart;
				}
				else
				{
					beforeEnd->next = node;
					beforeEnd = node;
				}
			}
			else
			{
				if (afterStart == NULL)
				{
					afterStart = node;
					afterEnd = afterStart;
				}
				else
				{
					afterEnd->next = node;
					afterEnd = node;
				}
			}
			head = next;
		}
		if (beforeStart == NULL)
			return afterStart;
		beforeEnd->next = afterStart;
		return beforeStart;

	}
};

/*
class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		ListNode* current = head;
		ListNode* left = NULL;
		ListNode* right = NULL;
		while (current != NULL)
		{
			if (current->val >= x)
			{
				if (right == NULL)
				{
					ListNode* p = new ListNode(current->val);
					right = p;
				}
				else
				{
					ListNode* p = right;
					ListNode* newNode = new ListNode(current->val);
					while (p->next != NULL)
						p = p->next;
					p->next = newNode;
				}
			}
			else
			{
				if (left == NULL)
				{
					ListNode* p = new ListNode(current->val);
					left = p;
				}
				else
				{
					ListNode* p = left;
					ListNode* newNode = new ListNode(current->val);
					while (p->next != NULL)
						p = p->next;
					p->next = newNode;
				}
			}
			current = current->next;
		}
		if (left == NULL)
		{
			left = right;
		}
		else
		{
			ListNode* p = left;
			while (p->next != NULL)
				p = p->next;
			p->next = right;
		}
		head = left;
		return head;
	}
};
*/
int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		LinkedList l ;
		int x;
		for (int i = 0; i < N; i++)
		{
			cin >> x;
			l.insert(x);
		}
		cin >> x;
		l.print();
		l.partition(x);
		l.print();
		cout << "Done" << endl;
	}


	return 0;
}