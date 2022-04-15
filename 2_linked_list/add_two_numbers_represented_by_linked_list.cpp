// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin >> val;

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 0; i < size - 1; i++)
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
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        Node *prev1, *prev2, *next1, *next2, *curr1, *curr2, *head, *tail;
        head = NULL;
        tail = NULL;
        prev1 = NULL;
        prev2 = NULL;
        next1 = NULL;
        next2 = NULL;
        curr1 = first;
        curr2 = second;
        while (curr1) {
            next1 = curr1->next;
            curr1->next = prev1;
            prev1 = curr1;
            curr1 = next1;
        }
        while (curr2) {
            next2 = curr2->next;
            curr2->next = prev2;
            prev2 = curr2;
            curr2 = next2;
        }


        int carry = 0;
        while (prev1 or prev2) {
            int a = prev1 ? prev1->data : 0;
            int b = prev2 ? prev2->data : 0;

            int sum = (a + b + carry);
            carry = sum / 10;
            if (sum >= 10)
                sum = sum % 10;

            if (head == NULL) {
                head = new Node(sum);
                tail = head;
            }
            else {
                tail->next = new Node(sum);
                tail = tail->next;
            }

            if (prev1)
                prev1 = prev1->next;
            if (prev2)
                prev2 = prev2->next;
        }
        if (carry)
            tail->next = new Node(carry);
        prev1 = NULL;
        while (head) {
            next1 = head->next;
            head->next = prev1;
            prev1 = head;
            head = next1;
        }
        return prev1;
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
        Node* first = buildList(n);

        cin >> m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first, second);
        printList(res);
    }
    return 0;
}
// } Driver Code Ends