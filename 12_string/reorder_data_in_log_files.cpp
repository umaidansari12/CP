class Solution {
public:
    pair<string, string> seperate(string a) {
        string identifier = "";
        int i = 0, n = a.size();
        while (i < n and a[i] != ' ') {
            identifier += a[i];
            i++;
        }
        i++;
        string logs = a.substr(i);

        return {identifier, logs};
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<pair<string, string>> let, dig;
        vector<string> ans;
        for (auto log : logs) {
            pair<string, string> s = seperate(log);
            if (s.second[0] >= 'a' and s.second[0] <= 'z')
                let.push_back({s.second, s.first});
            else
                dig.push_back({s.second, s.first});
        }
        sort(let.begin(), let.end());
        for (auto letter : let) {
            ans.push_back(letter.second + " " + letter.first);
        }
        for (auto digit : dig) {
            ans.push_back(digit.second + " " + digit.first);
        }

        return ans;
    }
};