// User function Template for C++

/*class Node {
public:
    int data;
    Node* next;

    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};*/

class Solution {
public:
    Node* constructLL(vector<int>& arr) {
        // code here
        Node* head = NULL;
        Node* ptr = NULL;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (head == NULL) {
                head = new Node(arr[i]);
                ptr = head;
            }
            else {
                ptr->next = new Node(arr[i]);
                ptr = ptr->next;
            }
        }
        return head;
    }
};