// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    vector<int> primeDivision(int N) {
        // code herev
        vector<int> prime(N + 2, 1);
        vector<int> r;
        prime[0] = prime[1] = 0;
        for (int i = 2; i * i <= N; i++)
        {
            if (prime[i])
            {
                for (int j = i * i; j <= N; j += i)
                {
                    prime[j] = 0;
                }
            }
        }
        for (int i = 2; i <= N; i++)
        {
            if (prime[i] and prime[N - i])
            {
                return {i, N - i};
            }
        }
        return r;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        Solution ob;
        vector<int> ans = ob.primeDivision(N);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends