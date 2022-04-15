

// CPP program to generate power set
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


//Function to return the lexicographically sorted power-set of the string.
void generate(string s, string r, int i, int n, vector<string>&re)
{
    if (i == n)
    {
        re.push_back(r);
        return;
    }
    generate(s, r + s[i], i + 1, n, re);
    generate(s, r, i + 1, n, re);
}


vector <string> powerSet(string s)
{
    //Your code here
    vector<string> r;
    // r.push_back("");
    generate(s, "", 0, s.size(), r);
    sort(r.begin(), r.end());
    return r;
}


// { Driver Code Starts.


// Driver code
int main()
{
    int T;
    cin >> T; //testcases
    while (T--)
    {
        string s;
        cin >> s; //input string

        //calling powerSet() function
        vector<string> ans = powerSet(s);

        //sorting the result of the powerSet() function
        sort(ans.begin(), ans.end());

        //printing the result
        for (auto x : ans)
            cout << x << " ";
        cout << endl;


    }

    return 0;
}   // } Driver Code Ends