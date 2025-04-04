/*Structure of the linked list node is as
struct Node {
  int data;
  struct Node * next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution {
public:
  Node *insertAtEnd(Node *head, int x) {
    // Code here
    if (head == NULL)
      return new Node(x);
    Node* ptr = head;
    while (ptr->next != NULL) {
      ptr = ptr->next;
    }
    ptr->next = new Node(x);
    return head;
  }
};