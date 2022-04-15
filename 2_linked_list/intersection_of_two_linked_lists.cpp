//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;

    cin >> val;
    head = tail = new Node(val);

    while (--size)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
}


// } Driver Code Ends
/* structure of list node:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution {
public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        // code here
        // return the head of intersection list
        set<int> s;
        Node* head = head2;
        while (head)
        {
            s.insert(head->data);
            head = head->next;
        }
        head = head1;
        Node* node = NULL;
        Node* prev = NULL;
        while (head)
        {
            if (s.find(head->data) != s.end())
            {
                if (node == NULL)
                {
                    node = new Node(head->data);
                    node->next = NULL;
                    prev = node;
                }
                else
                {
                    prev->next = new Node(head->data);
                    prev = prev->next;
                }
            }
            head = head->next;
        }
        return node;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;

        cin >> n;
        Node* head1 = inputList(n);

        cin >> m;
        Node* head2 = inputList(m);
        Solution obj;
        Node* result = obj.findIntersection(head1, head2);

        printList(result);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends