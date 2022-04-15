// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
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
        Node* prev1 = NULL;
        Node* prev2 = NULL;
        Node* next = NULL;
        Node* head = NULL;
        while (first)
        {
            next = first->next;
            first->next = prev1;
            prev1 = first;
            first = next;
        }
        while (second)
        {
            next = second->next;
            second->next = prev2;
            prev2 = second;
            second = next;
        }
        // while(prev1)
        // {
        //     cout<<prev1->data<<" ";
        //     prev1=prev1->next;
        // }
        // cout<<endl;
        // while(prev2)
        // {
        //     cout<<prev2->data<<" ";
        //     prev2=prev2->next;
        // }
        int carry = 0, sum = 0;
        while (prev1 or prev2)
        {
            if (head == NULL)
            {
                sum = (prev1 ? (prev1->data) : 0) + (prev2 ? (prev2->data) : 0) + carry;
                carry = sum / 10;
                if (sum >= 10)
                    sum %= 10;
                head = new Node(sum);
                next = head;
            }
            else
            {
                sum = (prev1 ? (prev1->data) : 0) + (prev2 ? (prev2->data) : 0) + carry;
                carry = sum / 10;
                if (sum >= 10)
                    sum %= 10;
                next->next = new Node(sum);
                next = next->next;
            }
            if (prev1)
                prev1 = prev1->next;
            if (prev2)
                prev2 = prev2->next;
        }
        if (carry)
        {
            next->next = new Node(carry);
            next = next->next;
        }
        prev1 = NULL;

        while (head)
        {
            next = head->next;
            head->next = prev1;
            prev1 = head;
            head = next;
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