/**
 * Definition of doubly linked list:
 *
 * struct Node {
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() : data(0), prev(nullptr), next(nullptr) {}
 *      Node(int val) : data(val), prev(nullptr), next(nullptr) {}
 *      Node(int val, Node *p, Node *n) : data(val), prev(p), next(n) {}
 * };
 *
 *************************************************************************/

Node * deleteLastNode(Node *head) {
    // Write your code here
    if (head == NULL or head->next == NULL)
        return NULL;
    Node* curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->prev->next = NULL;
    curr->prev = NULL;
    return head;
}

/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
public:
    // Function to delete a node at given position.
    Node* deleteNode(Node* head, int x) {
        // Your code here
        if (x == 1) {
            head = head->next;
            head->prev = NULL;
            return head;
        }
        Node* curr = head;
        int idx = 1;
        while (curr->next != NULL and idx < x) {
            curr = curr->next;
            idx++;
        }
        if (curr->next == NULL) {
            curr->prev->next = NULL;
        }
        else {
            curr->prev->next = curr->next;
            curr->next->prev = curr;
        }
        return head;
    }
};