int Solution::solve(ListNode* A, int B) {
    ListNode* curr = A;
    int total = 0;
    while (curr != NULL)
    {
        total++;
        curr = curr->next;
    }
    int mid = (total / 2) + 1;
    int find = mid - B;
    curr = A;
    while (find-- > 1)
    {
        curr = curr->next;
    }

    return (B > mid) ? -1 : curr->val;
}
