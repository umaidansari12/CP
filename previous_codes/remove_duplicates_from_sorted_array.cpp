#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
	int removeDuplicatesBrute(vector<int>& nums) {
		vector<int> a;
		int n = nums.size();
		int j = 0;
		for (int i = 0; i < n; i++)
		{
			if (a.size() == 0)
			{
				a.push_back(nums[i]);
				j++;
			}
			else if (a[j - 1] != nums[i])
			{
				a.push_back(nums[i]);
				j++;
			}
		}
		j = 0;
		for (auto i : a)
			nums[j++] = i;
		return j;

	}
	int removeDuplicatesBrute1(vector<int>& nums) {
		set<int> s;
		int n = nums.size();
		for (int i = 0; i < n; i++)
			s.insert(nums[i]);
		int i = 0;
		for (auto j : s)
			nums[i++] = j;
		return i;

	}
	int removeDuplicates(vector<int>& nums) {
		int n = nums.size();
		if (n == 0)
			return 0;
		int i = 0;
		for (int j = 1; j < n; j++)
		{
			if (nums[i] != nums[j])
				i++;
			nums[i] = nums[j];
		}
		return i + 1;

	}
	int removeDuplicates(vector<int>& nums) {
		int n = nums.size();
		if (n == 0)
			return 0;
		int i = 0, j = 1;
		while (j < n)
		{
			while (j < n && nums[i] == nums[j])
				j++;
			nums[++i] = nums[j];
			j++;
		}
		return i + 1;

	}
};



vector<int> removeDuplicatesFromSortedArray(vector<int> a, int n)
{
	vector<int> res;
	int size = 0;
	for (int i = 0; i < n; i++)
	{
		if (size == 0)
		{
			res.push_back(a[i]);
			size++;
		}
		else if (res[size - 1] != a[i])
		{
			res.push_back(a[i]);
			size++;
		}

	}
	return res;
}

int remove_duplicate(int A[], int N)
{
//Your code here
	int j = 0;
	for (int i = 0; i < N - 1; i++)
	{
		if (A[i] != A[i + 1])
			A[j++] = A[i];
	}
	A[j++] = A[N - 1];
	return j;
}

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int n = nums.size();
		if (n == 0 || n == 1)
			return n;
		int j = 0;
		for (int i = 0; i < n - 1; i++)
		{
			if (nums[i] != nums[i + 1])
				nums[j++] = nums[i];
		}
		nums[j++] = nums[n - 1];
		return j;

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
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		vector<int> res = removeDuplicatesFromSortedArray(a, n);
		for (int i : res)
		{
			cout << i << " ";
		}
		cout << endl << res.size() << endl;
	}


	return 0;
}