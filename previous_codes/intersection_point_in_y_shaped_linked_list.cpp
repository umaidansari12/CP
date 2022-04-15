//If given lists are of equal size, we can traverse both of
//them simultaneously and check for the intersecting node.

int intersectionPoint(Node* head1, Node* head2)
{
    int n1 = 0, n2 = 0;
    Node* temp;

    for (temp = head1; temp; temp = temp->next)
        n1++;
    // finding length of list 1

    for (temp = head2; temp; temp = temp->next)
        n2++;
    // finding length of list 2

    for (  ; n1 > n2 ; n1-- )
        head1 = head1->next;
    // if list1 is longer, we ignore some of its starting
    // elements till it has as many elements as list2

    for (  ; n2 > n1 ; n2-- )
        head2 = head2->next;
    // similarly
    // if list2 is longer, we ignore some of its starting
    // elements till it has as many elements as list1

    while ( head1 != head2 )
    {
        head1 = head1->next;
        head2 = head2->next;
        // now we simple traverse ahead till we get the
        // intersection point, if there is none, this loop
        // will break when both pointers point at NULL
    }

    if (head1) return head1->data;
    // if head1 is not NULL, we return its data
    return -1;       // otherwise we return -1
}


//optimal solution

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL)
            return NULL;
        int c1 = 0, c2 = 0;
        ListNode* a = headA;
        ListNode* b = headB;
        while (a != NULL || b != NULL)
        {
            if (a)
            {
                c1++;
                a = a->next;
            }
            if (b)
            {
                c2++;
                b = b->next;
            }
        }
        a = headA;
        b = headB;
        int diff = 0;
        if (c1 > c2)
        {
            swap(a, b);
            diff = c1 - c2;
        }
        else
        {
            diff = c2 - c1;
        }
        while (diff--)
            b = b->next;
        while (a != NULL && b != NULL)
        {
            if (a == b)
                return a;
            a = a->next;
            b = b->next;
        }
        return a;

    }
};

//optimal plus concise code
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL)
            return NULL;
        ListNode* a = headA;
        ListNode* b = headB;
        while (a != b)
        {
            a = (a == NULL) ? headB : a->next;
            b = (b == NULL) ? headA : b->next;
        }
        return a;

    }
};


int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    while (head1 != NULL)
    {
        Node* temp = head2;
        while (temp != NULL)
        {
            if (temp == head1)
                return head1->data;
            temp = temp->next;
        }
        head1 = head1->next;
    }
    return 0;
}

int intersectionPoint(Node* head1, Node* head2)
{
    // Your Code Here
    int c1 = 0, c2 = 0;
    Node* h1 = head1;
    Node* h2 = head2;
    while (h1 != NULL)
    {
        c1++;
        h1 = h1->next;
    }
    while (h2 != NULL)
    {
        c2++;
        h2 = h2->next;
    }
    int d = abs(c1 - c2);
    h1 = head1;
    h2 = head2;
    if (c1 > c2)
    {
        while (d--)
        {
            h1 = h1->next;
        }
    }
    else
    {
        while (d--)
        {
            h2 = h2->next;
        }
    }
    while (h1 != NULL && h2 != NULL)
    {
        if (h1 == h2)
            return h1->data;
        h1 = h1->next;
        h2 = h2->next;

    }
    return -1;
}

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        while (headA != NULL)
        {
            ListNode* temp = headB;
            while (temp != NULL)
            {
                if (temp == headA)
                    return temp;
                temp = temp->next;
            }
            headA = headA->next;
        }
        return headA;
    }
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> seen;
        while (headA != NULL)
        {
            seen.insert(headA);
            headA = headA->next;
        }
        while (headB != NULL)
        {
            if (seen.find(headB) != seen.end())
                return headB;
            headB = headB->next;
        }
        return headA;
    }
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, int> m;
        while (headA)
        {
            m[headA]++;
            headA = headA->next;
        }
        while (headB)
        {
            if (m.find(headB) != m.end())
                return headB;
            headB = headB->next;
        }
        return NULL;

    }
};