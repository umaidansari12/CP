Node *findMiddle(Node *head) {
    // Write your code here
    if (!head or !head->next)
        return head;
    int count = 0;
    Node* curr = head;
    while (curr) {
        count++;
        curr = curr->next;
    }

    count = count / 2;

    while (count--) {
        head = head->next;
    }

    return head;

}

Node *findMiddle(Node *head) {
    // Write your code here
    if (!head or !head->next)
        return head;
    Node* slow = head;
    Node* fast = head;

    while (fast and fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;

}


