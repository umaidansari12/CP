int Solution::solve(vector<int> &A, int B) {
    int n = A.size(), count = 0;
    for (int i = 0; i < n; i++)
    {
        int xr = 0;
        for (int j = i; j < n; j++)
        {
            xr ^= A[j];
            if (xr == B)
                count++;
        }
    }
    return count;
}

// O(n^2) solution above

int Solution::solve(vector<int> &A, int B) {
    int n = A.size(), count = 0, xr = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        xr ^= A[i];
        if (xr == B)
            count++;
        if (m.find(xr ^ B) != m.end())
            count += m[xr ^ B];
        m[xr]++;

    }
    return count;
}

