#include <bits/stdc++.h>

using namespace std;
using ll = long long;


class Solution {
public:
	int maxProduct(vector<int>& nums) {
		if (nums.size() == 1)
			return nums[0];

		int max_ending = 1, min_ending = 1, ans = 0, temp = 1;
		for (int i = 0; i < nums.size(); i++)
		{
			temp = max_ending;
			max_ending = max(nums[i], max(nums[i] * max_ending, nums[i] * min_ending));
			min_ending = min(nums[i], min(nums[i] * temp, nums[i] * min_ending));
			ans = max(ans, max_ending);
		}
		return ans;

	}
};

int fun()
{
	int max_current = 1, max_global = nums[0];
	for (int i = 0; i < nums.size(); i++)
	{
		max_current *= nums[i];
		max_global = max(max_global, max_current);
		max_current = max(max_current, 1);
	}
	return max_global;
}
class Solution {
public:

	// Function to find maximum product subarray
	long long maxProduct(int *arr, int n) {
		// code here
		long long int ans = arr[0], max_ending = arr[0], min_ending = arr[0];
		for (int i = 1; i < n; i++)
		{
			long long int temp = max_ending;
			max_ending = max((long long)arr[i], max(arr[i] * max_ending, arr[i] * min_ending));
			min_ending = min((long long)arr[i], min(arr[i] * temp, arr[i] * min_ending));
			ans = max(ans, max_ending);
		}
		return ans;
	}
};

//User function template for C++
class Solution {
public:

	// Function to find maximum product subarray

	long long maxProduct(int *arr, int n) {
		// code here

		long long int ma = arr[0];
		long long int mi = arr[0];
		long long int ans = arr[0];
		for (int i = 1; i < n; i++)
		{
			if (arr[i] < 0)
				swap(mi, ma);
			ma = max((long long) arr[i], ma * arr[i]);
			mi = min((long long)arr[i], mi * arr[i]);
			ans = max(ans, ma);
		}
		return ans;
	}
};
int max_3(int a, int b, int c)
{
	int res = max(a, b);
	res = max(res, c);
	return res;
}
int min_3(int a, int b, int c)
{
	int res = min(a, b);
	res = min(res, c);
	return res;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int curr_max = a[0], curr_min = a[0], prev_max = a[0], prev_min = a[0], ans = a[0];
		for (int i = 1; i < n; i++)
		{
			curr_max = max_3(prev_max * a[i], prev_min * a[i], a[i]);
			curr_min = min_3(prev_max * a[i], prev_min * a[i], a[i]);
			ans = max(ans, curr_max);
			prev_max = curr_max;
			prev_min = curr_min;
		}
		cout << ans << endl;

		/*
		res.push_back(m);
		res.push_back(pro);
		for (int k = 2; k < n; k++)
		{
			deque<int> q;
			int pro = 1, i = 0;
			for (i = 0; i < k; i++)
			{
				pro *= a[i];
				while (!q.empty())
					q.pop_back();
				q.push_back(i);
			}
			for (; i < n; i++)
			{
				res.push_back(pro);
				pro /= a[q.front()];
				while (!q.empty() && q.front() <= i - k)
					q.pop_front();
				while (!q.empty)
					q.pop_back();
				q.push_back(i);
			}

		}
		for (auto i : res)
			cout << i << " ";
		cout << endl;*/


	}


	return 0;
}