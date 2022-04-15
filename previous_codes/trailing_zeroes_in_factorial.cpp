#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    int trailingZeroes(int n)
    {
        // Write Your Code here
        int count = 0;
        for (int i = 5; n / i >= 1; i *= 5)
        {
            count += (n / i);
        }
        return count;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        int ans  = ob.trailingZeroes(N);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends

class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while (n) {
            n /= 5;
            res += n;
        }
        return res;

    }
};