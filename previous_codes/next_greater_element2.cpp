#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
	vector<int> nextGreaterElements(vector<int>& nums) {
		int n = nums.size();
		vector<int> a, res;
		for (int i = 0; i < n; i++)
		{
			a.push_back(nums[i]);
		}
		for (int i = 0; i < n; i++)
		{
			a.push_back(nums[i]);
		}
		for (int i = 0; i < n; i++)
		{
			int r = -1;
			for (int j = i + 1; j < (2 * n); j++)
			{
				if (a[j] > a[i])
				{
					r = a[j];
					break;
				}
			}
			res.push_back(r);
		}
		return res;
	}
};

class Solution {
public:
	vector<int> nextGreaterElements(vector<int>& nums) {
		int n = nums.size();
		vector<int> res(n, 0);
		stack<int> s;
		for (int i = (2 * n) - 1; i >= 0; i--)
		{
			while (!s.empty() && nums[s.top()] <= nums[i % n])
				s.pop();
			if (s.empty())
				res[i % n] = -1;
			else
				res[i % n] = nums[s.top()];
			s.push(i % n);
		}
		return res;
	}
};

class Solution {
public:
	vector<int> nextGreaterElements(vector<int>& nums) {
		int n = nums.size();
		vector<int> res;
		for (int i = 0; i < n; i++)
		{
			int r = -1;
			for (int j = 1; j < n; j++)
			{
				if (nums[(i + j) % n] > nums[i])
				{
					r = nums[(i + j) % n];
					break;
				}
			}
			res.push_back(r);
		}
		return res;
	}
};

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	return 0;
}