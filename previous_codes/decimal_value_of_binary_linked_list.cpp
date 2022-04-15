// Program to check if linked list is empty or not
#include<iostream>
using namespace std;
const long long unsigned int MOD = 1000000007;

/* Link list Node */
struct Node
{
    bool data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }

};

long long unsigned int decimalValue(struct Node *head);

void append(struct Node** head_ref, struct Node **tail_ref, bool new_data)
{

    struct Node* new_node = new Node(new_data);

    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}


bool isEmpty(struct Node *head);

/* Driver program to test above function*/
int main()
{
    bool l;
    int i, n, T;

    cin >> T;

    while (T--) {
        struct Node *head = NULL,  *tail = NULL;

        cin >> n;
        for (i = 1; i <= n; i++)
        {
            cin >> l;
            append(&head, &tail, l);
        }

        cout << decimalValue(head) << endl;
    }
    return 0;
}// } Driver Code Ends


/* Below global variable is declared in code for modulo arithmetic
const long long unsigned int MOD = 1000000007; */

/* Link list Node/
struct Node
{
    bool data;   // NOTE data is bool
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}; */

// Should return decimal equivalent modulo 1000000007 of binary linked list

void cal(Node* head, long long unsigned int &power, long long unsigned int &res)
{
    if (!head)
        return;
    cal(head->next, power, res);
    res = (res + ((head->data) * power)) % MOD;
    power = (power * 2) % MOD;
}
long long unsigned int decimalValue(Node *head)
{
    // Your Code Here
    long long unsigned int res = 0;
    long long unsigned int power = 1;
    cal(head, power, res);
    return res % MOD;
}

long long unsigned int decimalValuemyapproach(Node *head)
{
    // Your Code Here
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    long long unsigned int base = 1, ans = 0;
    while (prev)
    {
        ans = ((ans % MOD) + ((base * (prev->data)) % MOD)) % MOD;
        base = (base * (long long)2) % MOD;
        prev = prev->next;
    }
    return ans;
}