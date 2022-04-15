#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution1
{
public:
	int findOnce(int arr[], int n)
	{
		//code here.
		for (int i = 0; i < n; i++)
		{
			if (arr[i] != arr[i + 1] && i % 2 == 0)
				return arr[i];
		}
		return 0;
	}
};

int search(vector<int>&a, int low, int high)
{
	if (low > high)
		return -1;
	if (low == high)
		return a[low];
	int mid = (low + high) / 2;
	if (mid % 2 == 0)
	{
		if (a[mid] == a[mid + 1])
			return search(a, mid + 2, high);
		else
			return search(a, low, mid);
	}
	else
	{
		if (a[mid] == a[mid - 1])
			return search(a, mid + 1, high);
		else
			return search(a, low, mid - 1);
	}
}

int findElementThatAppearsOnceInASortedArray(vector<int>&a, int low, int high)
{
	int mid = (low + high) / 2;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (low == high)
			return a[low];
		if (mid % 2 == 0)
		{
			if (a[mid] == a[mid + 1])
			{
				low = mid + 2;
			}
			else
			{
				high = mid;
			}
		}
		else
		{
			if (a[mid] == a[mid - 1])
			{
				low = mid + 1;
			}
			else
			{
				high = mid - 1;
			}
		}
	}
	return 0;
}
int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		//cout << findElementThatAppearsOnceInASortedArray(a, 0, n - 1) << endl;
		cout << search(a, 0, n - 1) << endl;
	}


	return 0;
}

class Solution {
public:
	int search(vector<int>&a, int low, int high)
	{
		if (low > high)
			return -1;
		if (low == high)
			return a[low];
		int mid = (low + high) / 2;
		if (mid % 2 == 0)
		{
			if (a[mid] == a[mid + 1])
				return search(a, mid + 2, high);
			else
				return search(a, low, mid);
		}
		else
		{
			if (a[mid] == a[mid - 1])
				return search(a, mid + 1, high);
			else
				return search(a, low, mid - 1);
		}
	}
	int singleNonDuplicate(vector<int>& nums) {
		return search(nums, 0, nums.size() - 1);
	}
};