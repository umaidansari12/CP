
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    bool isPerfect(int i)
    {
        int s = 0, e = i;
        float ans = 0;
        while (s <= e)
        {
            int mid = (s + e) / 2;
            if (mid * mid == i)
                return true;
            if (mid * mid < i)
                s = mid + 1;
            else
                e = mid - 1;
        }
        return false;
    }
    int countSquares(int N) {
        // code here
        int ans = 0;
        for (int i = 1; i < N; i++)
        {
            if (isPerfect(i))
                ans++;
        }
        return ans;
    }
    //O(sqrt(N))
    int countSquaresOptimal(int N) {
        // code here
        int ans = 0;
        for (int i = 1; i * i < N; i++)
        {
            ans++;
        }
        return ans;
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
        cout << ob.countSquares(N) << endl;
    }
    return 0;
}  // } Driver Code Ends