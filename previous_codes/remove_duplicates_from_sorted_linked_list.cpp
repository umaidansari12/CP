Node *removeDuplicates(Node *root)
{
// your code goes here
    Node* current = root;
    while (current->next != NULL)
    {
        if (current->data == current->next->data)
        {
            Node* next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        }
        else
        {
            current = current->next;
        }
    }
    return root;
}

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)
            return head;
        ListNode* current = head;
        while (current->next != NULL)
        {
            if (current->val == current->next->val)
            {
                ListNode* next_next = current->next->next;
                delete(current->next);
                current->next = next_next;
            }
            else
            {
                current = current->next;
            }
        }
        return head;
    }
};