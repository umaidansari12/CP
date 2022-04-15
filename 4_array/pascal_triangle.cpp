#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
// #define ll long long
class Solution {
public:
    vector<ll> nthRowOfPascalTriangle(int n) {
        // code here
        vector<vector<ll>> dp(n);
        int mod = 1e9 + 7;
        for (long long int i = 0; i < n; i++) {
            dp[i].resize(i + 1);
            dp[i][0] = dp[i][i] = 1;
            for (long long int j = 1; j < i; j++) {
                dp[i][j] = ((dp[i - 1][j - 1] % mod) + (dp[i - 1][j] % mod)) % mod;
            }
        }
        return dp[n - 1];
    }

    class Solution {
    public:
        vector<ll> nthRowOfPascalTriangle(int n) {
            // code here
            vector<ll> dp(n);
            int mod = 1e9 + 7;
            dp[0] = 1;
            for (long long int i = 0; i < n; i++) {
                for (long long int j = i; j > 0; j--) {
                    dp[j] = ((dp[j] % mod) + (dp[j - 1] % mod)) % mod;
                }
            }
            return dp;
        }
    };
};


// { Driver Code Starts.


void printAns(vector<ll> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}
// } Driver Code Ends