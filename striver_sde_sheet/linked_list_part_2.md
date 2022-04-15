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

    


    
    ```


