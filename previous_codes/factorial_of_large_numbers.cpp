#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> factorial(int N) {
        // code here
        vector<int> r;
        r.push_back(1);
        for (int i = 1; i <= N; i++)
        {
            int carry = 0, n = r.size();
            for (int j = 0; j < n; j++)
            {
                int sum = (r[j] * i) + carry;
                r[j] = (sum) % 10;
                carry = sum / 10;
            }
            while (carry > 0)
            {
                r.push_back(carry % 10);
                carry /= 10;
            }
        }
        reverse(r.begin(), r.end());
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
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i];
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends