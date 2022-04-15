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
/*The idea is to add zeros to the start of the smaller list (which is allowed since it doesn't tamper with the original structure of the list) such that both the lists become of equal size and then use recursion to perform digit by digit addition (starting from the last digits, obviously).

For example consider the following lists,

l1: 7->2->4->3
l2: 5->6->4
After adding zeros to l2 (the smaller list), the lists become,

l1: 7->2->4->3
l2: 0->5->6->4
We now use recursion to dive to the end of both the lists and start addition from the end.
After each recursion ends, l1 and l2 will be waiting at the previous nodes, so an indirect reverse traversal is obtained without the use of a doubly linked list.
The key is being able to pass carry from current recursive function to the previous recursive function, for which we can pass the reference variable carry to function calls so that the changes made to carry reflect through all the recursive calls made.

If the concept is still not clear, dry running the code using pen and paper will surely help.

(P.S - This program might seem lengthy, and although most of it stems from the "adding zero" process, I did not want to reduce the length and compromise readability.)

Happy Coding..!!*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //Adding zeros to the start of the smaller list:
        ListNode *ptr1 = l1, *ptr2 = l2;
        while (ptr1 != NULL || ptr2 != NULL)
        {
            if (ptr1 == NULL)
            {
                ListNode *newNode = new ListNode(0);
                newNode->next = l1;
                l1 = newNode;

                ptr2 = ptr2->next;
            }
            else if (ptr2 == NULL)
            {
                ListNode *newNode = new ListNode(0);
                newNode->next = l2;
                l2 = newNode;

                ptr1 = ptr1->next;
            }
            else
            {
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
        }

        //Main operation:
        int carry = 0;
        ListNode *dummy = new ListNode(-1);
        dummy->next = addTwoDigit(l1, l2, carry);
        if (carry != 0)
        {
            ListNode *newNode = new ListNode(carry);
            newNode->next = dummy->next;
            dummy->next = newNode;
        }

        return dummy->next;
    }

    ListNode* addTwoDigit(ListNode* l1, ListNode* l2, int &carry)
    {
        if (l1 == NULL && l2 == NULL)
            return NULL;

        ListNode *newNode = new ListNode(-1);
        newNode->next = addTwoDigit(l1->next, l2->next, carry);

        newNode->val = (l1->val + l2->val + carry) % 10;
        carry = (l1->val + l2->val + carry) / 10;

        return newNode;
    }
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int n1 = 0, n2 = 0, carry = 0;
    ListNode *curr1 = l1, *curr2 = l2, *res = NULL;
    while ( curr1 ) { curr1 = curr1->next; n1++; }
    while ( curr2 ) { curr2 = curr2->next; n2++; }
    curr1 = l1; curr2 = l2;
    while ( n1 > 0 && n2 > 0) {
        int sum = 0;
        if ( n1 >= n2 ) { sum += curr1->val; curr1 = curr1->next; n1--;}
        if ( n2 > n1 ) { sum += curr2->val; curr2 = curr2->next; n2--;}
        res = addToFront( sum, res );
    }
    curr1 = res; res = NULL;
    while ( curr1 ) {
        curr1->val += carry; carry = curr1->val / 10;
        res = addToFront( curr1->val % 10, res );
        curr2 = curr1;
        curr1 = curr1->next;
        delete curr2;
    }
    if ( carry ) res = addToFront( 1, res );
    return res;
}
ListNode* addToFront( int val, ListNode* head ) {
    ListNode* temp = new ListNode(val);
    temp->next = head;
    return temp;
}
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* current = l1;
        vector<int> a, b;
        while (current)
        {
            a.push_back(current->val);
            current = current->next;
        }
        current = l2;
        while (current)
        {
            b.push_back(current->val);
            current = current->next;
        }
        int n = a.size() - 1, m = b.size() - 1, sum = 0, carry = 0;
        ListNode* ans = NULL;
        ListNode* node = NULL;
        ListNode* ne = NULL;
        while (n >= 0 || m >= 0)
        {
            int c = (n < 0) ? 0 : a[n];
            int d = (m < 0) ? 0 : b[m];
            sum = (carry + c + d >= 10) ? (carry + c + d) % 10 : (carry + c + d);
            carry = (carry + c + d) >= 10 ? 1 : 0;
            if (ans == NULL)
            {
                ans = new ListNode(sum);
                node = ans;
            }
            else
            {
                ne = new ListNode(sum);
                ne->next = node;
                node = ne;
            }
            if (n >= 0)
                n--;
            if (m >= 0)
                m--;
        }
        if (carry >= 1)
        {
            ne = new ListNode(carry);
            ne->next = node;
            node = ne;
        }

        return node;
    }
};