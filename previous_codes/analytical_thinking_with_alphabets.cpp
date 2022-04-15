#include <bits/stdc++.h>

using namespace std;




/*
 * Complete the 'findShortestSubstring' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int findShortestSubstring(string s) {
    int n = s.size(), start = -1, end = -1;//ans = INT_MAX;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int freq[26] = {0};
            //cout << s.substr(i, j - i + 1) << endl;
            string t = s.substr(0, i) + s.substr(j, n - j + 1);
            string x = s.substr(i, j - i + 1);
            //cout << t << endl;
            int k = 0, len = 0;
            for (k = i; k < t.size(); k++)
                freq[t[k] - 'a']++;
            for (k = i; k < s.size(); k++)
            {
                if (freq[t[k] - 'a'] > 1)
                    len++;
                freq[t[k] - 'a']++;
            }
            /* for (k = 0; k < 26; k++)
                 if (freq[k] > 1)
                     break;*/
            //cout << j - i + 1 << endl;
            //int m = t.size();
            cout << len << endl;
            ans.push_back(len);
            /*if (k == 26)
                ans.push_back(j - i + 1);*/
        }
    }
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s;
        getline(cin, s);

        int result = findShortestSubstring(s);
        cout << result << endl;
    }




    return 0;
}