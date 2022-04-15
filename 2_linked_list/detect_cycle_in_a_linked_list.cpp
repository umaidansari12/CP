
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