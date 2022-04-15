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
public:
	Node* head;
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
};

/*vector<int> sum_list(Node* l1, Node* l2)
{
	vector<int> l3;
	int sum = 0, carry = 0;
	while (l1 != NULL && l2 != NULL)
	{
		int a = l1 ? l1->data : 0, b = l2 ? l2->data : 0;
		//cout << carry << endl;
		sum = ((carry + a + b) >= 10) ? (carry + a + b) % 10 : (carry + a + b);
		carry = ((carry + a + b) >= 10) ? 1 : 0;
		//cout << sum << " " << carry << endl;
		l3.push_back(sum);
		/*Node* newNode = new Node(sum);
		Node* current = l3.head;
		if (current == NULL)
		{
			current = newNode;
		}
		else
		{
			while (current->next != NULL)
				current = current->next;
			current->next = newNode;
		}
		l1 = l1->next;
		l2 = l2->next;
	}
	return l3;
}
*/

Node* sum_list(Node* l1, Node* l2)
{
	int sum = 0, carry = 0;
	Node* prev = NULL;
	Node* res = NULL;
	Node* newNode = NULL;
	while (l1 != NULL || l2 != NULL)
	{
		int a = l1 ? l1->data : 0, b = l2 ? l2->data : 0;
		sum = ((carry + a + b) >= 10) ? (carry + a + b) % 10 : (carry + a + b);
		carry = ((carry + a + b) >= 10) ? 1 : 0;
		newNode = new Node(sum);
		if (res == NULL)
		{
			res = newNode;
		}
		else
		{
			prev->next = newNode;
		}
		prev = newNode;
		if (l1)
			l1 = l1->next;
		if (l2)
			l2 = l2->next;
	}
	if (carry > 0)
	{
		newNode->next = new Node(carry);
	}
	return res;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n, m, x;
		cin >> n;
		LinkedList l1, l2;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			l1.insert(x);
		}
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> x;
			l2.insert(x);
		}
		//l1.print();
		Node* l3 = sum_list(l1.head, l2.head);
		while (l3 != NULL)
		{
			cout << l3->data << " ";
			l3 = l3->next;
		}
		cout << endl;
		/*vector<int> l3 = sum_list(l1.head, l2.head);
		for (int i : l3)
		{
			cout << i << "->";
		}
		cout << endl;*/
	}


	return 0;
}