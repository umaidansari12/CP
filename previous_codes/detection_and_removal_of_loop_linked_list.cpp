/*Input:
5
7 58 36 34 16
1

Its Correct output is:
1

And Your Code's output is:
0
This is the case where our code fails because the starting point of the loop is the
head of the list and it is making circular list and it is the corner case kindly
visualize it on pen annd paper*/

void removeLoop(Node* head)
{
	// code here
	// just remove the loop without losing any nodesh
	if (head == NULL && head->next == NULL)
		return;
	Node* slow = head;
	Node* fast = head;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		if (fast->next == NULL)
			return;
		else
			fast = fast->next->next;
		if (slow == fast)
			break;
	}
	//this is the condition to check for corner cases and
	//when the slow and fast next element will be head then
	// an infinite loop will  occur where fast next point to previous node of slow and
	//this way they will never become equal
	if (slow == head)
	{
		while (slow->next != head)
			slow = slow->next;
		slow->next = NULL;
	}
	if (slow == fast)
	{
		slow = head;
		while (slow->next != fast->next)
		{
			slow = slow->next;
			fast = fast->next;
		}
		fast->next = NULL;
	}
}

void removeLoop(Node* head)
{
	// code here
	// just remove the loop without losing any nodes
	Node* fast = head;
	Node* slow = head;
	int f = 0;
	while (fast->next && fast->next->next)
	{
		fast = fast->next->next;
		slow = slow->next;
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
			fast = fast->next;
			slow = slow->next;
		}
		if (slow == fast)
		{
			slow = fast;
			while (fast->next != slow)
			{
				fast = fast->next;
			}
			fast->next = NULL;
		}
	}

}

Node * breakChain(Node * head) {
	//Complete this method


	set<Node*> s;
	Node* temp = head;
	while (temp != NULL)
	{
		if (s.find(temp->next) != s.end())
		{
			temp->next = NULL;
			return head;
		}
		s.insert(temp);
		temp = temp->next;
	}
	return head;


}
