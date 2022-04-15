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


//T.C -> O(min(logN,logM)) -> since we are performing partition on smaller array
//S.C -> O(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1); // we need to perform cuts on smaller sized array so that we dont run overflow edge  case in which we take some elements from larger set but we dont have sufficient elements in the smaller set to accomodate (n+m+1)/2-cut1 elements this is the  edge case and we have covered this by taking set1 as smaller one;
        int n = nums1.size(), m = nums2.size(), low = 0, high = n, size = (n + m);
        while (low <= high) {
            int cut1 = (low + high) / 2; //we are taking n+m+1 as if n+m is even then incrementing 1 will not affect the cut1 value and if n+m is odd then cut1 value will be 1 greater in set
            int cut2 = ((n + m + 1) / 2) - cut1;
            int left1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
            int left2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];
            int right1 = cut1 == n ? INT_MAX : nums1[cut1];
            int right2 = cut2 == m ? INT_MAX : nums2[cut2];

            if (left1 <= right2 and left2 <= right1) {
                if (size % 2 == 0) {
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                }
                else
                    return max(left1, left2);
            }
            else if (left1 > right2) {
                high = cut1 - 1;
            }
            else {
                low = cut1 + 1;
            }
        }
        return 0.0;
    }
};

double Solution::findMedianSortedArrays(const vector<int> &array1, const vector<int> &array2) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if (array1.size() > array2.size())
        return findMedianSortedArrays(array2, array1);
    int n = array1.size(), m = array2.size(), low = 0, high = n;
    while (low <= high) {
        int cut1 = (low + high) / 2;
        int cut2 = ((n + m + 1) / 2) - cut1;

        int left1 = cut1 == 0 ? INT_MIN : array1[cut1 - 1];
        int left2 = cut2 == 0 ? INT_MIN : array2[cut2 - 1];

        int right1 = cut1 == n ? INT_MAX : array1[cut1];
        int right2 = cut2 == m ? INT_MAX : array2[cut2];

        if (left1 <= right2 and left2 <= right1) {
            if ((n + m) % 2 == 0) {
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            }
            else {
                return double(max(left1, left2));
            }
        }
        else if (left1 > right2) {
            high = cut1 - 1;
        }
        else {
            low = cut1 + 1;
        }

    }
    return 0.0;
}
