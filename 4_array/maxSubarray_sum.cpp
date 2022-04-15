#include<bits/stdc++.h>
using namespace std;

//kadanes algorithm

int maxSumSubarray(vector<int> A) {
    int largest = INT_MIN, cs = 0;
    for (int i = 0; i < A.size(); i++)
    {
        cs += A[i];
        largest = max(largest, cs);
        if (cs < 0)
            cs = 0;

    }
    return largest;
}

//prefix sum approach

int maxSumSubarray(vector<int> A) {
    int largest = INT_MIN, cs = 0, n = A.size();
    int pre[n] = {0};
    pre[0] = A[0];
    for (int i = 1; i < n; i++)
        pre[i] = pre[i - 1] + A[i];
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = i; j < n; j++)
        {
            largest = max(largest, pre[j] - ((i > 0) ? pre[i - 1] : 0));
        }
    }
    return largest;
}

// brute force n2