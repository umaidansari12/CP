Node* deleteMid(Node* head)
{
    // Your Code Here
    int total = 0;
    Node* current = head;
    while (current != NULL)
    {
        current = current->next;
        total++;
    }
    int mid = total / 2;
    current = head;
    while (mid-- > 1)
    {
        current = current->next;
    }
    current->next = current->next->next;

    return head;
}

Node* deleteMid(Node* head)
{
    // Your Code Here
    int total = 0;
    Node* fast = head;
    Node* slow = head;
    Node* prev = NULL;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    prev->next = slow->next;
    delete(slow);
    return head;


    return head;
}