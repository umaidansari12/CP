class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> FS(256, 0), FP(256, 0);
        int cnt = 0, start = 0, start_idx = -1, window_size = 0, min_window_len = INT_MAX;
        for (int i = 0; i < t.length(); i++)
            FP[t[i]]++;
        for (int i = 0; i < s.length(); i++)
        {
            FS[s[i]]++;
            if (FP[s[i]] != 0 and FS[s[i]] <= FP[s[i]])
                cnt++;
            if (cnt == t.length())
            {
                while (FS[s[start]] == 0 or FS[s[start]] > FP[s[start]])
                {
                    FS[s[start++]]--;
                }
                window_size = i - start + 1;
                if (min_window_len > window_size)
                {
                    min_window_len = i - start + 1;
                    start_idx = start;
                }
            }
        }
        if (start_idx == -1)
            return "";
        return s.substr(start_idx, min_window_len);

    }
};