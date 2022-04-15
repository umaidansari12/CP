class Solution {
public:
    string frequencySort(string s) {
        map<char, int> m;
        for (auto i : s)
            m[i]++;
        s = "";
        vector<pair<char, int>> r;
        for (auto i : m)
        {
            r.push_back({i.first, i.second});
        }
        sort(r.begin(), r.end(), [](pair<char, int> a, pair<char, int> b) {
            return a.second > b.second;
        });
        for (auto i : r)
        {
            s += string(i.second, i.first);
        }
        return s;


    }
};