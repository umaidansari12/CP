/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//inplace solution
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        ListNode* r;
        if (l1->val > l2->val)
            swap(l1, l2);
        r = l1;
        while (l1 != NULL && l2 != NULL)
        {
            ListNode* tmp = NULL;
            while (l1 != NULL && l1->val <= l2->val)
            {
                tmp = l1;
                l1 = l1->next;
            }
            tmp->next = l2;
            swap(l2, l1);
        }
        return r;

    }
};



/* Link list Node
struct Node {
  int data;
  struct Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

Node* sortedMerge(Node* head_A, Node* head_B)
{
    // code here
    Node* newHead = new Node(0);
    Node* newList = newHead;
    while (head_A != NULL && head_B != NULL)
    {
        if (head_A->data <= head_B->data)
        {
            newList->next = head_A;
            newList = newList->next;
            head_A = head_A->next;
        }
        else
        {
            newList->next = head_B;
            newList = newList->next;
            head_B = head_B->next;
        }
    }
    if (head_A != NULL)
    {
        newList->next = head_A;
    }
    else
    {
        newList->next = head_B;
    }
    newList = newHead->next;
    return newList;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* dd = dummy;
        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val <= l2->val)
            {
                dd->next = new ListNode(l1->val);
                dd = dd->next;
                l1 = l1->next;
            }
            else
            {
                dd->next = new ListNode(l2->val);
                dd = dd->next;
                l2 = l2->next;
            }
        }
        while (l1 != NULL)
        {
            dd->next = new ListNode(l1->val);
            dd = dd->next;
            l1 = l1->next;
        }
        while (l2 != NULL)
        {
            dd->next = new ListNode(l2->val);
            dd = dd->next;
            l2 = l2->next;
        }

        return dummy->next;
    }
};

