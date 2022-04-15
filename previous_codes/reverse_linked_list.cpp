Node* reverseList(Node* head)
{
	if (head == NULL)
		return NULL;
	Node* previous = NULL, current = head, next = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	return previous;
}

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
	ListNode* reverseList(ListNode* head) {
		ListNode* prev = NULL;
		ListNode* next = NULL;
		while (head != NULL)
		{
			next = head->next;
			head->next = prev;
			prev = head;
			head = next;
		}
		return prev;

	}
};

struct Node* reverseList(struct Node *head)
{
	// code here
	// return head of reversed list
	Node* previous = (Node*)malloc(sizeof(Node));
	Node* current = (Node*)malloc(sizeof(Node));
	Node* next = (Node*)malloc(sizeof(Node));
	current = head;
	previous = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	return previous;
}