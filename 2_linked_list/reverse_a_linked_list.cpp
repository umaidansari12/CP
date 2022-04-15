//Initial Template for C++// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

class Solution
{
public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        Node *prev, *curr, *next;
        next = NULL;
        prev = NULL;
        curr = head;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    struct Node* reverseHelper(struct Node* head) {
        if (head == NULL or head->next == NULL) {
            return head;
        }
        struct Node* rest = reverseHelper(head->next);
        head->next->next = head;
        head->next = NULL;
        return rest;
    }
    struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        head = reverseHelper(head);
        return head;
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
    ListNode* reverseList(ListNode* head) {
        //  base case -> if the linked list is empty or contains single node then the list remains as it is so we are returning this in that case
        // also we are boiling down to last node of linked list and there by returning its reference as it will be the new head of the reversed linked list
        if (head == NULL or head->next == NULL)
            return head;

        // go deep till the last node of the linked list and return the newHead
        ListNode* newHead = reverseList(head->next);

        //current's head next that means next of the current element and its next will be head
        // reversing the pointer instead of 1->2 doing 1<-2

        head->next->next = head;

        head->next = NULL; // 1->2 x cutting this link

        //return last node of the linked list as it is the newHead
        return newHead;


    }
};

// { Driver Code Starts.

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp  = temp->next;
    }
}

/* Driver program to test above function*/
int main()
{
    int T, n, l, firstdata;
    cin >> T;

    while (T--)
    {
        struct Node *head = NULL,  *tail = NULL;

        cin >> n;

        cin >> firstdata;
        head = new Node(firstdata);
        tail = head;

        for (int i = 1; i < n; i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }

        Solution ob;
        head = ob. reverseList(head);

        printList(head);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends