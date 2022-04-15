class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int count = 0;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                for (int k = 0; k < nums3.size(); k++) {
                    for (int l = 0; l < nums4.size(); l++) {
                        if ((nums1[i] + nums2[j] + nums3[k] + nums4[l]) == 0)
                            count++;
                    }
                }
            }
        }
        return count;

    }
};

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int count = 0;
        unordered_map<int, int> freq;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                freq[nums1[i] + nums2[j]]++;
            }
        }

        for (int k = 0; k < nums3.size(); k++) {
            for (int l = 0; l < nums4.size(); l++) {
                count += freq[-nums3[k] - nums4[l]];
            }
        }

        return count;

    }
};