/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

*****************************************************************/

Node* merge(Node* a, Node* b) {
	Node* dummy_head = new Node(0);
	Node* head = dummy_head;

	while (a != NULL and b != NULL) {
		if (a->data < b->data) {
			dummy_head->child = a;
			dummy_head = dummy_head->child;
			a = a->child;
		}
		else {
			dummy_head->child = b;
			dummy_head = dummy_head->child;
			b = b->child;
		}
	}

	if (a) {
		dummy_head->child = a;
	}
	else if (b) {
		dummy_head->child = b;
	}

	return head->child;
}

Node* flattenLinkedList(Node* head)
{
	// Write your code here
	if (head == NULL or head->next == NULL) {
		return head;
	}

	head->next = flattenLinkedList(head->next);

	head = merge(head, head->next);

	return head;
}


Node* merge(Node* a, Node* b) {
	Node* dummy_head = new Node(0);
	Node* head = dummy_head;

	while (a != NULL and b != NULL) {
		if (a->data < b->data) {
			dummy_head->child = a;
			dummy_head = dummy_head->child;
			a = a->child;
		}
		else {
			dummy_head->child = b;
			dummy_head = dummy_head->child;
			b = b->child;
		}
	}

	if (a) {
		dummy_head->child = a;
	}
	else if (b) {
		dummy_head->child = b;
	}

	return head->child;
}

Node* flattenLinkedList(Node* head)
{
	// Write your code here
	if (head == NULL or head->next == NULL) {
		return head;
	}

	Node* a = head;
	Node* answer = NULL;
	while (a) {
		answer = merge(answer, a);
		a = a->next;
	}

	return answer;
}
