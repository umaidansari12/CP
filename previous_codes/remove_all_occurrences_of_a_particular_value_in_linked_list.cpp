// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
	int data;
	struct Node* next;

	Node(int x) {
		data = x;
		next = NULL;
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
	ListNode* removeElements(ListNode* head, int val) {
		ListNode* head1 = NULL;
		ListNode* prev = NULL;
		ListNode* t = head;
		while (t)
		{
			if (t->val != val)
			{
				if (head1 == NULL)
				{
					head1 = new ListNode(t->val);
					prev = head1;
				}
				else
				{
					ListNode* node = new ListNode(t->val);
					prev->next = node;
					prev = node;
				}
			}
			t = t->next;
		}
		return head1;

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
	ListNode* removeElements(ListNode* head, int val) {
		if (!head)
			return head;
		ListNode* t = head;
		while (t->next)
		{
			if (t->next->val == val)
			{
				t->next = t->next->next;
			}
			else
				t = t->next;
		}
		if (head->val == val)
			head = head->next;
		return head;
	}
};
void append(struct Node** head_ref, struct Node **tail_ref,
            int new_data)
{
	struct Node* new_node = new Node(new_data);
	if (*head_ref == NULL)
		*head_ref = new_node;
	else
		(*tail_ref)->next = new_node;
	*tail_ref = new_node;
}

/* Function to get the middle of the linked list*/
struct Node* deleteAllOccurances(struct Node *head, int );

void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << "\n";
}
int sizeofthelinkedlist(Node* head)
{
	int x = 0;
	while (head != NULL)
	{
		x++;
		head = head->next;
	}
	return x;
}


/* Driver program to test above function*/
int main()
{
	int T, i, n, l;

	// TO BE REMOVED
	for (int i = 0; i < 2000; i++);


	cin >> T;

	while (T--) {
		struct Node *head = NULL,  *tail = NULL;

		cin >> n;
		for (i = 1; i <= n; i++)
		{
			cin >> l;
			append(&head, &tail, l);
		}

		int kk;
		cin >> kk;
		head = deleteAllOccurances(head, kk);
		cout << sizeofthelinkedlist(head) << endl;
		printList(head);
	}
	return 0;
}

// } Driver Code Ends


/* Link list Node
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};*/
/*You are required to complete below method*/
Node* deleteAllOccurances(Node *head, int x)
{
	//Your code here
	Node* head1 = NULL;
	Node* prev = NULL;
	Node* t = head;
	while (t)
	{
		if (t->data != x)
		{
			if (head1 == NULL)
			{
				head1 = new Node(t->data);
				prev = head1;
			}
			else
			{
				Node* node = new Node(t->data);
				prev->next = node;
				prev = node;
			}
		}
		t = t->next;
	}
	return head1;
}

Node* deleteAllOccurances(Node *head, int x)
{
	//Your code here
	Node* temp = head;
	while (head->data == x)
		head = head->next;
	while (temp->next)
	{
		if (temp->next->data == x)
			temp->next = temp->next->next;
		else
			temp = temp->next;
	}
	return head;
}