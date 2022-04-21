LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
    // Write your code here.
    if (!head)
        return head;

    int _size = 0;

    LinkedListNode<int> *curr = head;

    while (curr) {
        _size++;
        curr = curr->next;
    }

    if (K == 0)
        return head;

    if (_size == K)
        return head->next;
    if (K > _size)
        return head;


    int steps = (_size - K);


    curr = head;
    LinkedListNode<int> *prev = NULL;
    for (int i = 0; i < steps; i++) {
        prev = curr;
        curr = curr->next;
    }

    prev->next = (curr->next) ? curr->next : NULL;

    return head;
}