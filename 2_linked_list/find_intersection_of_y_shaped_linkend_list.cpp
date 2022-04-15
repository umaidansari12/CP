/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
        };

*****************************************************************/

int findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    while (firstHead) {
        Node* second_temp = secondHead;
        while (second_temp) {
            if (second_temp == firstHead)
                return firstHead->data;
            second_temp = second_temp->next;
        }
        firstHead = firstHead->next;
    }
    return -1;
}

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
        };

*****************************************************************/
#include <bits/stdc++.h>

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