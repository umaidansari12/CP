#include<bits/stdc++.h>
using namespace std;

int min_bars_helper(string s, int idx, unordered_set<string>&se)
{
    if (s[idx] == '\0')
        return 0;
    int ans = INT_MAX;
    string current_string = "";
    for (int j = idx; s[j] != '\0'; j++)
    {
        current_string += s[j];
        if (se.find(current_string) != se.end())
        {
            int remaining_ans = min_bars_helper(s, j + 1, se);
            if (remaining_ans != -1)
                ans = min(ans, 1 + remaining_ans);
        }
    }
    if (ans == INT_MAX)
        return -1;
    return ans;
}


int min_bars(string s, string words[], int n) {
    //Complete this function return the min bars
    // n is number of words
    unordered_set<string> se;
    for (int i = 0; i < n; i++)
    {
        se.insert(words[i]);
    }
    int output = min_bars_helper(s, 0, se);
    return output - 1;

}