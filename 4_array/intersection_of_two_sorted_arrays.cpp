#include <bits/stdc++.h>
vector<int> findArrayIntersection(vector<int> &nums1, int n, vector<int> &nums2, int m)
{
    // Write your code here.
    int first = 0, second = 0;
    vector<int> answer;
    while (first < n and second < m) {
        if (nums1[first] < nums2[second]) {
            first++;
        }
        else if (nums1[first] > nums2[second]) {
            second++;
        }
        else if (nums1[first] == nums2[second]) {
            answer.push_back(nums1[first]);
            first++;
            second++;
        }
    }
    return answer;
}


vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(), m = nums2.size();
    int first = 0, second = 0;
    vector<int> answer;
    while (first < n and second < m) {
        if (nums1[first] < nums2[second]) {
            first++;
        }
        else if (nums1[first] > nums2[second]) {
            second++;
        }
        else if (nums1[first] == nums2[second]) {
            if (answer.size() == 0 or answer.back() != nums1[first])
                answer.push_back(nums1[first]);
            first++;
            second++;
        }
    }
    return answer;
}