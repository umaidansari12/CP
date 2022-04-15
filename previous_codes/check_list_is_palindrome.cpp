Node* reverse(Node* head)
{
    Node* current = head;
    Node* prev = NULL;
    Node* next = NULL;
    while (current)
    {
        Node* n = new Node(current->data);
        n->next = prev;
        prev = n;
        current = current->next;
    }
    return prev;
}
bool isPalindrome(Node *head)
{
    //Your code her
    Node* current = head;
    Node* r = reverse(current);
    current = head;
    while (current && r)
    {
        if (r->data != current->data)
            return false;
        r = r->next;
        current = current->next;
    }
    return true;
}
bool isPalindrome(Node *head)
{
    //Your code here
    stack<int> s;
    Node* current = head;
    while (current)
    {
        s.push(current->data);
        current = current->next;
    }
    current = head;
    while (!s.empty())
    {
        if (s.top() != current->data)
            return false;
        s.pop();
        current = current->next;
    }
    return true;
}
Node* reverse(Node* head)
{
    Node* current = head;
    Node* prev = NULL;
    Node* next = NULL;
    while (current)
    {
        Node* n = new Node(current->data);
        n->next = prev;
        prev = n;
        current = current->next;
    }
    return prev;
}
bool isPalindrome(Node *head)
{
    //Your code her
    Node* current = head;
    Node* r = reverse(current);
    current = head;
    while (current && r)
    {
        if (r->data != current->data)
            return false;
        r = r->next;
        current = current->next;
    }
    return true;
}
bool isPalindrome(Node *head)
{
    //Your code here
    stack<int> s;
    Node* slow = head;
    while (slow != NULL)
    {
        s.push(slow->data);
        slow = slow->next;
    }
    while (head != NULL)
    {
        if (s.top() == head->data)
            s.pop();
        else
            return false;
        head = head->next;
    }
    return true;
}

int Solution::lPalin(ListNode* A) {
    stack<int> s;
    ListNode* current = A;
    while (current != NULL)
    {
        s.push(current->val);
        current = current->next;
    }
    while (A != NULL)
    {
        if (A->val != s.top())
            return 0;
        else
            s.pop();
        A = A->next;
    }
    return 1;
}


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* current = head;
        stack<int> s;
        while (current != NULL)
        {
            s.push(current->val);
            current = current->next;
        }
        while (head != NULL)
        {
            if (head->val != s.top())
                return false;
            else
                s.pop();
            head = head->next;
        }
        return true;
    }
};

Node* reverse(Node* head)
{
    Node* prev = NULL;
    Node* next = NULL;
    while (head)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}
bool isPalindrome(Node *head)
{
    //Your code here
    if (head == NULL || head->next == NULL)
        return true;
    Node* fast = head;
    Node* slow = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = reverse(slow->next);
    slow = slow->next;
    while (slow)
    {
        if (head->data != slow->data)
            return false;
        slow = slow->next;
        head = head->next;

    }
    return true;
}

class Solution {
public:
    ListNode* reverse(ListNode* head)
    {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if (head == NULL)
            return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverse(slow->next);
        slow = slow->next;
        fast = head;
        while (slow)
        {
            if (slow->val != fast->val)
                return false;
            slow = slow->next;
            fast = fast->next;
        }
        return true;

    }
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> res;
        while (head != NULL)
        {
            res.push_back(head->val);
            head = head->next;
        }
        vector<int> res2 = res;
        reverse(res.begin(), res.end());
        for (int i = 0; i < res.size(); i++)
            if (res[i] != res2[i])
                return false;
        return true;

    }
};