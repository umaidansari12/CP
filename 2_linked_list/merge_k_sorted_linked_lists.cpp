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

class Solution {
public:
    struct node {
        Node* curr;
        int idx;
        node(Node* a, int i) {
            curr = a;
            idx = i;
        }
    };
    struct compare {
        bool operator()(node a, node b) {
            return a.curr->data > b.curr->data;
        }
    };

    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
        // Your code here
        Node *head, *tail;
        head = tail = NULL;
        priority_queue<node, vector<node>, compare> heap;
        vector<Node*> ptr(K);
        for (int i = 0; i < K; i++) {
            ptr[i] = arr[i];
            if (ptr[i] != NULL)
                heap.push(node(ptr[i], i));
        }
        if (heap.empty())
            return NULL;

        head = tail = heap.top().curr;
        int idx = heap.top().idx;
        heap.pop();
        ptr[idx] = ptr[idx]->next;
        if (ptr[idx])
            heap.push(node(ptr[idx], idx));
        while (!heap.empty()) {
            Node* temp = heap.top().curr;
            idx = heap.top().idx;
            heap.pop();
            tail->next = temp;
            tail = tail->next;
            ptr[idx] = ptr[idx]->next;
            if (ptr[idx])
                heap.push(node(ptr[idx], idx));
        }
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
//Divide_&_Conquer
class Solution {
    ListNode *merge(vector<ListNode*>& lists, int left, int right)
    {
        if (left == right)  //Only 1 list,therefore can't be merged
            return lists[left];

        int k = right - left + 1; //No of current lists
        ListNode *head, *h1, *h2, *ptr;
        head = h1 = h2 = NULL;
        h1 = merge(lists, left, left + k / 2 - 1); //Merge 1st half and store its head in h1
        h2 = merge(lists, left + k / 2, right); //Merge 2nd half and store its head in h2

        //Merge h1 and h2 into head
        if (!h1 and !h2) //No list is present
            return head;
        else if (!h1)   //Only 2nd list is present
            return h2;
        else if (!h2)   //Only 1st list is present
            return h1;

        if (!h1 or (h1 and h1->val > h2->val))
        {   head = h2;  h2 = h2->next;    }
        else
        {   head = h1;  h1 = h1->next;    }

        ptr = head;
        while (h1 or h2)
        {
            if (!h1)
            {   ptr->next = h2;   h2 = h2->next;  ptr = ptr->next;  }
            else if (!h2)
            {   ptr->next = h1;   h1 = h1->next;  ptr = ptr->next;  }
            else if (h1->val < h2->val)
            {   ptr->next = h1;   h1 = h1->next;    ptr = ptr->next;  }
            else
            {   ptr->next = h2;   h2 = h2->next;    ptr = ptr->next;  }
        }
        return head;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if (k == 0)
            return NULL;
        else if (k == 1)
            return lists[0];
        ListNode *head, *h1, *h2, *ptr;
        head = h1 = h2 = NULL;
        h1 = merge(lists, 0, k / 2); //Merge 1st half
        if (k / 2 + 1 <= k - 1)
            h2 = merge(lists, k / 2 + 1, k - 1); //Merge 2nd half

        //Merge h1 and h2 into head
        if (!h1 and !h2) //No list is present
            return head;
        else if (!h1)   //Only 2nd list is present
            return h2;
        else if (!h2)   //Only 1st list is present
            return h1;

        if (!h1 or (h1 and h1->val > h2->val))
        {   head = h2;  h2 = h2->next;    }
        else
        {   head = h1;  h1 = h1->next;    }

        ptr = head;
        while (h1 or h2)
        {
            if (!h1)
            {   ptr->next = h2;   h2 = h2->next;  ptr = ptr->next;  }
            else if (!h2)
            {   ptr->next = h1;   h1 = h1->next;  ptr = ptr->next;  }
            else if (h1->val < h2->val)
            {   ptr->next = h1;   h1 = h1->next;    ptr = ptr->next;  }
            else
            {   ptr->next = h2;   h2 = h2->next;    ptr = ptr->next;  }
        }
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
    struct node {
        ListNode *curr;    //Current node
        int idx;    //List index number
        node(ListNode *a, int b)
        {
            curr = a;
            idx = b;
        }
    };
    struct compare {
        bool operator()(node a, node b)
        {
            return a.curr->val > b.curr->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if (k == 0)
            return NULL;
        ListNode *head, *tail;
        head = tail = NULL;
        priority_queue<node, vector<node>, compare> heap;
        vector<ListNode*> ptr(k);   //Current node ptrs for all the lists
        //Assign all the current ptrs and BUILD_HEAP
        for (int i = 0; i < k; ++i)
        {
            ptr[i] = lists[i];
            if (ptr[i] != NULL)
                heap.push(node(ptr[i], i));
        }

        if (heap.empty())
            return NULL;
        //Insert 1st node
        head = tail = heap.top().curr;
        int idx = heap.top().idx;
        heap.pop();
        ptr[idx] = ptr[idx]->next;
        if (ptr[idx])   //Push newly pointed node if not NULL
            heap.push(node(ptr[idx], idx));

        //Make list with rest of the nodes
        while (!heap.empty())
        {
            ListNode *temp = heap.top().curr; //Pop root node
            idx = heap.top().idx;
            heap.pop();

            tail->next = temp;  //Add newnode to list
            tail = tail->next;
            ptr[idx] = ptr[idx]->next;  //Update current pointer
            if (ptr[idx])  //Push newly pointed node if not NULL
                heap.push(node(ptr[idx], idx));
        }
        return head;
    }
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