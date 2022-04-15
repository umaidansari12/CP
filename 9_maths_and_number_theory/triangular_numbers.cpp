// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int isTriangular(int N) {
        //code here
        int sum = 0, i = 1;
        while (sum < N) {
            sum += i;
            i++;
        }
        return sum == N;
    }
    int isTriangular(int N) {
        //code here
        if (N < 0)
            return 0;

        // n*(n+1) = num
        // n2 + n + (-2 * num) = 0

        int c = -2 * N;
        int a = 1, b = 1;
        int d = (b * b) - (4 * a * c);

        if (d < 0)
            return 0;

        float root1 = (-b - sqrt(d)) / (2 * a);
        float root2 = (-b + sqrt(d)) / (2 * a);

        if (root1 > 0 and floor(root1) == root1)
            return 1;

        if (root2 > 0 and floor(root2) == root2)
            return 1;

        return 0;
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
        cout << ob.isTriangular(N) << "\n";
    }
}  // } Driver Code Ends