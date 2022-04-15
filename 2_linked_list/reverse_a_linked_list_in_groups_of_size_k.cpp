#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;

    node(int x) {
        data = x;
        next = NULL;
    }

};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element
  Return the node which points to the head of the new LinkedList
  Node is defined as
    struct node
    {
        int data;
        struct node* next;

        node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution
{
public:
    struct node *reverse (struct node *head, int k)
    {
        // Complete this method
        node* curr = head;
        node* prev = NULL;
        node* next = NULL;
        int count = 0;
        while (curr and count < k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if (next)
        {
            head->next = reverse(next, k);
        }
        return prev;
    }

    node* reverseKNodes(node* head, int k) {
        if (head == NULL || head->next == NULL) return head;

        int length = lengthOfLinkedList(head);

        node* dummyHead = new node(0);
        dummyHead->next = head;

        node* pre = dummyHead;
        node* cur;
        node* nex;

        while (length >= k) {
            cur = pre->next;
            nex = cur->next;
            for (int i = 1; i < k; i++) {
                cur->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = cur->next;
            }
            pre = cur;
            length -= k;
        }
        return dummyHead->next;
    }
};


// { Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin >> t;

    while (t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;

        for (int i = 0 ; i < n ; i++)
        {
            int value;
            cin >> value;
            if (i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }

    return (0);
}

// } Driver Code Ends