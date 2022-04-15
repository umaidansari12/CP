#include<bits/stdc++.h>

// } Driver Code Ends


class Solution
{
public:
    string reverse(string str)
    {
        //code here.
        int i = 0, j = str.size() - 1;
        while (i < j)
        {
            if (!isalpha(str[i]))
                i++;
            else if (!isalpha(str[j]))
                j--;
            else
                swap(str[i++], str[j--]);
        }
        return str;
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
        cout << ob.reverse(s) << endl;
    }
    return 0;
}

// } Driver Code Ends