class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> engineer;
        for (int i = 0; i < n; i++) {
            engineer.push_back({efficiency[i], speed[i]});
        }
        sort(engineer.rbegin(), engineer.rend());
        priority_queue<int, vector<int>, greater<int>> min_heap;
        long long total_speed = 0, answer = 0;
        const int MOD = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            int curr_efficiency = engineer[i].first;
            int curr_speed = engineer[i].second;

            if (min_heap.size() == k) {
                total_speed -= min_heap.top();
                min_heap.pop();
            }
            min_heap.push(curr_speed);

            total_speed += curr_speed;
            answer = max(answer, total_speed * curr_efficiency);
        }
        return answer % MOD;
    }
};