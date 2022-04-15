#include<bits/stdc++.h>
using namespace std;

//minimum number of reversals needed to make the string balanced

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal// } Driver Code Ends

bool isBalanced(string s)
{
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '}')
        {
            if (st.empty())
                return false;
            st.pop();
        }
        else if (s[i] == '{')
            st.push('{');
    }
    return st.size() == 0;
}

int solve(string &s, int idx, int steps)
{
    if (idx == s.size())
    {
        //cout << s << endl;
        if (isBalanced(s))
            return steps;
        else
            return INT_MAX;
    }

    if (s[idx] == '{')
        s[idx] = '}';
    else if (s[idx] == '}')
        s[idx] = '{';
    //cout << s << endl;
    int ans1 = solve(s, idx + 1, steps + 1);
    if (s[idx] == '{')
        s[idx] = '}';
    else if (s[idx] == '}')
        s[idx] = '{';
    // cout << s << endl;
    int ans2 = solve(s, idx + 1, steps);

    return min(ans1, ans2);
}

int countRevRecur (string s)
{
    // your code here;
    int n = s.size();
    if (n % 2 != 0)
        return -1;
    int ans = solve(s, 0, 0);
    return ans == INT_MAX ? -1 : ans;
}

int countRev (string s)
{
    // your code here
    int n = s.size();
    if (n % 2 != 0)
        return -1;
    stack<char> st;
    int open = 0 , close = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '{')
        {
            st.push(s[i]);
            open++;
        }
        else if (s[i] == '}' and !st.empty() and st.top() == '{')
        {
            st.pop();
            open--;
        }
        else
            close++;
    }
    if (open % 2 == 0)
        open /= 2;
    else
        open = (open / 2) + 1;
    if (close % 2 == 0)
        close /= 2;
    else
        close = (close / 2) + 1;

    return open + close;

}