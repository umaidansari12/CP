#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[low] <= nums[mid])
            {
                if (target >= nums[low] and target <= nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else
            {
                if (target >= nums[mid] and target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return -1;
    }
};


int find_key(vector <int> a, int n, int key)
{
    int s = 0, e = n - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (a[mid] == key)
        {
            return mid;
        }
        else if (a[s] <= a[mid])
        {
            if (key >= a[s] && key <= a[mid])
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        else if (a[mid] >= a[e])
        {
            if (key <= a[e] and key <= a[mid])
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
    }
    return -1;
}

int main() {
    //code
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int key;
        cin >> key;
        cout << find_key(a, n, key) << endl;
    }
    return 0;
}