class Solution {
public:
    static bool comp(pair<string, int> a, pair<string, int> b)
    {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second > b.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        vector<pair<string, int>> r;
        for (auto i : words)
            m[i]++;
        for (auto i : m)
        {
            r.push_back({i.first, i.second});
        }
        sort(r.begin(), r.end(), comp);
        vector<string> output;
        for (int i = 0; i < k; i++)
            output.push_back(r[i].first);
        return output;

    }
};