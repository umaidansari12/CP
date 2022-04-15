#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Given a street of N houses (a row of houses),
// each house having K amount of money kept inside; now there is a
// thief who is going to steal this money but he has a
// constraint/rule that he cannot steal/rob two adjacent houses. Find
// the maximum money he can rob. Simply we need to print the result
// as (n/2)*money if n is even else n is odd  then (n/2+1) *money
class Solution {
public: int maximizeMoney(int N , int K) {
        // code here
        return ((N + 1) / 2) * K;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;

        cin >> N >> K;

        Solution ob;
        cout << ob.maximizeMoney(N, K) << endl;
    }
    return 0;
}  // } Driver Code Ends