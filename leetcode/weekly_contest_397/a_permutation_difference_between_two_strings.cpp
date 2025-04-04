class Solution {
public:
    int findPermutationDifference(string s, string t) {
        vector<int> t_(26, -1);
        int _size = t.size();
        for (int i = 0; i < _size; i++)
            t_[t[i] - 'a'] = i;
        int answer = 0;
        for (int i = 0; i < _size; i++) {
            answer += abs(i - t_[s[i] - 'a']);
        }
        return answer;
    }
};