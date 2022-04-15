#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution {
public:
    vector<int> constructLowerArray(int *arr, int n) {
        // code here
        vector<int> r;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] < arr[i])
                    count++;
            }
            r.push_back(count);
        }
        return r;
    }
};

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
                temp[k++] = v[j++];
            }
            else
            {
                count[v[i].second] += (right - j + 1);
                temp[k++] = v[i++];
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

class Solution {
public:
    void merge_count(vector<vector<int>>::iterator l, vector<vector<int>>::iterator r, vector<int>&count)
    {
        if (r - l <= 1)return;
        vector<vector<int>>::iterator m = l + (r - l) / 2;
        merge_count(l, m, count);
        merge_count(m, r, count);
        vector<vector<int>>::iterator i = l;
        vector<vector<int>>::iterator j = m;
        for (i = l; i < m; i++)
        {
            while (j < r && (((*i)[0] > (*j)[0])))
                j++;
            count[(*i)[1]] += j - m;
        }
        inplace_merge(l, m, r);

    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> count(nums.size(), 0);
        vector<vector<int>> temp;
        for (int i = 0; i < nums.size(); i++)
        {
            temp.push_back(vector<int>({nums[i], i}));
        }
        merge_count(temp.begin(), temp.end(), count);
        return count;

    }
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> r;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] > nums[j])
                    count++;
            }
            r.push_back(count);
        }
        return r;

    }
};
// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.constructLowerArray(arr, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends