#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

void print(Node *root)
{
    Node *temp = root;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node* removeDuplicates(Node *root);

int main() {
    // your code goes here
    int T;
    cin >> T;

    while (T--)
    {
        int K;
        cin >> K;
        struct Node *head = NULL;
        struct Node *temp = head;

        for (int i = 0; i < K; i++) {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else
            {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }


        Node *result  = removeDuplicates(head);
        print(result);
        cout << endl;

    }
    return 0;
}// } Driver Code Ends


/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

// Function to remove duplicates from the linked list
// root: root of the linked list
Node * removeDuplicates( Node *head)
{
// your code goes here
    unordered_set<int> seen;
    Node* current = head;
    Node* prev = NULL;
    while (current != NULL)
    {
        if (seen.find(current->data) != seen.end())
        {
            prev->next = current->next;
            delete(current);
        }
        else
        {
            seen.insert(current->data);
            prev = current;
        }
        current = prev->next;
    }
    return head;
}

class Solution
{
public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head)
    {
        // your code goes here
        unordered_set<int> seen;
        Node* current = head;
        Node* prev = NULL;
        while (current != NULL)
        {
            if (seen.find(current->data) != seen.end())
            {
                prev->next = current->next;
                delete(current);
            }
            else
            {
                seen.insert(current->data);
                prev = current;
            }
            current = current->next;

        }
        return head;

    }
};
