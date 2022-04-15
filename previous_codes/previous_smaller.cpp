vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int> s;
    int n = A.size();
    vector<int> r(n);
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && s.top() >= A[i])
        {
            s.pop();
        }
        if (s.empty())
            r[i] = -1;
        else
            r[i] = s.top();
        s.push(A[i]);
    }
    return r;
}
