int getMiddle(Node* head)
{
	if (head == NULL)
		return -1;
	Node* slow = head, fast = head;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow->data;
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
	ListNode* middleNode(ListNode* head) {
		int count = 0;
		ListNode* curr = head;
		while (curr != NULL)
		{
			curr = curr->next;
			count++;
		}
		int mid = count / 2;
		while (mid--)
			head = head->next;
		return head;



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
	ListNode* middleNode(ListNode* head) {
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast != NULL && fast->next != NULL)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;

	}
};