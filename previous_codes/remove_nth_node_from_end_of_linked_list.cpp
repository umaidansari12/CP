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
/*class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* h = head;
        while (count < n)
        {
            h = h->next;
            count++;
        }
        h->next = h->next->next;
        return head;


    }
};*/

//one pass solution

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start = new ListNode();
        start->next = head;
        ListNode* fast = start;
        ListNode* slow = start;
        while (n--)
        {
            fast = fast->next;
        }
        while (fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return start->next;

    }
};

//two pass solution
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* h = head;
        int count = 0;
        while (h)
        {
            h = h->next;
            count++;
        }
        //cout<<count-n<<endl;
        h = head;
        if (n == count)
        {
            head = head->next;
            return head;
        }

        count = count - n - 1;
        while (count--)
            h = h->next;
        ListNode* node = h->next;
        h->next = h->next->next;
        delete(node);
        return head;

    }
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* h = head;
        int count = 0;
        while (h)
        {
            h = h->next;
            count++;
        }
        //cout<<count-n<<endl;
        h = head;
        if (n == count)
        {
            head = head->next;
            return head;
        }

        count = count - n - 1;
        while (count--)
            h = h->next;
        ListNode* node = h->next;
        h->next = h->next->next;
        return head;

    }
};