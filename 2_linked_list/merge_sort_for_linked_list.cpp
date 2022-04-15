#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution {
public:
    //Function to sort the given linked list using Merge Sort.
    Node* merge(Node* first, Node* second)
    {
        Node* result = NULL;
        if (first == NULL)
            return second;
        if (second == NULL)
            return first;


        if (first->data <= second->data)
        {
            result = first;
            result->next = merge(first->next, second);
        }
        else
        {
            result = second;
            result->next = merge(first, second->next);
        }
        return result;

    }

    Node* getMiddle(Node* head)
    {
        Node* slow = head;
        Node* fast = head->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
        /*
        Node* slow=head;
        Node* fast=head;
        while(fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
        */
    }

    Node* mergeSort(Node* head) {
        // your code here
        if (head == NULL || head->next == NULL)
            return head;
        Node* mid = getMiddle(head);
        Node* newHead = mid->next;
        mid->next = NULL;

        return merge(mergeSort(head), mergeSort(newHead));

    }
};


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends