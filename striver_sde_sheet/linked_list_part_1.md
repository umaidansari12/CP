* ## Reverse a Linked List
```
Problem Statement: Given the head of a singly linked list, write a program to reverse the linked list, and return the head pointer to the reversed list.

# Iterative version

Approach : To reverse a linked list we need to reverse the linking between the nodes that means if the linked list is (A-->B-->C-->D-->NULL) then after reversing D should point to C and C should point to B and so on that means now the linked list will look something like this (NULL<--A<--B<--C<--D).
We need to modify the pointers take one pointer which will point to head and a next pointer which will keep track of the next of the current element when we will change the next pointer of the current element so as we will not lost track of all the elements present in the linked list and we will take previous pointer which will keep storing the reverse pointers.

Code : 

struct Node* reverseList(struct Node *head)
{
    // code here
    // return head of reversed list
    Node *prev, *curr, *next;
    next = NULL;
    prev = NULL;
    curr = head;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

# Recursive Version

Approach : We are going to the last node of the list and everytime changing the pointers of current node by changing current node's next pointer to point to current node and everytime returning the new head of the list i.e the last node of the given list.

Code :

struct Node* reverseHelper(struct Node* head) {
    if (head == NULL or head->next == NULL) {
        return head;
    }
    struct Node* rest = reverseHelper(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}
struct Node* reverseList(struct Node *head)
{
    // code here
    // return head of reversed list
    head = reverseHelper(head);
    return head;
}
```
* ## Find middle element in a Linked List
```
Problem Statement: Given the head of a singly linked list, return the middle node of the linked list. If there are two middle nodes, return the second middle node.

Approach : Calculate the length of the linked list and then traverse the list (size/2) times and the node reached will be the middle node.

Code : 

Node *findMiddle(Node *head) {
    // Write your code here
    if(!head or !head->next)
        return head;
    int count = 0;
    Node* curr = head;
    while(curr){
        count++;
        curr=curr->next;
    }
    
    count = count/2;
    
    while(count--){
        head=head->next;
    }
    
    return head;
    
}

Approach : Use the slow and fast pointer and move fast pointer by two steps and slow pointer by one step as one pointer is moving faster than the other 2 times you will observe that if the faster one will be at nth node then the slower one will be at (n/2)th node. 
Note : use condition fast!=NULL and fast->next!=NULL if you want to fetch second middle node else use fast->next!=NULL and fast->next->next!=NULL to fetch first middle node

Code : 

Node *findMiddle(Node *head) {
    // Write your code here
    if(!head or !head->next)
        return head;
    Node* slow = head;
    Node* fast = head;
    
    while(fast and fast->next){
        fast=fast->next->next;
        slow = slow->next;
    }
    return slow;
    
}
```

* ## Merge two sorted Linked Lists

```
Problem Statement: Given two singly linked lists that are sorted in increasing order of node values, merge two sorted linked lists and return them as a sorted list. The list should be made by splicing together the nodes of the first two lists.

Approach : Use the merge method of merge sort and start 
```