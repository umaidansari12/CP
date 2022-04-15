class Solution {
public:
    void solve(int idx, int n, string s, set<string>&res, string r)
    {
        if (idx == n)
        {
            res.insert(r);
            return;
        }
        char upper = toupper(s[idx]);
        char lower = tolower(s[idx]);
        solve(idx + 1, n, s, res, r + upper);
        solve(idx + 1, n, s, res, r + lower);
    }
    vector<string> letterCasePermutation(string s) {
        set<string> res;
        string r = "";
        vector<string> result;
        solve(0, s.size(), s, res, r);
        for (auto i : res)
            result.push_back(i);

        return result;

    }
};