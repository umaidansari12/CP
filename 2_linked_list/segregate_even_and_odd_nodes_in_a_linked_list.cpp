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
        cout << node->data << " ";
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
class Solution {
public:
    Node* divide(int N, Node *head) {
        // code here
        Node* even = NULL;
        Node* prev_even = NULL;
        Node* odd = NULL;
        Node* prev_odd = NULL;
        while (head)
        {
            if ((head->data) % 2 == 0)
            {
                if (even == NULL)
                {
                    even = new Node(head->data);
                    prev_even = even;
                }
                else
                {
                    prev_even->next = new Node(head->data);
                    prev_even = prev_even->next;
                }
            }
            else
            {
                if (odd == NULL)
                {
                    odd = new Node(head->data);
                    prev_odd = odd;
                }
                else
                {
                    prev_odd->next = new Node(head->data);
                    prev_odd = prev_odd->next;
                }
            }
            head = head->next;
        }
        if (even == NULL)
            return odd;
        if (odd == NULL)
            return even;
        prev_even->next = odd;
        return even;
    }
};

// { Driver Code Starts.

int main() {
    //code
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int data;
        cin >> data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N - 1; ++i)
        {
            cin >> data;
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans);
    }
    return 0;
}
// } Driver Code Ends