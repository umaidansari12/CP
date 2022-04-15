#include <bits/stdc++.h>
using namespace std;

RandomListNode* Solution::copyRandomList(RandomListNode* A) {
	if (!A)
		return NULL;

	RandomListNode* head = A;

	while (A)
	{
		RandomListNode* copyA = new RandomListNode(A->label);
		copyA->next = A->next;
		A->next = copyA;
		A = copyA->next;
	}
	A = head;

	while (A)
	{
		if (!A->random)             // I missed this check.
			A->next->random = NULL;
		else
			A->next->random = A->random->next;

		A = A->next->next;
	}
	A = head;

	RandomListNode* copy = A->next;
	RandomListNode* copyHead = A->next;

	while (A)
	{
		A->next = A->next->next;
		A = A->next;
		if (!copy->next)            // I missed this check.
			break;
		copy->next = copy->next->next;
		copy = copy->next;
	}

	return copyHead;
	/*RandomListNode* iter=A;
	RandomListNode* front=A;
	while(iter!=NULL)
	{
	    front=iter->next;
	    RandomListNode* copy = new RandomListNode(iter->label);
	    iter->next=copy;
	    iter=front;
	}
	iter=A;
	while(iter!=NULL)
	{
	    front=iter->next->next;
	    if(iter->random!=NULL)
	    iter->next->random=iter->random->next;
	    else
	    iter->next->random=NULL;
	    iter=iter->next->next;
	}
	iter = A;
	RandomListNode* pseudoHead=new RandomListNode(0);
	RandomListNode* copy=pseudoHead;
	while(iter!=NULL)
	{
	    front=iter->next->next;
	    copy->next=iter->next;
	    iter->next=front;
	    copy=copy->next;
	    iter=iter->next;
	}*/
	//return pseudoHead->next;
}

class Solution {
public:
	Node* copyRandomListBrute(Node* head) {
		Node* curr = head;
		unordered_map<Node*, Node*> m;
		while (curr)
		{
			m[curr] = new Node(0);
			m[curr]->val = curr->val;
			curr = curr->next;
		}
		curr = head;
		while (curr)
		{
			m[curr]->next = m[curr->next];
			m[curr]->random = m[curr->random];
			curr = curr->next;
		}
		return m[head];

	}
	Node* copyRandomList(Node* head) {
		Node* iter = head;
		Node* front = head;
		//1st step creation of deep copy nodes and pointing them as next of original node
		// First round: make copy of each node,
		// and link them together side-by-side in a single list.
		while (iter != NULL)
		{
			front = iter->next;
			Node* copy = new Node(iter->val);
			iter->next = copy;
			copy->next = front;
			iter = front;
		}
		//2nd step creation and pointing of random pointer
		// Second round: assign random pointers for the copy nodes.
		iter = head;
		while (iter != NULL)
		{
			front = iter->next->next;
			if (iter->random != NULL)
				iter->next->random = iter->random->next;
			iter = iter->next->next;
		}
		//segregation of original and deep copy linked list
		// Third round: restore the original list, and extract the copy list.
		Node* pseudo_head = new Node(0);
		Node* copy = pseudo_head;
		iter = head;
		while (iter != NULL)
		{
			front = iter->next->next;
			copy->next = iter->next;
			iter->next = front;
			copy = copy->next;
			iter = iter->next;
		}
		return pseudo_head->next;

	}
};

struct Node {
	int data;
	Node *next;
	Node *arb;

	Node(int x) {
		data = x;
		next = NULL;
		arb = NULL;
	}
};

void print(Node *root) {
	Node *temp = root;
	while (temp != NULL) {
		int k;
		if (temp->arb == NULL)
			k = -1;
		else
			k = temp->arb->data;
		cout << temp->data << " " << k << " ";
		temp = temp->next;
	}
}

Node *copyList(Node *head);

void append(Node **head_ref, Node **tail_ref, int new_data) {

	Node *new_node = new Node(new_data);
	if (*head_ref == NULL) {
		*head_ref = new_node;
	} else
		(*tail_ref)->next = new_node;
	*tail_ref = new_node;
}

bool validation(Node *head, Node *res, Node *cloned_addr,
                Node *generated_addr) {

	if (generated_addr == cloned_addr) return false;

	Node *temp1 = head;
	Node *temp2 = res;

	int len1 = 0, len2 = 0;
	while (temp1 != NULL) {
		len1++;
		temp1 = temp1->next;
	}
	while (temp2 != NULL) {
		len2++;
		temp2 = temp2->next;
	}

	/*if lengths not equal */

	if (len1 != len2) return false;

	temp1 = head;
	temp2 = res;
	while (temp1 != NULL) {
		if (temp1->data != temp2->data) return false;
		if (temp1->arb != NULL and temp2->arb != NULL) {
			if (temp1->arb->data != temp2->arb->data) return false;
		} else if (temp1->arb != NULL and temp2->arb == NULL)
			return false;
		else if (temp1->arb == NULL and temp2->arb != NULL)
			return false;
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	return true;
}

/* Driver program to test above function*/
int main() {
	int T, i, n, l, k;
	Node *generated_addr = NULL;
	/*reading input stuff*/
	cin >> T;

	while (T--) {
		generated_addr = NULL;
		struct Node *head = NULL, *tail = NULL;

		cin >> n >> k;
		for (i = 1; i <= n; i++) {
			cin >> l;
			append(&head, &tail, l);
		}

		for (int i = 0; i < k; i++) {
			int a, b;
			cin >> a >> b;

			Node *tempA = head;
			int count = -1;

			while (tempA != NULL) {
				count++;
				if (count == a - 1) break;
				tempA = tempA->next;
			}
			Node *tempB = head;
			count = -1;

			while (tempB != NULL) {
				count++;
				if (count == b - 1) break;
				tempB = tempB->next;
			}

			// when both a is greater than N
			if (a <= n) tempA->arb = tempB;
		}
		/*read finished*/

		generated_addr = head;
		Node *res = copyList(head);

		Node *cloned_addr = res;

		cout << validation(head, res, cloned_addr, generated_addr) << endl;
	}

	return 0;
}
// } Driver Code Ends


/*  the node structure is as follows

struct Node {
    int data;
    Node *next;
    Node *arb;

    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};
*/

Node *copyList(Node *start) {
	// Your code here
	Node* curr = start, *temp;

	// insert additional node after
	// every node of original list
	while (curr)
	{
		temp = curr->next;

		// Inserting node
		curr->next = new Node(curr->data);
		curr->next->next = temp;
		curr = temp;
	}

	curr = start;

	// adjust the random pointers of the
	// newly added nodes
	while (curr)
	{
		if (curr->next)
			curr->next->arb = curr->arb ?
			                  curr->arb->next : curr->arb;

		// move to the next newly added node by
		// skipping an original node
		curr = curr->next ? curr->next->next : curr->next;
	}

	Node* original = start, *copy = start->next;

	// save the start of copied linked list
	temp = copy;

	// now separate the original list and copied list
	while (original && copy)
	{
		original->next =
		    original->next ? original->next->next : original->next;

		copy->next = copy->next ? copy->next->next : copy->next;
		original = original->next;
		copy = copy->next;
	}

	return temp;
}