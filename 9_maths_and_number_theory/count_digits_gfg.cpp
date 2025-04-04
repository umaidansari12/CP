//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int evenlyDivides(int N) {
        //code here
        int tempNum = N, count = 0;

        while (tempNum > 0) {
            int digit = tempNum % 10;
            tempNum /= 10;
            if (digit != 0 and N % digit == 0)
                count++;
        }
        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.evenlyDivides(N) << endl;
    }
    return 0;
}
// } Driver Code Ends