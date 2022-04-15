#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    static bool comp(pair<int, int> a, pair<int, int> b)
    {
        if (a.second == b.second)
            return a.first > b.first;
        return a.second > b.second;
    }
    vector<int> topK(vector<int>& nums, int k) {
        // Code here
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
            m[nums[i]]++;
        vector<pair<int, int>> r;
        for (auto i : m)
            r.push_back({i.first, i.second});
        sort(r.begin(), r.end(), comp);
        vector<int> output;
        for (int i = 0; i < k; i++)
            output.push_back(r[i].first);
        return output;
    }
};

class Solution1 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (auto i : nums)
            m[i]++;
        vector<pair<int, int>> r;
        for (auto i : m)
            r.push_back({i.first, i.second});
        sort(r.begin(), r.end(), [](pair<int, int> a, pair<int, int> b)
        {
            return a.second > b.second;
        });
        vector<int> output;
        for (int i = 0; i < k; i++)
            output.push_back(r[i].first);
        return output;
    }
};


// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends