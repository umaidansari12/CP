class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> a, b, c, d;
        for (int i = 0; i < nums1.size(); i++) {
            a[nums1[i]]++;
        }
        for (int i = 0; i < nums2.size(); i++) {
            b[nums2[i]]++;
        }
        vector<int> answer1, answer2;
        for (int i = 0; i < nums1.size(); i++) {
            if (b[nums1[i]] == 0 and c[nums1[i]] == 0) {
                answer1.push_back(nums1[i]);
                c[nums1[i]]++;
            }
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (a[nums2[i]] == 0 and d[nums2[i]] == 0) {
                answer2.push_back(nums2[i]);
                d[nums2[i]]++;
            }
        }
        return {answer1, answer2};
    }
};

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());

        vector<int> distinct_nums1, distinct_nums2;
        for (int num : set1) {
            if (set2.count(num) == 0) {
                distinct_nums1.push_back(num);
            }
        }

        for (int num : set2) {
            if (set1.count(num) == 0) {
                distinct_nums2.push_back(num);
            }
        }

        return {distinct_nums1, distinct_nums2};
    }
};