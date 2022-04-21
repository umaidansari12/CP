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

# Brute

Approach : Use the merge method of merge sort and start merging the nodes by first comparing the node's value and then make the pointer point to smaller value either by creating a new list or by just modifying the pointers in old list.

Code :

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

Time Complexity : O(N+M)
Space Complexity : O(1) // if modifying the pointers 
                   O(N+M) // if creating a new list out of the sorted values

# Optimal (Inplace merging without using extra space)

Approach : Make the list1 point to smaller value and list2 to greater value and make a dummy node which can maintain the head of the linked list.Now as we store the smallest value out of the head of both the linked list in list1 so we will start traversing the list1 until it has value lesser than list2 so as to maintain a sorted order and also maintaining a previous node which is needed to connect list1 and list2 in sorted order and swap(list1,list2)

Code : 

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    // if either of the list is empty then return the other list
    // when list1 is empty then 
    // our output will be same as list2
    if (!first)
        return second;
    // when list2 is empty then our output 
    // will be same as list1
    if (!second)
        return first;

    // pointing l1 and l2 to smallest and greatest one
    // check which one's first value is smaller and swap if needed because we need to have first one as smaller
    if (first->data > second->data) {
        swap(first, second);
    }
    // act as head of resultant merged list
    //create a dummy head to retain the head of the original linked list
    Node<int> *newHead = first;

    while (first != NULL and second != NULL) {
        // maintain a previous node to keep track of the last node visited so as to broke the current link and join it with the second list

        // the intuition is to traverse the first list until we are getting values which are lesser than second's value then broke the link and point the last node visited in first to second node after that swap because we have got value in first which is greater than second so swap to move smaller again to first to get the nodes in increasing order

        Node<int>* previous = NULL;

        while (first and first->data <= second->data) {
            //storing last sorted node 
             
            previous = first;

            first = first->next;
        }

        // link previous sorted node with 
        // next larger node in list2
        previous->next = second;
        swap(first, second);
    }

    return newHead;
}
Time Complexity : O(N+M)
Space Complexity : O(1)
```

* ## Remove N-th node from the end of a Linked List

```
Problem Statement: Given a linked list, and a number N. Find the Nth node from the end of this linkedlist, and delete it. Return the head of the new modified linked list.

# Brute

Approach : Count the number of nodes in the linked list, as per the observation we can see the n-th node from end will be (size-n)th node from start so we traverse the list (size-n-1) times maintaining a previous pointer also to delete (size-n)th node

Code :

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
    // Write your code here.
    if(!head)
        return head;

    int _size = 0;
    
    LinkedListNode<int> *curr = head;
    
    while(curr){
        _size++;
        curr=curr->next;
    }
    
    if(K==0)
        return head;
    
    if(_size==K)
        return head->next;
    if(K>_size)
        return head;
    
    
    int steps = (_size-K);

    
    curr = head;
    LinkedListNode<int> *prev = NULL;
    for(int i=0;i<steps;i++){
        prev=curr;
        curr=curr->next;        
    }
    
    prev->next = (curr->next)?curr->next:NULL;
    
    return head;
}

Time Complexity : O(N) + O(N-K) ! O(N)
Space Compexity : O(1)

# Optimal 

Approach : Make use of two pointers as we are not allowed to traverse two times and nth node from end will be equal to (size-n)th node from start. what if we advance the fast pointer n steps and then move both slow and fast pointers simultaneously until fast reaches null we will see that the slow pointer will now stand at (size-n)th node from start i.e nth node from end.

Code : 

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
    // Write your code here.
    if(!head)
        return head;
    
    if(K==0)
        return head;
    
    LinkedListNode<int> *fast = head;
    LinkedListNode<int> *slow = head;
    
    for(int i=0;i<K;i++){
        if(fast->next==NULL){
            if(i==(K-1)){
                return head->next;
            }
            return head;
        }
        fast = fast->next;
        
    }
    
    while(fast->next){
        slow=slow->next;
        fast=fast->next;
    }
    
    slow->next = slow->next->next;
    
    return head;
}

Time Complexity : O(N)
Space Complexity : O(1)
```

* ## Add two numbers represented as Linked Lists

```
Problem Statement: Given the heads of two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

Approach : Use elementary mathematics and start adding values one by one and make use of carry and remainder and maintain a new linked list that will store the answer

Code :


Node *addTwoNumbers(Node *head1, Node *head2)
{
    // Write your code here.
	Node* ans = NULL;
    Node* prev = NULL;
    
    if(!head1)
        return head2;
    if(!head2)
        return head1;
    
    int carry = 0;
    
    while((head1 or head2) or carry){
        
        int a = (head1)?head1->data:0;
        int b = (head2)?head2->data:0;
        
        int sum = (carry+a+b);
        carry = (sum)/10;
        sum%=10;
        
        if(ans==NULL){
            ans = new Node(sum);
            prev = ans;
        }
        else{
            prev->next = new Node(sum);
            prev=prev->next;
        }      
        head1=(head1)?head1->next:NULL;
        head2=(head2)?head2->next:NULL;
    }
    
    //     if(carry){
    //         prev->next = new Node(carry);
    //     }
    
    return ans;
}

Time Complexity : O(max(N,M))
Space Complexity : O(max(N,M))
```

* ## Delete given node in a Linked List : O(1) approach

```
Problem Statement: Write a function to delete a node in a singly-linked list. You will not be given access to the head of the list instead, you will be given access to the node to be deleted directly. It is guaranteed that the node to be deleted is not a tail node in the list.

Approach : Replace given node's value with value that is placed towards its next pointer and then point given node's next pointer to node that is pointed by it's next pointer

Code :

void deleteNode(LinkedListNode<int> * node) {
    // Write 
    node->data = node->next->data;
    node->next = node->next->next;
}

Time Complexity : O(1)
Space Complexity : O(1)
```