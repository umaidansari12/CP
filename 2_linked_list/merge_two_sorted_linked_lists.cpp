Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    int data = 0;
    Node<int> *newHead = new Node<int>(data);
    Node<int> *head = newHead;

    while (first and second) {
        if (first->data < second->data) {
            newHead->next = first;
            first = first->next;
            newHead = newHead->next;
        }
        else {
            newHead->next = second;
            second = second->next;
            newHead = newHead->next;
        }
    }

    while (first) {
        newHead->next = first;
        first = first->next;
        newHead = newHead->next;
    }
    while (second) {
        newHead->next = second;
        second = second->next;
        newHead = newHead->next;
    }
    head = head->next;
    return head;

}

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    // if either of the list is empty then return the other list
    if (!first)
        return second;
    if (!second)
        return first;

    // check which one's first value is smaller and swap if needed because we need to have first one as smaller
    if (first->data > second->data) {
        swap(first, second);
    }
    //create a dummy head to retain the head of the original linked list
    Node<int> *newHead = first;

    while (first != NULL and second != NULL) {
        // maintain a previous node to keep track of the last node visited so as to broke the current link and join it with the second list
        // the intuition is to traverse the first list until we are getting values which are lesser than second's value then broke the link and point the last node visited in first to second node after that swap because we have got value in first which is greater than second so swap to move smaller again to first to get the nodes in increasing order
        Node<int>* previous = NULL;
        while (first and first->data <= second->data) {
            previous = first;
            first = first->next;
        }
        previous->next = second;
        swap(first, second);
    }

    return newHead;
}
