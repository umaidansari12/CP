

/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

//Function to insert a new node at given position in doubly linked list.
void addNode(Node *head, int pos, int data)
{
    // Your code here
    int idx = 0;
    Node* curr = head;
    while (curr->next != NULL and idx < pos) {
        idx++;
        curr = curr->next;
    }
    Node* element = new Node(data);
    if (curr->next) {
        element->next = curr->next;
        element->prev = curr;
        curr->next->prev = element;
        curr->next = element;
    }
    else {
        curr->next = element;
        element->prev = curr;
    }
}