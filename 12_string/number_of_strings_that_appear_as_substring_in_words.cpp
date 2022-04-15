class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0;
        for (auto pat : patterns)
        {
            if (word.find(pat) != std::string::npos)
                cnt++;
        }
        return cnt;
    }
};