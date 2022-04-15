/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

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

    // here is k is 1-based indexing and if k==0 or k>_size of the linked list itself we simply return head that means dont remove anything as we don't have that index available
    if (K == 0 or K > _size)
        return head;

    // if the k is equal to size of the linked list that means from end we need to remove last element which is as similar to removing first element so we just return head->next;
    if (_size == K)
        return head->next;

    // k>0 and k<_size that means the k is inside the boundation and we need to remove the element at kth index
    // kth node from end means (_size - k)th node from start so we maintain a prev pointer to remove the element from the linked list

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

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
    // Write your code here.
    if (!head)
        return head;

    if (K == 0)
        return head;

    LinkedListNode<int> *fast = head;
    LinkedListNode<int> *slow = head;

    for (int i = 0; i < K; i++) {
        if (fast->next == NULL) {
            if (i == (K - 1)) {
                return head->next;
            }
            return head;
        }
        fast = fast->next;

    }

    while (fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = slow->next->next;

    return head;
}