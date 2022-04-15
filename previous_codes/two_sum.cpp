#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int n = nums.size();
		vector<int> r;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (nums[i] + nums[j] == target)
				{
					r.push_back(i);
					r.push_back(j);
					break;
				}
			}
		}
		return r;

	}
};

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int n = nums.size();
		vector<int> r;
		unordered_map<int, int> m;
		for (int i = 0; i < n; i++)
		{
			if (m.find(target - nums[i]) != m.end())
			{
				r.push_back(m[target - nums[i]]);
				r.push_back(i);
				break;
			}
			m[nums[i]] = i;
		}

		return r;

	}
};

class Solution {
public:
	// Function to check if array has 2 elements
	// whose sum is equal to the given value
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
		// code here
		sort(arr, arr + n);
		int low = 0, high = n - 1;
		while (low < high)
		{
			if ((arr[low] + arr[high]) == x)
				return true;
			(arr[low] + arr[high]) < x ? low++ : high--;
		}
		return false;
	}
};

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	return 0;
}