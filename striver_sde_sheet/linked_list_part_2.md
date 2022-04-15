# Linked List - II
* ## Find the intersection point of a Y - shaped linked list
```
Problem Statement: Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

# Brute

Approach : For each node in the first linked list , traverse the second linked list from start to end and check if they have common references.

Code :

Node* intersection(Node* a,Node* b){
    while(a!=NULL){
        Node* curr = b;
        while(curr!=NULL){
            if(a==curr){
                return a;
            }
            curr = curr->next;                
        }
        a=a->next;
    }
    return NULL;
}

Time Complexity : O(M*N)
Space Complexity : O(1)


# Better 

Approach : Use hashing and store the nodes of first linked list in a hashmap then traverse the second linked list and check if current node is present in the hashmap or not.

int findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    unordered_set<Node*> hash;

    while (firstHead) {
        hash.insert(firstHead);
        firstHead = firstHead->next;
    }

    while (secondHead) {
        if (hash.find(secondHead) != hash.end())
            return secondHead->data;
        secondHead = secondHead->next;
    }

    return -1;
}

Time Complexity : O(M+N)
Space Complexity : O(M)

# Optimal

Approach : Calculate the length of both the linked list, then from the size of longer linked list subtract size of smaller linked list which is the difference step, now traverse the longer list difference steps and now both of the linked list are aligned and now we just need to traverse them simultaneously and if we found the same reference return true otherwise false.

Code : 

int findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    // steps first find  the length of both the linked lists then traverse the longer linked list and then move them simultaneously and when they collide you need to return that node's reference
    int length_first = 0, length_second = 0;

    Node* curr_first = firstHead;
    Node* curr_second = secondHead;

    while (curr_first) {
        length_first++;
        curr_first = curr_first->next;
    }

    while (curr_second) {
        length_second++;
        curr_second = curr_second->next;
    }

    if (length_first < length_second) {
        swap(length_first, length_second);
        swap(firstHead, secondHead);
    }

    int diff = length_first - length_second;

    while (diff--) {
        firstHead = firstHead->next;
    }

    while (firstHead and secondHead) {
        if (firstHead == secondHead)
            return firstHead->data;
        firstHead = firstHead->next;
        secondHead = secondHead->next;
    }

    return -1;
}

Time Complexity : M + N + (M-N) + N -> O(2(M+N)) -> O(M+N)
Space Complexity : O(1)

# Optimal 

Approach : Take two dummy nodes and point them to the head of both the linked list , if one node reached null then we assign that node to point to the head of the other linked list until both of the nodes becomes same , the intuition is as we are moving both of the linked list simultaneously so when move the shorter linked list to null the longer linked list will be difference step to reach null and as we assign shorter one to longer linked list so now it will travel the difference step from start and the longer linked list will complete the difference step and will be assigned to shorter linked list and now both of them are aligned and is ready to move simultaneously to find intersection as in above approach we are aligning them by moving difference steps.

Code : 

int findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    if (firstHead == NULL or secondHead == NULL)
        return -1;
    // the algorithm states that take two dummy nodes and point them to the head of both the
    // linked list , now start moving them simulatneously , when the shorter linked list
    // will reach null you will point it to head of longer linked list now head of longer linked list will be
    // at difference steps from the end now as the end of the longer linked list is reached you will move it to point to head of shorter linked list and as we are moving both the nodes simultaneously the head of shorter one which was pointed to longer one will be difference steps ahead and now we can move both the heads simutaneously as they are aligned together and we will check for equality

    Node* first_head = firstHead;
    Node* second_head = secondHead;

    while (first_head != second_head) {

        first_head = first_head ? first_head->next : secondHead;
        second_head = second_head ? second_head->next : firstHead;
    }


    return first_head ? first_head->data : -1;
}

Time Complexity : O(N+M)
Space Complexity : O(1)    
```

* ## Detect a cycle in a linked list
```
Problem Statement : Given head, the head of a linked list, determine if the linked list has a cycle in it. There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.

Return true if there is a cycle in the linked list. Otherwise, return false.

# Brute

Approach : Use hashmap , traverse the linked list and store every node in a hashmap and while traversing check if the current node is already present in the hashmap or not.

Code : 

bool detectCycle(Node *head)
{
	//	Write your code here
	unordered_set<Node*> found;
	while (head) {
		if (found.find(head->next) != found.end())
			return true;
		found.insert(head);
		head = head->next;
	}
	return false;
}

Time Complexity : O(N)
Space Complexity : O(N)

# Optimal

Approach : Use slow and fast pointer and they are bound to collide at some point if there is a cycle in the linked list.

Code :

bool detectCycle(Node *head)
{
	//	Write your code here
	Node* slow = head;
	Node* fast = head;

    // we are checking if fast pointer doesnt becomes null because null indicates that there is no cycle  and if there is a cycle then fast and slow pointer are bound to meet at some point in the cycle	
	while(fast->next and fast){
		slow = slow->next;
		fast = fast->next->next;
		if(fast==slow)
			return true;
	}
	
	return false;
}

Time Complexity : O(N)
Space Complexity : O(1)



```



