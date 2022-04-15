#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		set<int> s;
		for (int i = 0; i < nums.size(); i++)
		{
			if (s.find(nums[i]) != s.end())
				return nums[i];
			s.insert(nums[i]);
		}
		return 0;
	}
};

class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int tortoise = nums[0];
		int hare = nums[0];
		do {
			tortoise = nums[tortoise];
			hare = nums[nums[hare]];
		} while (tortoise != hare);

		// Find the "entrance" to the cycle.
		tortoise = nums[0];
		while (tortoise != hare) {
			tortoise = nums[tortoise];
			hare = nums[hare];
		}

		return hare;
	}
};

class Solution {
public:
	//O(nlogn)
	vector<int> findDuplicates1(vector<int>& nums) {
		if (nums.size() <= 1)    return {};
		sort(nums.begin(), nums.end());
		vector<int> result;
		for (int i = 0; i < nums.size() - 1; i++) {
			if (nums[i] == nums[i + 1]) {
				result.push_back(nums[i]);
			}
		}
		return result;
	}
	//O(n) with extra space O(n)
	vector<int> findDuplicates2(vector<int>& nums) {
		unordered_map<int, int> umap;
		vector<int> result;
		for (int& i : nums) {
			umap[i]++;
		}
		for (auto& [key, value] : umap) {
			if (value > 1) {
				result.push_back(key);
			}
		}
		return result;
	}
	//O(n) with O(1) space
	vector<int> findDuplicates3(vector<int>& nums) {
		vector<int> result;
		for (int i = 0; i < nums.size(); i++) {
			int num = abs(nums[i]) ;
			if (nums[num - 1] < 0) {
				result.push_back(num);
			}
			nums[num - 1] *= -1;
		}
		return result;
	}
};

vector<int> duplicates(int a[], int n) {
	// code here
	vector <int> r;
	for (int i = 0; i < n; i++)
	{
		a[a[i] % n] += n;
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] / n > 1)
			r.push_back(i);
	}
	if (r.size() == 0)
		r.push_back(-1);
	return r;
}
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	return 0;
}