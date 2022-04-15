// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Node structure

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
    void rearrangeEvenOdd(Node *head)
    {
        // Your Code here
        if (!head or !head->next)
            return;

        Node* odd = NULL;
        Node* even = NULL;
        Node* prev_even = NULL;
        Node* prev_odd = NULL;
        int pos = 1;
        while (head)
        {
            if ((pos) % 2 == 1)
            {
                if (odd == NULL)
                {
                    odd = prev_odd = head;
                }
                else
                {
                    prev_odd->next = head;
                    prev_odd = head;
                }
            }
            else if ((pos) % 2 == 0)
            {
                if (even == NULL)
                {
                    even = prev_even = head;
                }
                else
                {
                    prev_even->next = head;
                    prev_even = head;
                }
            }
            pos++;
            head = head->next;
        }
        //   if(odd==NULL)
        //   {
        //       prev_even->next=NULL;
        //       head=even;
        //       return ;
        //   }
        //   if(even==NULL)
        //   {
        //       prev_odd->next=NULL;
        //       head=odd;
        //       return ;
        //   }
        prev_odd->next = even;
        prev_even->next = NULL;
        head = odd;
    }
};


// { Driver Code Starts.

/* Driver program to test above function*/
int main()
{
    int T, i, n, l;

    cin >> T;

    while (T--)
    {
        struct Node *head = NULL;
        struct Node *temp = head;
        cin >> n;
        for (i = 1; i <= n; i++)
        {
            cin >> l;

            if (head == NULL)
            {
                head = temp = new Node(l);

            }
            else
            {   temp->next = new Node(l);
                temp = temp->next;
            }
        }
        Solution ob;
        ob.rearrangeEvenOdd(head);
        while (head != NULL)
        {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
    return 0;
}
// } Driver Code Ends