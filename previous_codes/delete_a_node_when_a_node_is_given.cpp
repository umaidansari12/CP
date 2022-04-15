void deleteNode(Node *node)
{
	// Your code here
	Node* temp = node->next;
	*node = *temp;
	free(temp);
}

class Solution {
public:
	void deleteNode(ListNode* node) {
		node->val = node->next->val;
		node->next = node->next->next;
	}
};

class Solution {
public:
	void deleteNode(ListNode* node) {
		ListNode* next = node->next;
		*node = *next;
	}
};