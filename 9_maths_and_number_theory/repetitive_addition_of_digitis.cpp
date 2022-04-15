#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    int singleDigit(long long N)
    {
        // Write Your Code here
        while (N >= 10)
        {
            long long temp = N, sum = 0;
            while (temp)
            {
                sum += (temp % 10);
                temp /= 10;
            }
            N = sum;
        }
        return N;
    }
    int singleDigit(long long N)
    {
        // Write Your Code here
        // if N is 0 then return 0;
        if (N == 0)
            return 0;
        // if N is divisible by 9 then eventually it will land to sum of digits as 9 ex-2880 else if not divisible then land to N%9

        return (N % 9) == 0 ? 9 : N % 9;

    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long N;
        cin >> N;
        Solution ob;
        int ans  = ob.singleDigit(N);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends