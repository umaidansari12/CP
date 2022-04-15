// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    void solve(vector<int>&A, int i, int N, int sum, set<vector<int>>&res, vector<int> r)
    {
        if (i == N)
        {
            if (sum == 0)
            {
                sort(r.begin(), r.end());
                res.insert(r);
            }
            return;
        }

        if (A[i] <= sum)
        {
            r.push_back(A[i]);
            solve(A, i + 1, N, sum - A[i], res, r);
            r.pop_back();
        }
        solve(A, i + 1, N, sum, res, r);
    }
    vector<vector<int>> combinationSum(vector<int> &A, int N, int B) {
        // code here
        vector<vector<int>> res;
        set<vector<int>> s;
        vector<int> r;
        solve(A, 0, N, B, s, r);
        for (auto i : s)
            res.push_back(i);
        sort(res.begin(), res.end());
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, x, B;
        cin >> N;
        vector<int> A;
        for (int i = 0; i < N; i++)
        {
            cin >> x;
            A.push_back(x);
        }
        cin >> B;

        Solution ob;
        vector<vector<int>> result;
        result = ob.combinationSum(A, N, B);

        if (result.size() == 0)
            cout << "Empty" << endl;
        else {
            for (int i = 0; i < result.size(); i++) {
                cout << "(";
                for (int j = 0; j < result[i].size(); j++) {
                    cout << result[i][j];
                    if (j < result[i].size() - 1)
                        cout << " ";
                }
                cout << ")";
            }
            cout << endl;
        }
    }
    return 0;
}  // } Driver Code Ends