/* Link list node */
/*
struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
}; */

class Solution {
public:
    // Function to count nodes of a linked list.
    bool searchKey(int n, struct Node* head, int key) {
        // Code here
        if (head == NULL)
            return false;
        Node* ptr = head;
        while (ptr) {
            if (ptr->data == key)
                return true;
            ptr = ptr->next;
        }
        return false;
    }
};