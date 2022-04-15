#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*bool arrayContains(vector<int>&nums, int num)
{
	for (int i = 0; i < nums.size(); i++)
		if (nums[i] == num)
			return true;
	return false;
}

int longestConsecutive(vector<int>& nums) {
	int n = nums.size(), ans = 0;
	for (int i = 0; i < n; i++)
	{
		int curr = nums[i];
		int count = 1;
		while (arrayContains(nums, curr + 1))
		{
			curr++;
			count++;
		}
		ans = max(ans, count);
	}
	return ans;
}

int longestConsecutive(vector<int>& nums) {
	int n = nums.size(), longest_count = 0;
	unordered_map<int, int> m;
	for (int i = 0; i < n; i++)
	{
		m[nums[i]]++;
	}
	for (int i = 0; i < n; i++)
	{
		if (m.find(nums[i] - 1) == m.end())
		{
			int curr = nums[i], count = 1;
			while (m.find(curr + 1) != m.end())
			{
				curr++;
				count++;
			}
			longest_count = max(count, longest_count);
		}
	}
	return longest_count;
}

*/

int longestConsecutiveSequence(vector<int> &a, int n)
{
	unordered_map<int, int> m;
	int maxCount = 0;
	for (int i = 0; i < n; i++)
	{
		m[a[i]]++;
	}
	for (int i = 0; i < n; i++)
	{
		if (m.find(a[i] - 1) == m.end())//considering starting point and from there counting longest subsequence
		{
			int curr = a[i], count = 1;
			while (m.find(curr + 1) != m.end())
			{
				curr++;
				count++;
			}
			maxCount = max(count, maxCount);
		}
	}
	return maxCount;
}


int longestConsecutive_Sequence(vector<int>& arr , int n)
{
	if (arr.size() == 0)
		return 0;
	int i = 1, ans = 1, count = 1, n = arr.size();
	sort(arr.begin(), arr.end());
	for (i = 1; i < n; i++)
	{
		if (arr[i] != arr[i - 1])
		{
			if (arr[i] == arr[i - 1] + 1)
				count++;
			else
			{
				count = 1;
			}
			ans = max(count, ans);
		}

	}

	return ans;

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
		cout << longestConsecutive_Sequence(a, n) << endl;
	}


	return 0;
}