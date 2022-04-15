// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }

};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}

// } Driver Code Ends
/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
        // Your code here
        priority_queue<Node*, vector<Node*>, compare> min_heap;
        for (int i = 0; i < K; i++)
        {
            min_heap.push(arr[i]);
        }
        Node* head = NULL;
        Node* prev = NULL;
        while (!min_heap.empty())
        {
            Node* curr = min_heap.top();
            min_heap.pop();
            if (curr->next != NULL)
            {
                min_heap.push(curr->next);
            }
            if (head == NULL)
            {
                head = new Node(curr->data);
                prev = head;
            }
            else
            {
                Node* n = new Node(curr->data);
                prev->next = n;
                prev = n;
            }

        }
        return head;
    }
private:
    struct compare {
        bool operator()(Node* a, Node* b) {
            return a->data > b->data;
        }
    };
};



// { Driver Code Starts.
// Driver program to test above functions
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        struct Node *arr[N];
        for (int j = 0; j < N; j++)
        {
            int n;
            cin >> n;

            int x;
            cin >> x;
            arr[j] = new Node(x);
            Node *curr = arr[j];
            n--;

            for (int i = 0; i < n; i++)
            {
                cin >> x;
                Node *temp = new Node(x);
                curr->next = temp;
                curr = temp;
            }
        }
        Solution obj;
        Node *res = obj.mergeKLists(arr, N);
        printList(res);

    }

    return 0;
}
// } Driver Code Ends

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return NULL;

        priority_queue<ListNode*, vector<ListNode*>, compare> min_heap;
        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i] != NULL)
                min_heap.push(lists[i]);
        }
        ListNode* head = NULL;
        ListNode* prev = NULL;
        while (!min_heap.empty())
        {
            ListNode* curr = min_heap.top();
            min_heap.pop();
            if (curr->next != NULL)
            {
                min_heap.push(curr->next);
            }
            if (head == NULL)
            {
                head = new ListNode(curr->val);
                prev = head;
            }
            else
            {
                ListNode* n = new ListNode(curr->val);
                prev->next = n;
                prev = n;
            }
        }
        return head;
    }
private:
    struct compare {
        bool operator()(ListNode* a, ListNode* b)
        {
            return a->val > b->val;
        }
    };

};