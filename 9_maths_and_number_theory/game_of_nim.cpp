//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    int nimGame(int N) {
        // code here
        return (N % 2) != 0;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, X;
        cin >> N;

        Solution ob;
        if (ob.nimGame(N) == 1)
            cout << "Player A\n";
        else
            cout << "Player B\n";
    }
    return 0;
}
// } Driver Code Ends