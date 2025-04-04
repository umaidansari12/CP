class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size(), sum = 0, ans = 0;
        unordered_map<int, int> hash_map;
        for (int right = 0; right < n; right++) {
            sum += nums[right];
            if (sum == goal)
                ans++;
            if (hash_map.find(sum - goal) != hash_map.end())
                ans += hash_map[sum - goal];
            hash_map[sum]++;
        }
        return ans;
    }
};

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size(), sum = 0, ans = 0;
        unordered_map<int, int> hash_map;
        for (int right = 0; right < n; right++) {
            sum += nums[right];
            if (sum == goal)
                ans++;
            if (hash_map.find(sum - goal) != hash_map.end())
                ans += hash_map[sum - goal];
            hash_map[sum]++;
        }
        return ans;
    }
};