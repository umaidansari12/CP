class Solution {
public:
    static bool compare(pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
    }
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int, int> count;
        // cout<<nums1.size();
        for (int i = 0; i < nums1.size(); i++) {
            // cout<<nums1[i][0]<<" "<<nums1[i][1]<<"\n";
            if (count.find(nums1[i][0]) == count.end()) {
                count[nums1[i][0]] = nums1[i][1];
            }
            else {
                count[nums1[i][0]] += nums1[i][1];
            }
        }
        for (auto value : count) {
            // cout<<value.first<<" "<<value.second<<"\n";
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (count.find(nums2[i][0]) == count.end()) {
                count[nums2[i][0]] = nums2[i][1];
            }
            else {
                count[nums2[i][0]] += nums2[i][1];

            }
        }
        // sort(count.begin(),count.end(),compare);
        vector<vector<int>> result;
        for (auto value : count) {
            // cout<<value.first<<" "<<value.second<<"\n";
            result.push_back({value.first, value.second});
        }
        return result;
    }
};