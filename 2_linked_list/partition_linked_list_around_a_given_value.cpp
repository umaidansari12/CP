// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node* partition(struct Node* head, int x);

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void) {
    int t;
    cin >> t;

    while (t--) {
        struct Node* head = NULL;
        struct Node* temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            if (i == 0) {
                head = new Node(value);
                temp = head;
            } else {
                temp->next = new Node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        // Solution ob;

        head = partition(head, k);
        printList(head);
    }

    return (0);
}
// } Driver Code Ends


// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/

struct Node* partition(struct Node* head, int x) {

    if (!head)
        return NULL;
    // code here
    Node* less = NULL;
    Node* prev_less = NULL;
    Node* greater = NULL;
    Node* prev_greater = NULL;
    Node* equal = NULL;
    Node* prev_equal = NULL;
    Node* curr = head;
    while (curr)
    {
        if (curr->data == x)
        {
            if (equal == NULL)
            {
                equal = curr;
                prev_equal = equal;
            }
            else
            {
                prev_equal->next = curr;
                prev_equal = curr;
            }
        }
        else if (curr->data < x)
        {
            if (less == NULL)
            {
                less = curr;
                prev_less = less;
            }
            else
            {
                prev_less->next = curr;
                prev_less = curr;
            }
        }
        else if (curr->data > x)
        {
            if (greater == NULL)
            {
                greater = curr;
                prev_greater = greater;
            }
            else
            {
                prev_greater->next = curr;
                prev_greater = curr;
            }
        }
        curr = curr->next;
    }
    if (prev_greater != NULL)
    {
        prev_greater->next = NULL;
    }
    if (less == NULL)
    {
        if (equal == NULL)
        {
            return greater;
        }
        prev_equal->next = greater;
        return equal;
    }
    if (equal == NULL)
    {
        prev_less->next = greater;
        return less;
    }
    prev_less->next = equal;
    prev_equal->next = greater;
    return less;
}