// User function Template for C++

/*
class Node{
public:
    Node* prev;
    int data;
    Node* next;

    Node()
    {
        prev = NULL;
        data = 0;
        next = NULL;
    }

    Node(int value)
    {
        prev = NULL;
        data = value;
        next = NULL;
    }
};*/

class Solution {
public:
    Node* constructDLL(vector<int>& arr) {
        // code here
        Node* head = NULL;
        Node* curr = NULL;
        Node* prev = NULL;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (head == NULL) {
                head = new Node(arr[i]);
                curr = head;
            }
            else {
                curr->next = new Node(arr[i]);
                curr->next->prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};

/*
 * Definition for doubly-linked list.
 * class Node
 * {
 * public:
 *    int data;
 *    Node *next, *prev;
 *    Node() : data(0), next(nullptr), prev(nullptr) {}
 *    Node(int x) : data(x), next(nullptr), prev(nullptr) {}
 *    Node(int x, Node *next, Node *prev) : data(x), next(next), prev(prev) {}
 * };
 */

Node* constructDLL(vector<int>& arr) {
    // Write your code here
    Node* head = NULL;
    Node* curr = NULL;

    int n = arr.size();
    for (int i = 0; i < n; i++) {
        if (head == NULL) {
            head = new Node(arr[i]);
            curr = head;
        }
        else {
            curr->next = new Node(arr[i]);
            curr->next->prev = curr;
            curr = curr->next;
        }
    }
    return head;
}
