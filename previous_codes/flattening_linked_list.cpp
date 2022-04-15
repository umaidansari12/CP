/*Given a Linked List of size N, where every node represents a linked list and contains two pointers of its type:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.

Note: The flattened list will be printed using the bottom pointer instead of next pointer.

Example 1:

Input:
5 -> 10 -> 19 -> 28
|     |     |     |
7     20    22   35
|           |     |
8          50    40
|                 |
30               45
Output:  5-> 7-> 8- > 10 -> 19-> 20->
22-> 28-> 30-> 35-> 40-> 45-> 50.

Note: | represents the bottom pointer.
Your Task:
You need to complete the function flatten() that takes head of the list as parameter and returns the root of flattened list. The printing is done by the driver code.

Note: Try to solve the problem without using any extra space.

Expected Time Complexity: O(N*M)
Expected Auxiliary Space: O(1)

Constraints:
0 <= N <= 50
1 <= Mi <= 20
1 <= Element of linked list <= 103*/

#include <bits/stdc++.h>

using namespace std;
//using ll = long long;

Node* merge(Node* a, Node* b)
{
	Node* res = new Node(0);
	Node* temp = res;
	while (a != NULL && b != NULL)
	{
		if (a->data <= b->data)
		{
			temp->bottom = a;
			temp = temp->bottom;
			a = a->bottom;
		}
		else
		{
			temp->bottom = b;
			temp = temp->bottom;
			b = b->bottom;
		}
	}
	if (a != NULL)
		temp->bottom = a;
	else
		temp->bottom = b;
	return res->bottom;

}
Node *flatten(Node *root)
{
	// Your code here
	if (root == NULL || root->next == NULL)
		return root;
	root->next = flatten(root->next);
	root = merge(root, root->next);
	return root;
}

class Node {
public:
	int data;
	Node* next;
	//Node* down;
	Node(int x)
	{
		this->data = x;
		this->next = NULL;
		//this->down = NULL;
	}

};

void insert(Node* head, Node* prev, int x)
{
	Node* newNode = new Node(x);
	if (head == NULL)
		head = newNode;
	else
		prev->next = newNode;
	prev = newNode;
}

void print(Node* head)
{
	Node* current = head;
	while (current)
	{
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}


Node* merge(Node* first, Node* second)
{
	if (first == NULL)
		return second;
	if (second == NULL)
		return first;
	Node* result;
	if (first->data < second->data)
	{
		result = first;
		result->bottom = merge(first->bottom, second);
	}
	else
	{
		result = second;
		result->bottom = merge(first, second->bottom);
	}
	result->next = NULL;
	return result;
}
Node *flatten(Node *root)
{
	// Your code here
	if (root == NULL || root->next == NULL)
		return root;
	root->next = flatten(root->next);
	root = merge(root, root->next);
	return root;
}


int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	Node* head = NULL;
	Node* prev = NULL;
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		insert(head, prev, x);
	}
	print(head);


	return 0;
}


