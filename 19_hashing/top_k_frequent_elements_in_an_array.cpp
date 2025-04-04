vector<int> topK(vector<int>& nums, int k) {
    // Code here
    unordered_map<int, int> cnt;
    for (int i = 0; i < nums.size(); i++) {
        cnt[nums[i]]++;
    }
    vector<pair<int, int>> res;
    for (auto cnter : cnt) {
        res.push_back({cnter.first, cnter.second});
    }
    sort(res.begin(), res.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second)
            return a.first > b.first;
        return a.second > b.second;
    });
    vector<int> answer;
    for (int i = 0; i < k; i++)
        answer.push_back(res[i].first);
    return answer;
}