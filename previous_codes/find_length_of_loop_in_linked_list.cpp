#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	return 0;
}

int countNodesinLoop(struct Node *head)
{
	// Code here
	struct Node* slow = head;
	struct Node* fast = head;
	int count = 0, f = 0;
	while (fast->next && fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			f = 1;
			break;
		}
	}
	if (f)
	{
		fast = head;
		while (slow != fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
		if (slow == fast)
		{
			struct Node* slow = fast;
			count = 1;
			while (slow->next != fast)
			{
				slow = slow->next;
				count++;
			}
		}
	}
	return count;
}