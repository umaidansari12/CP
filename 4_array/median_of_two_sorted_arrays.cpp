//Brute
// T.C -> O(N+M)+O((N+M)log(N+M));
//S.C -> O(N+M)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        for (auto num : nums1)
            merged.push_back(num);
        for (auto num : nums2)
            merged.push_back(num);
        int size = merged.size();
        sort(merged.begin(), merged.end());
        double ans = 0.0;
        if (size % 2 == 0) {
            size /= 2;
            return ans = ((double)(merged[size]) + (double)(merged[size - 1])) / 2.0;
        }
        return merged[size / 2];
    }
};

//T.C -> O(N+M)
//S.C -> O(N+M)
class Solution {
public:
    void merge(vector<int> &nums1, vector<int> &nums2, vector<int> &merged) {
        int i = 0, j = 0, n = nums1.size(), m = nums2.size(), k = 0;
        while (i < n and j < m) {
            if (nums1[i] <= nums2[j]) {
                merged[k++] = nums1[i++];
            }
            else {
                merged[k++] = nums2[j++];
            }
        }
        while (i < n) {
            merged[k++] = nums1[i++];
        }
        while (j < m) {
            merged[k++] = nums2[j++];
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int> merged(n + m);
        merge(nums1, nums2, merged);
        int size = (n + m);
        if (size % 2 == 0) {
            return ((double)(merged[size / 2]) + (double)(merged[(size / 2) - 1])) / 2.0;
        }
        return merged[size / 2];

    }
};

//T.C -> O(N+M)
//S.C -> O(1)
class Solution {
public:
    double merge(vector<int> &nums1, vector<int> &nums2) {
        int i = 0, j = 0, n = nums1.size(), m = nums2.size(), k = 0, size = (n + m);
        double ans1 = 0.0, ans2 = 0.0;
        int f = size % 2;
        while (i < n and j < m) {
            if (nums1[i] <= nums2[j]) {
                if (k == (size / 2) - 1)
                {
                    ans1 = nums1[i];
                }
                if (k == (size / 2)) {
                    ans2 = nums1[i];
                }
                k++;
                i++;
            }
            else {
                if (k == (size / 2) - 1)
                {
                    ans1 = nums2[j];
                }
                if (k == (size / 2)) {
                    ans2 = nums2[j];
                }
                k++;
                j++;
            }
        }
        while (i < n) {
            if (k == (size / 2) - 1)
            {
                ans1 = nums1[i];
            }
            if (k == (size / 2)) {
                ans2 = nums1[i];
            }
            k++;
            i++;
        }
        while (j < m) {
            if (k == (size / 2) - 1)
            {
                ans1 = nums2[j];
            }
            if (k == (size / 2)) {
                ans2 = nums2[j];
            }
            k++;
            j++;
        }
        if (f)
            return ans2;
        return (ans1 + ans2) / 2.0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int size = (n + m);
        return merge(nums1, nums2);
    }
};