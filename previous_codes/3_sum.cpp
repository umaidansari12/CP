#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<vector<int> > Solution::threeSum(vector<int> &A) {
	int n = A.size();
	vector<vector<int>> res;
	vector<int> ri(3);
	sort(A.begin(), A.end());
	for (int i = 0; i < n; i++)
	{
		int l = i + 1, r = n - 1;
		while (l < r)
		{
			long long int sum = 0LL + A[l] + A[r] + A[i];
			if (sum == 0)
			{
				ri[0] = A[i];
				ri[1] = A[l];
				ri[2] = A[r];
				res.push_back(ri);
				int left = A[l];
				while (l < n && A[l] == left)
					l++;
				int right = A[r];
				while (r > l && A[r] == right)
					r--;
			}
			else if (sum < 0)
				l++;
			else
				r--;
		}
		while (i < n && A[i] == A[i + 1])
			i++;

	}
	return res;
}



class Solution {
public:
	vector<vector<int>> threeSumBrute(vector<int>& nums) {
		int n = nums.size();
		vector<int> r(3);
		set<vector<int>> s;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				for (int k = j + 1; k < n; k++)
				{
					if (nums[i] + nums[j] + nums[k] == 0)
					{
						r[0] = nums[i];
						r[1] = nums[j];
						r[2] = nums[k];
						sort(r.begin(), r.end());
						s.insert(r);
					}
				}
			}
		}
		vector<vector<int>> res;
		for (auto i : s)
			res.push_back(i);
		return res;

	}
	vector<vector<int>> threeSumBetter(vector<int>& nums) {
		unordered_map<int, int> m;
		set<vector<int>> s;
		vector<int> r(3);
		vector<vector<int>> res;
		int n = nums.size();
		for (int i = 0; i < n; i++)
			m[nums[i]]++;
		for (int i = 0; i < n; i++)
		{
			m[nums[i]]--;
			for (int j = i + 1; j < n; j++)
			{
				int sum = -1 * (nums[i] + nums[j]);
				m[nums[j]]--;
				if (m.find(sum) != m.end() && m[sum] > 0)
				{
					r[0] = nums[i];
					r[1] = nums[j];
					r[2] = sum;
					sort(r.begin(), r.end());
					s.insert(r);
				}
				m[nums[j]]++;
			}
			m[nums[i]]++;
		}
		for (auto i : s)
			res.push_back(i);
		return res;

	}
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int n = nums.size();
		vector<int> r(3);
		vector<vector<int>> res;
		for (int i = 0; i < n; i++)
		{
			int l = i + 1, ri = n - 1;
			while (l < ri)
			{
				if (nums[i] + nums[l] + nums[ri] == 0)
				{
					r[0] = nums[i];
					r[1] = nums[l];
					r[2] = nums[ri];
					res.push_back(r);
					int left = nums[l];
					while (l < n && nums[l] == left)
						l++;
					int right = nums[ri];
					while (ri > l && nums[ri] == right)
						ri--;
					// l++;
					// ri--;
				}
				else if (nums[i] + nums[l] + nums[ri] < 0)
					l++;
				else
					ri--;

				while (i + 1 < n && nums[i] == nums[i + 1])
					i++;
			}
		}
		return res;

	}
	vector<vector<int>> threeSum(vector<int>& num) {
		vector<vector<int>> res;
		sort(num.begin(), num.end());

		// moves for a
		for (int i = 0; i < (int)(num.size()) - 2; i++) {

			if (i == 0 || (i > 0 && num[i] != num[i - 1])) {

				int lo = i + 1, hi = (int)(num.size()) - 1, sum = 0 - num[i];

				while (lo < hi) {
					if (num[lo] + num[hi] == sum) {

						vector<int> temp;
						temp.push_back(num[i]);
						temp.push_back(num[lo]);
						temp.push_back(num[hi]);
						res.push_back(temp);

						while (lo < hi && num[lo] == num[lo + 1]) lo++;
						while (lo < hi && num[hi] == num[hi - 1]) hi--;

						lo++; hi--;
					}
					else if (num[lo] + num[hi] < sum) lo++;
					else hi--;
				}
			}
		}
		return res;
	}
};

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n, x, f = 0;
		cin >> n >> x;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		for (int i = 0; i < n; i++)
		{
			int left = i + 1;
			int right = n - 1;
			while (left < right)
			{
				int sum = a[i] + a[left] + a[right];
				if (sum == x)
				{
					f = 1;
					break;
				}
				else if (sum < x)
					left++;
				else
					right--;
			}
		}
		cout << f << endl;

	}
	return 0;
}