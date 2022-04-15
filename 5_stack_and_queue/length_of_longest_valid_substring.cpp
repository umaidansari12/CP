// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
public:
    bool isBalanced(string s)
    {
        stack<char> st;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ')')
            {
                if (st.empty())
                    return false;
                st.pop();
            }
            else if (s[i] == '(')
                st.push(s[i]);
        }
        return st.size() == 0;
    }
    int findMaxLenBrute(string s) {
        // code here
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            string st;
            for (int j = i; j < s.size(); j++)
            {
                st += s[j];
                if (isBalanced(st))
                    ans = max(ans, j - i + 1);
                //else
                //break;
            }
        }
        return ans;
    }
    int findMaxLen(string str) {
        // code here
        int n = str.length();

        // Create a stack and push -1 as
        // initial index to it.
        stack<int> stk;
        stk.push(-1);

        // Initialize result
        int result = 0;

        // Traverse all characters of given string
        for (int i = 0; i < n; i++)
        {
            // If opening bracket, push index of it
            if (str[i] == '(')
                stk.push(i);

            // If closing bracket, i.e.,str[i] = ')'
            else
            {
                // Pop the previous opening
                // bracket's index
                if (!stk.empty())
                {
                    stk.pop();
                }

                // Check if this length formed with base of
                // current valid substring is more than max
                // so far
                if (!stk.empty())
                    result = max(result, i - stk.top());

                // If stack is empty. push current index as
                // base for next valid substring (if any)
                else
                    stk.push(i);
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
        string S;
        cin >> S;
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}
// } Driver Code Ends