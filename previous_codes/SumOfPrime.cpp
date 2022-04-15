
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:

    vector<int> getPrimes(int N) {
        // code here
        /*vector<int> res1;
        res1.push_back(-1);
        res1.push_back(-1);*/
        bool prime[N + 1];
        memset(prime, true, sizeof(prime));

        prime[0] = prime[1] = false;
        for (int i = 2; i * i <= N; i++)
        {
            if (prime[i])
            {
                for (int j = i * i; j <= N; j += i)
                    prime[j] = false;
            }
        }
        int ans1 = -1, ans2 = -1;
        for (int i = 2; i <= (N / 2); i++)
        {
            if (prime[i])
            {
                if (prime[N - i])
                {
                    ans1 = i;
                    ans2 = N - i;
                    break;
                }
            }
        }
        vector<int> r;
        r.push_back(ans1);
        r.push_back(ans2);
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
        vector<int> ptr = ob.getPrimes(N);
        cout << ptr[0] << " " << ptr[1] << endl;
    }
    return 0;
}  // } Driver Code Ends