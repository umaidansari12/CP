#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		map<ListNode*, int> m;
		while (head)
		{
			if (m.find(head) != m.end())
				return head;
			m[head]++;
			head = head->next;
		}
		return head;

	}
};

ListNode* Solution::detectCycle(ListNode* A) {
	// Do not write main() function.
	// Do not read input, instead use the arguments to the function.
	// Do not print the output, instead return values as specified
	// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	if (A == NULL || A->next == NULL)
		return NULL;
	ListNode* slow = A;
	ListNode* fast = A;
	int flag = 0;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		if (fast->next == NULL)
			return NULL;
		else
			fast = fast->next->next;
		if (slow == fast)
		{
			flag = 1;
			break;
		}
	}
	if (flag)
	{
		slow = A;
		while (slow != fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
	}
	return NULL;
}


class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		ListNode* slow = head;
		ListNode* fast = head;
		int flag = 0;
		while (fast != NULL && fast->next != NULL)
		{
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
			{
				flag = 1;
				break;
			}
		}
		if (flag)
		{
			slow = head;
			while (slow != fast)
			{
				fast = fast->next;
				slow = slow->next;
			}
			return slow;
		}
		return NULL;

	}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		if (head == NULL || head->next == NULL)
			return NULL;
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast->next && fast->next->next)
		{
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
			{
				fast = head;
				while (slow != fast)
				{
					slow = slow->next;
					fast = fast->next;
				}
				if (slow == fast)
					return slow;
			}

		}


		return NULL;

	}
};