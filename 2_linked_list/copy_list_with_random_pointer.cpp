/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    void createList(RandomListNode* head, unordered_map<RandomListNode*, RandomListNode*> &mp) {
        while (head != NULL) {
            mp[head] = new RandomListNode(head->label);
            head = head->next;
        }
    }
    void connectRandom(RandomListNode* head, unordered_map<RandomListNode*, RandomListNode*> &mp) {
        while (head != NULL) {
            mp[head]->next = mp[head->next];
            mp[head]->random = mp[head->random];
            head = head->next;
        }

    }
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        unordered_map<RandomListNode*, RandomListNode*> mp;
        createList(head, mp);
        connectRandom(head, mp);
        return mp[head];
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* iter = head;
        Node* front = head;
        //1st step creation of deep copy nodes and pointing them as next of original node
        while (iter != NULL)
        {
            front = iter->next;
            Node* copy = new Node(iter->val);
            iter->next = copy;
            copy->next = front;
            iter = front;
        }
        //2nd step creation and pointing of random pointer
        iter = head;
        while (iter != NULL)
        {
            front = iter->next->next;
            if (iter->random != NULL)
                iter->next->random = iter->random->next;
            iter = front;
        }
        //segregation of original and deep copy linked list
        Node* pseudo_head = new Node(0);
        Node* copy = pseudo_head;
        iter = head;
        while (iter != NULL)
        {
            front = iter->next->next;
            copy->next = iter->next;
            iter->next = front;
            copy = copy->next;
            iter = iter->next;
        }
        return pseudo_head->next;

    }
};