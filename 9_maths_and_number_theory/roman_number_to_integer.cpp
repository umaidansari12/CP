// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
public:
    int value(char ch) {
        if (ch == 'I')
            return 1;
        else if (ch == 'V')
            return 5;
        else if (ch == 'X')
            return 10;
        else if (ch == 'L')
            return 50;
        else if (ch == 'C')
            return 100;
        else if (ch == 'D')
            return 500;
        else if (ch == 'M')
            return 1000;
        return 0;
    }
    int romanToDecimal(string &str) {
        // code here
        int result = 0, n = str.size();
        for (int i = 0; i < n; i++) {
            int value1 = value(str[i]);
            if (i + 1 < n) {
                int value2 = value(str[i + 1]);
                if (value2 > value1) {
                    result += (value2 - value1);
                    i++;
                }
                else {
                    result += value1;
                }
            }
            else {
                result += value1;
            }
        }
        return result;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}  // } Driver Code Ends