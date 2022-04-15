Node* deleteNode(Node *head, int x)
{
    //Your code
    if (head == NULL)
        return head;
    if (x - 1 == 0)
    {
        head = head->next;
        return head;
    }
    int count = 0;
    Node* current = head;
    while (current != NULL && count < x - 2)
    {
        current = current->next;
        count++;
    }
    if (current == NULL || current->next == NULL)
        return head;
    current->next = current->next->next;
    return head;
}
