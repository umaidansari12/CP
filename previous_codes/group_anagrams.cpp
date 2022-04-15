//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
vector<vector<string> > Anagrams(vector<string>& string_list) ;

// } Driver Code Ends
//User function Template for C++

vector<int> getHashValue(string s)
{
    vector<int> freq(26, 0);
    for (int i = 0; i < s.size(); i++)
    {
        freq[s[i] - 'a']++;
    }
    return freq;
}
vector<vector<string> > Anagrams(vector<string>& string_list)
{
    // Your Code Here
    vector<vector<string>> output;
    map<vector<int>, vector<string>> m;
    for (int i = 0; i < string_list.size(); i++)
    {
        vector<int> h = getHashValue(string_list[i]);
        //sort(h.begin(), h.end());
        m[h].push_back(string_list[i]);
    }
    for (auto i : m)
    {
        output.push_back(i.second);
    }
    return output;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin >> string_list[i];
        vector<vector<string> > result = Anagrams(string_list);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for (int j = 0; j < result[i].size(); j++)
            {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
// } Driver Code Ends