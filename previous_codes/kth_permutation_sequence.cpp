#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
	void solve(vector<int>& nums, int l, int r, vector<vector<int>> &res)
	{
		if (l == r)
			res.push_back(nums);
		for (int i = l; i <= r; i++)
		{
			swap(nums[l], nums[i]);
			solve(nums, l + 1, r, res);
			swap(nums[l], nums[i]);
		}
	}
	string getPermutation(int n, int k) {
		vector<vector<int>> res;
		vector<int> nums(n, 0);
		for (int i = 1; i <= n; i++)
			nums[i - 1] = i;
		solve(nums, 0, nums.size() - 1, res);
		sort(res.begin(), res.end());
		string s;
		for (int i = 0; i < n; i++)
		{
			s += to_string(res[k - 1][i]);
		}
		return s;
	}
};

void kth_permutation_sequence(vector<int>&a, int l, int r, vector<vector<int>>&res)
{
	if (l == r)
	{
		res.push_back(a);
		return;
	}
	for (int i = l; i <= r; i++)
	{
		swap(a[l], a[i]);
		kth_permutation_sequence(a, l + 1, r, res);
		swap(a[l], a[i]);
	}
}

class Solution {
public:
	string getPermutation(int n, int k) {
		int fact = 1;
		vector<int> numbers;
		for (int i = 1; i < n; i++)
		{
			fact *= i;
			numbers.push_back(i);
		}
		numbers.push_back(n);
		k = k - 1;
		string ans;
		while (true)
		{
			ans += (to_string(numbers[k / fact]));
			numbers.erase(numbers.begin() + (k / fact));
			if (numbers.size() == 0)
				break;
			k %= fact;
			fact /= numbers.size();
		}
		return ans;


	}
};

void solve(string&ans, vector<int>&fact, vector<int>&digits, int n, int k)
{
	if (n == 1)
	{
		ans += char(digits.back() + '0');
		return;
	}
	int index = k / fact[n - 1];
	if (k % fact[n - 1] == 0)
		index--;
	ans += (digits[index] + '0');
	digits.erase(digits.begin() + index);
	k -= fact[n - 1] * index;
	solve(ans, fact, digits, n - 1, k);
}

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		vector<int> digits(n);
		vector<int> fact;
		int f = 1;
		fact.push_back(1);
		for (int i = 1; i < n; i++)
		{
			f *= i;
			fact.push_back(f);
			digits[i - 1] = i;
		}
		digits[n - 1] = n;
		/*for (int i : fact)
		{
			cout << i << " ";
		}*/


		string ans;
		solve(ans, fact, digits, n, k);
		cout << ans << endl;
		/*vector<vector<int>> res;
		kth_permutation_sequence(a, 0, n - 1, res);
		sort(res.begin(), res.end());
		vector<int> r = res[k - 1];
		for (int i : r)
			cout << i;*/
	}


	return 0;
}