
#include <bits/stdc++.h>

bool detectCycle(Node *head)
{
	//	Write your code here
	unordered_set<Node*> found;
	while (head) {
		if (found.find(head->next) != found.end())
			return true;
		found.insert(head);
		head = head->next;
	}
	return false;
}

bool detectCycle(Node *head)
{
	//	Write your code here
	Node* slow = head;
	Node* fast = head;
	// we are checking if fast pointer doesnt becomes null because null indicates that there is no cycle  and if there is a cycle then fast and slow pointer are bound to meet at some point in the cycle
	while (fast->next and fast) {
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow)
			return true;
	}

	return false;
}