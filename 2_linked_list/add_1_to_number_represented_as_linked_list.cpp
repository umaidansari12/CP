//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
//User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
public:
    Node* addOne(Node *head)
    {
        // Your Code here
        // return head of list after adding one
        vector<int> r;
        while (head)
        {
            r.push_back(head->data);
            head = head->next;
        }
        int carry = 1;
        for (int i = r.size() - 1; i >= 0; i--)
        {
            int sum = (carry + r[i]);
            carry = sum >= 10 ? 1 : 0;
            sum %= 10;
            r[i] = sum;
        }
        if (carry)
            r.insert(r.begin(), carry);
        head = NULL;
        Node* prev = NULL;
        for (int i = 0; i < r.size(); i++)
        {
            if (head == NULL)
            {
                head = new Node(r[i]);
                prev = head;
            }
            else
            {
                prev->next = new Node(r[i]);
                prev = prev->next;
            }
        }
        return head;
    }
    void solve(Node* head, int &carry) {
        if (!head)
            return;
        solve(head->next, carry);

        int sum = head->data;

        sum += carry;

        carry = sum / 10;

        head->data = sum % 10;

    }
    Node* addOne(Node *head)
    {
        // Your Code here
        // return head of list after adding one
        int carry = 1;
        solve(head, carry);
        if (carry) {
            Node* n = new Node(carry);
            n->next = head;
            head = n;
        }
        return head;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Node* head = new Node( s[0] - '0' );
        Node* tail = head;
        for (int i = 1; i < s.size(); i++)
        {
            tail->next = new Node( s[i] - '0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}
// } Driver Code Ends