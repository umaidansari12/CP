
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    string isSumOfTwo(int N) {
        // code here
        vector<int> prime(N + 1, 1);
        prime[0] = prime[1] = 0;
        for (int i = 2; i <= N; i++)
        {
            if (prime[i])
            {
                for (int j = i * i; j <= N; j += i)
                {
                    if (prime[j])
                        prime[j] = 0;
                }
            }
        }
        for (int i = 2; i <= N; i++)
        {
            if (prime[i] and prime[N - i])
                return "Yes";
        }
        return "No";
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
        cout << ob.isSumOfTwo(N) << endl;
    }
    return 0;
}
// } Driver Code Ends