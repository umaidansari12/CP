#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
	int merge(vector<int>&a, int l, int m, int r)
	{
		int i = l, j = m + 1, count = 0;
		for (int i = l; i <= m; i++)
		{
			while (j <= r && a[i] > 2LL * a[j])
				j++;
			count += (j - (m + 1));
		}
		i = l, j = m + 1;
		vector<int> temp;
		while (i <= m && j <= r)
		{
			if (a[i] <= a[j])
				temp.push_back(a[i++]);
			else
				temp.push_back(a[j++]);
		}
		while (i <= m)
			temp.push_back(a[i++]);
		while (j <= r)
			temp.push_back(a[j++]);
		for (int i = l; i <= r; i++)
			a[i] = temp[i - l];
		return count;
	}
	int mergeSort(vector<int>&a, int l, int r)
	{
		int count = 0;
		if (l >= r)
			return 0;
		int m = (l + r) / 2;
		count += mergeSort(a, l, m);
		count += mergeSort(a, m + 1, r);
		count += merge(a, l, m, r);
		return count;
	}
	int reversePairs(vector<int>& nums) {
		return mergeSort(nums, 0, nums.size() - 1);
	}
};

class Solution {
public:
	int merge(vector<int> &nums, int left, int mid, int right)
	{
		int cnt = 0, j = mid + 1;
		for (int i = left; i <= mid; i++)
		{
			while (j <= right && nums[i] > 2LL * nums[j])
			{
				j++;
			}
			cnt += (j - (mid + 1));
		}
		vector<int> temp;
		int low = left, high = mid + 1;
		while (low <= mid && high <= right)
		{
			if (nums[low] <= nums[high])
			{
				temp.push_back(nums[low++]);
			}
			else
			{
				temp.push_back(nums[high++]);
			}
		}
		while (low <= mid)
		{
			temp.push_back(nums[low++]);
		}
		while (high <= right)
		{
			temp.push_back(nums[high++]);
		}
		for (int i = left; i <= right; i++)
		{
			nums[i] = temp[i - left];
		}
		return cnt;
	}
	int mergeSort(vector<int>&nums, int left, int right)
	{
		if (left >= right)
			return 0;
		int mid = (left + right) / 2;
		int inv = mergeSort(nums, left, mid);
		inv += mergeSort(nums, mid + 1, right);
		inv += merge(nums, left, mid, right);
		return inv;
	}
	int reversePairs(vector<int>& nums) {
		return mergeSort(nums, 0, nums.size() - 1);
	}
};

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);


	return 0;
}