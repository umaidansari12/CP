#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution {
public:
    long long f(int n)
    {
        long long pro = 1;
        for (int i = 1; i <= n; i++)
        {
            pro = ((pro % 1000000007) * (i % 1000000007)) % 1000000007;
        }
        return pro;
    }
    vector<long long> factorial(vector<long long> a, int n) {
        vector<long long> fact(n, 0);
        int m = *max_element(a.begin(), a.end());
        vector<long long> r(m + 1, 1);
        for (int i = 1; i <= m; i++)
            r[i] = ((i % 1000000007) * (r[i - 1] % 1000000007)) % 1000000007;
        for (int i = 0; i < n; i++)
        {
            fact[i] = r[a[i]];
        }
        return fact;

    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<long long> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<long long> res = ob.factorial(a, n);
        for (i = 0; i < n; i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends