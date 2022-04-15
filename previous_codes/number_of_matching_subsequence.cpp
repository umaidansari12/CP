class Solution {
public:
    bool isSubsequence(string a, string b)
    {
        int n = a.size(), m = b.size(), j = 0, i = 0;
        while (i < n and j < m)
        {
            if (a[i] == b[j])
            {
                i++;
                j++;
            }
            else
                i++;
        }
        if (j == m)
            return true;
        return false;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        unordered_map<string, int> m;
        for (int i = 0; i < words.size(); i++)
        {
            m[words[i]]++;
        }
        for (auto i : m)
        {
            if (isSubsequence(s, i.first))
                count += i.second;
        }
        return count;

    }
};