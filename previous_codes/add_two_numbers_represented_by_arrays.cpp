#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    string calc_Sum(int *a, int n, int *b, int m) {
        // Complete the function
        int i = n - 1, j = m - 1, carry = 0, sum = 0;
        string s;
        while (i >= 0 && j >= 0)
        {
            sum = a[i--] + b[j--] + carry;
            carry = sum < 10 ? 0 : 1;
            sum %= 10;
            s += to_string(sum);
        }
        while (i >= 0)
        {
            sum = a[i--] + carry;
            carry = sum < 10 ? 0 : 1;
            sum %= 10;
            s += to_string(sum);
        }
        while (j >= 0)
        {
            sum = b[j--] + carry;
            carry = sum < 10 ? 0 : 1;
            sum %= 10;
            s += to_string(sum);
        }
        if (carry)
            s += to_string(carry);
        reverse(s.begin(), s.end());
        i = 0;
        while (i < s.size() && s[i] == '0')
            i++;
        return s.substr(i, s.size() - i + 1);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int m;
        cin >> m;
        int b[m];
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        Solution ob;
        cout << ob.calc_Sum(a, n, b, m) << endl;
    }
    return 0;
}  // } Driver Code Ends