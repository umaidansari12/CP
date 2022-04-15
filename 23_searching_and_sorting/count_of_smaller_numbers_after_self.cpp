class Solution {
public:
    void merge(int left, int mid, int right, vector<int>&count, vector<pair<int, int>>&v)
    {
        vector<pair<int, int>> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;
        while (i <= mid && j <= right)
        {
            if (v[i].first <= v[j].first)
            {
                temp[k++] = v[i++];
            }
            else
            {
                count[v[j].second] += (mid - i + 1);
                temp[k++] = v[j++];
            }
        }
        while (i <= mid)
            temp[k++] = v[i++];
        while (j <= right)
            temp[k++] = v[j++];
        for (i = left; i <= right; i++)
            v[i] = temp[i - left];
    }
    void mergeSort(int left, int right, vector<int>&count, vector<pair<int, int>>&v)
    {
        if (left >= right)
            return;
        int mid = left + (right - left) / 2;
        mergeSort(left, mid, count, v);
        mergeSort(mid + 1, right, count, v);
        merge(left, mid, right, count, v);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++)
        {
            v[i] = make_pair(nums[i], i);
        }
        vector<int> count(n, 0);
        mergeSort(0, n - 1, count, v);
        return count;
    }
};