#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution {
public:
    // #define ll long long
    int mod = 1e9 + 7;
    ll solve(int n, string s)
    {
        if (n == 0)
        {
            return 1;
        }
        if (s.size() == 0)
        {
            return ((solve(n - 1, s + '1') % mod) + (solve(n - 1, s + '0') % mod)) % mod;
        }
        else
        {
            if (s[s.size() - 1] == '0')
                return ((solve(n - 1, s + '1') % mod) + (solve(n - 1, s + '0') % mod)) % mod;
            else
                return (solve(n - 1, s + '0') % mod);

        }
    }
    ll countStringsRecur(int n) {
        // code here
        return solve(n, "") % mod;
    }
    void generate(int i, int n, vector<string> &r, string s)
    {
        if (i == n)
        {
            r.push_back(s);
            return;
        }
        generate(i + 1, n, r, s + '1');
        generate(i + 1, n, r, s + '0');
    }
    ll countStrings(int n) {
        // code here
        vector<string> r;
        ll count = 0, mod = 1e9 + 7;
        generate(0, n, r, "");
        for (auto i : r)
        {
            //cout << i << " ";
            int j = 0;
            for (j = 0; j < i.size() - 1; j++)
            {
                if (i[j] == i[j + 1] and i[j] == '1')
                {
                    break;
                }
            }
            if (j == i.size() - 1)
                count = (count + 1) % mod;
        }
        //cout << endl;
        return count;
    }
    /*
    This problem can be solved using Dynamic Programming.
    Let a[i] be the number of binary strings of length i which do not
    contain any two consecutive 1’s and which end in 0.
    Similarly, let b[i] be the number of such strings which end in 1.
    We can append either 0 or 1 to a string ending in 0, but we can only append 0
     to a string ending in 1. This yields the recurrence relation:

    a[i] = a[i - 1] + b[i - 1]
    b[i] = a[i - 1]
    The base cases of above recurrence are a[1] = b[1] = 1. The total number of
    strings of length i is just a[i] + b[i].
    Following is the implementation of above solution. In the following
    implementation, indexes start from 0. So a[i] represents the number of
    binary strings for input length i+1. Similarly, b[i] represents binary string
     for input length i+1.
     */
    ll countStringsBottomUp(int n) {
        // code here
        vector<long long> a(n, 0), b(n, 0);
        ll mod = 1e9 + 7;
        a[0] = b[0] = 1;
        for (int i = 1; i < n; i++)
        {
            a[i] = ((a[i - 1] % mod) + (b[i - 1] % mod)) % mod;
            b[i] = a[i - 1] % mod;
        }
        return ((a[n - 1] % mod) + (b[n - 1] % mod)) % mod;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStringsBottomUp(n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends