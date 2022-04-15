class node {
public:
    int val;
    node* next;
    node(int val)
    {
        this->val = val;
        next = NULL;
    }
};

class MyLinkedList {
private:
    node* head;
    node* tail;
    int size;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index >= size or index < 0)
            return -1;
        node* cur = head;
        for (int i = 0; i < index; i++)
            cur = cur->next;
        return cur->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        node* n = new node(val);
        n->next = head;
        head = n;
        if (size == 0) tail = n;
        ++size;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        node* n = new node(val);
        if (size == 0)
        {
            tail = n;
            head = n;
        }
        tail->next = n;
        tail = n;
        ++size;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > size or index < 0)
            return;
        else if (index == 0)
        {
            addAtHead(val);
            return;
        }
        else if (index == size)
        {
            addAtTail(val);
            return;
        }
        node* cur = head;
        for (int i = 0; i < index - 1; i++)
            cur = cur->next;
        node* n = new node(val);
        n->next = cur->next;
        cur->next = n;
        ++size;
        return;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index >= size or index < 0)
            return;
        else if (index == 0)
        {
            head = head->next;
            return;
        }
        node* cur = head;
        for (int i = 0; i < index - 1; i++)
            cur = cur->next;
        cur->next = cur->next->next;
        if (index == size - 1)
            tail = cur;
        --size;
        return;

    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */