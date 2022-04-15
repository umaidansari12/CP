int getNthFromLast(Node *head, int n)
{
    // Your code here
    Node* current = head;
    int count = 0;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    int find = count - n + 1;
    int curr = 0;
    if (n > count)
        return -1;
    current = head;
    while (curr < find - 1)
    {
        curr++;
        current = current->next;
    }
    return current->data;
}

int getNthFromLast(Node *head, int n)
{
    // Your code here
    Node* first = head;
    Node* second = head;
    for (int i = 0; i < n; i++)
    {
        if (second == NULL)
        {
            if (n > i)
                return -1;
            return first->data;
        }
        second = second->next;
    }
    while (second != NULL)
    {
        first = first->next;
        second = second->next;
    }
    return first->data;
}

