//Initial Template for C++

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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* node = dummy;
        while (node != NULL)
        {
            ListNode* first = node->next;
            ListNode* second = NULL;
            if (first != NULL)
            {
                second = first->next;
            }
            if (second != NULL)
            {
                ListNode* secondNext = second->next;
                second->next = first;
                node->next = second;
                first->next = secondNext;
                node = first;
            }
            else
                break;
        }
        return dummy->next;

    }

};

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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        swap(dummy);
        return dummy->next;

    }
    void swap(ListNode* node)
    {
        if (node == NULL)
            return;
        ListNode* first = node->next;
        ListNode* second = NULL;
        if (first != NULL)
            second = first->next;
        if (second != NULL)
        {
            ListNode* secondNext = second->next;
            second->next = first;
            node->next = second;
            first->next = secondNext;
            swap(first);
        }
    }
};

class Solution
{
public:
    Node* pairWiseSwap(struct Node* head)
    {
        // The task is to complete this method
        struct Node* dummy = new struct Node(0);
        dummy->next = head;
        swap(dummy);
        return dummy->next;
    }
    void swap(struct Node* node)
    {
        if (node == NULL)
            return;
        struct Node* first = node->next;
        struct Node* second = NULL;
        if (first != NULL)
        {
            second = first->next;
        }
        if (second != NULL)
        {
            struct Node* secondNext = second->next;
            second->next = first;
            node->next = second;
            first->next = secondNext;
            swap(first);
        }
    }
    Node* pairWiseSwap(struct Node* head)
    {
        // The task is to complete this method
        struct Node* dummy = new struct Node(0);
        dummy->next = head;
        struct Node* node = new struct Node(0);
        node = dummy;
        while (node != NULL)
        {
            struct Node* first = node->next;
            struct Node* second = NULL;
            if (first != NULL)
            {
                second = first->next;
            }
            if (second != NULL)
            {
                struct Node* secondNext = second->next;
                second->next = first;
                node->next = second;
                first->next = secondNext;
                node = first;
            }
            else
                break;
        }
        return dummy->next;
    }
};


// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
//Function to swap elements pairwise.
struct Node* pairwise_swap(struct Node* head)
{
    // your code here
    /*
    if (!head or !head->next)
            return head;
        Node* prev = head;
        Node* curr = head->next;
        head = curr;
        Node* next = NULL;
        while (1)
        {
            next = curr->next;
            curr->next = prev;
            if (next == NULL || next->next == NULL)
            {
                prev->next = next;
                break;
            }
            prev->next = next->next;
            prev = next;
            curr = next->next;
        }

        return head;
    */
    vector<Node*> list;
    Node* curr = head;
    while (curr)
    {
        list.push_back(curr);
        curr = curr->next;
    }
    for (int i = 0; i < list.size() - 1; i += 2)
    {
        swap(list[i]->data, list[i + 1]->data);
    }
    return head;
}

// { Driver Code Starts.
void printList(struct Node* node)
{
    while (node != NULL)
    {
        printf("%d ", (node)->data);
        node = (node)->next;
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, l, firstdata;
        cin >> n;
        // taking first node of linked list
        cin >> firstdata;
        struct Node* head = new Node(firstdata);
        struct Node* tail = head;
        // taking remaining nodes of linked list
        for (int i = 1; i < n; i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        head = pairwise_swap(head);
        printList(head);
        cout << endl;
    }
}  // } Driver Code Ends

ListNode* Solution::swapPairs(ListNode* A) {
    if (!A)
        return NULL;
    ListNode* head = A;
    ListNode* curr, *next, *prev;
    prev = NULL;
    curr = A;
    next = curr->next;
    if (next)
        A = next;
    while (next)
    {
        curr->next = next->next;
        next->next = curr;
        if (prev)
            prev->next = next;      //I had missed this part of linking 1 to 4: 2->1 ~ 4->3
        prev = curr;
        curr = curr->next;
        if (curr)
            next = curr->next;
        else
            next = NULL;
    }
    return A;
}