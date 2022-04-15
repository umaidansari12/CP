#include <bits/stdc++.h>

using namespace std;
using ll = long long;


//Reverse lists and add nodes one by one. Also keep track of carry.
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

Node* reverse(Node *head)
// this function reverses the linked list
{
	Node * prev = NULL;
	Node * current = head;
	Node * next;

	while (current != NULL)
	{
		next = current->next;     // storing next node
		current->next = prev;     // linking current node to previous
		prev = current;           // updating prev
		current = next;           // updating current
	}

	return prev;
}

struct Node* addTwoLists(struct Node* first, struct Node* second)
{
	first = reverse(first);              // reversing lists
	second = reverse(second);            // to simplify addition

	Node *sum = NULL;
	int carry = 0;

	while ( first != NULL || second != NULL || carry != 0 )
	{
		int newVal = carry;
		if (first) newVal += first->data;
		if (second) newVal += second->data;
		// newly value for sumList is sum of carry and respective
		// digits in the 2 lists

		carry = newVal / 10;             // updating carry
		newVal = newVal % 10;            // making sure newVal is <10

		Node* newNode = new Node(newVal);
		newNode->next = sum;             // appending newVal node
		sum = newNode;

		if (first) first = first->next;    // moving to next node
		if (second) second = second->next;
	}

	return sum;
}


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

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* start = new ListNode();
		int carry = 0;
		ListNode* temp = start;
		while (l1 != NULL || l2 != NULL || carry)
		{
			int sum = 0;
			if (l1)
			{
				sum += l1->val;
				l1 = l1->next;
			}
			if (l2)
			{
				sum += l2->val;
				l2 = l2->next;
			}
			sum += carry;
			carry = sum / 10;
			temp->next = new ListNode(sum % 10);
			temp = temp->next;
		}
		return start->next;

	}
};

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


/*class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int sum = 0, carry = 0;
		ListNode* newNode;
		ListNode* prev = NULL;
		ListNode* res = NULL;
		while (l1 != NULL || l2 != NULL)
		{
			sum = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
			carry = (sum >= 10) ? 1 : 0;
			sum = sum % 10;
			newNode = new ListNode(sum);
			if (res == NULL)
				res = newNode;
			else
				prev->next = newNode;
			prev = newNode;
			if (l1)
				l1 = l1->next;
			if (l2)
				l2 = l2->next;
		}
		if (carry > 0)
			newNode->next = new ListNode(carry);
		return res;
	}
};*/


Node* addSameSize(Node* head1, Node* head2, int* carry)
{
	// Your code here
	Node*temp;
	int car = 0;
	if (head1 == NULL || head2 == NULL)
		return NULL;
	temp = addSameSize(head1->next, head2->next, carry);
	car = (head1->data) + (head2->data) + (*carry);
	head2->data = (car) % 10;
	*carry = (car) / 10;
	return head2;
}

void addCarryToRemaining(Node* head1, Node* curr, int* carry, Node** result)
{
	// Your code here
	// Your code here
	if (head1 == curr)
		return;
	int car;
	addCarryToRemaining(head1->next, curr, carry, result);
	if (head1->next == curr)
	{
		head1->next = *result;
	}
	car = (head1->data + *carry);
	head1->data = car % 10;
	*(carry) = (car) / 10;
	*result = head1;
}