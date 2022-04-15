#include <bits/stdc++.h>

using namespace std;
using ll = long long;
/*The naive approach obviously is exploring all combinations of 4 integers using 4 loops.

Now, to look into improving, does it help if we sort the array ?

Also, think of how your approach would change
if you did not have to list all of the unique tuples but just tell
whether at least one such tuple existed ( YES / NO

When the array is sorted, try to fix the least and second least integer by looping over it.
Lets say the least integer in the solution is arr[i] and second least is arr[j].
Now we need to find a pair of integers k and l such that arr[k] + arr[l] is target-arr[i]-arr[j].
To do that, lets try the 2 pointer approach. If we fix the two pointers at the end ( that is, j+1 and end of array ), we look at the sum.
If the sum is smaller than the sum we want, we increase the first pointer to increase the sum.
If the sum is bigger than the sum we want, we decrease the end pointer to reduce the sum.

Note that there is one more solution possible if the question only asked to answer YES / NO to suggest whether there existed at least one tuple with the target sum.
Then we could have gone with an approach using more memory with hashing.

Getting a Time Limit exceeded or Output Limit exceeded ?

Make sure you handle case of empty input []. In C++/C, Usually if you run a loop till array.size() - 2, it can lead to the program running indefinitely as array.size() is unsigned int, and the subtraction just makes it wrap over to a big integer.

Make sure you are not processing the same triplets again. Skip over the duplicates in the array.
Try a input like :
-1 -1 -1 -1 0 0 0 0 1 1 1 1
Ideally, you should get only 3 pairs : {[-1 -1 1 1], [-1 0 0 1], [0 0 0 0]}

*/
struct pairs {
	int sum;
	int f;
	int s;
};

bool compare(pairs a, pairs b) {
	return a.sum < b.sum;
}

bool noCommon(pairs a, pairs b) {
	if (a.f == b.f || a.f == b.s || a.s == b.f || a.s == b.s)
		return false;
	return true;
}

vector<vector<int> > fourSum(vector<int> &arr, int k) {
	int n = arr.size();
	vector<pairs> a;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			pairs t;
			t.sum = arr[i] + arr[j];
			t.f = i;
			t.s = j;
			a.push_back(t);
		}
	}
	sort(a.begin(), a.end(), compare);
	/*for (auto i : a)
		cout << i.sum << " " << i.f << " " << i.s << endl;*/
	int i = 0, j = a.size() - 1;
	set<vector<int>> se;
	vector<vector<int> > res;
	vector<int> r(4);
	while (i < n && j >= 0)
	{
		if (a[i].sum + a[j].sum == k && noCommon(a[i], a[j]))
		{
			r[0] = arr[a[i].f];
			r[1] = arr[a[i].s];
			r[2] = arr[a[j].f];
			r[3] = arr[a[j].s];
			//sort(r.begin(), r.end());
			se.insert(r);
			i++;
			j--;
		}
		else if (a[i].sum + a[j].sum < k)
		{
			i++;
		}
		else
			j--;
	}
	for (auto i : se)
		res.push_back(i);
	//return vector<vector<int>>();
	return res;
}

vector<vector<int> > fourSum(vector<int> &arr, int k) {
	// Your code goes here
	int n = arr.size();
	unordered_map<int, pair<int, int>> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			m[arr[i] + arr[j]] = {i, j};
		}
	}
	set<vector<int>> se;
	vector<vector<int>> res;
	vector<int> r(4);
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			int sum = arr[i] + arr[j];
			if (m.find(k - sum) != m.end())
			{
				pair<int, int> p = m[k - sum];
				if (p.first != i && p.first != j && p.second != i && p.second != j)
				{
					r[0] = arr[i];
					r[1] = arr[j];
					r[2] = arr[p.first];
					r[3] = arr[p.second];
					se.insert(r);

				}
			}
		}
	for (auto i : se)
		res.push_back(i);
	return res;
}


class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		int n = nums.size();
		vector<vector<int>> res;
		set<vector<int>> s;
		vector<int> r(4);
		sort(nums.begin(), nums.end());
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				int k = j + 1, a = n - 1;
				while (k < a)
				{
					if (nums[i] + nums[j] + nums[k] + nums[a] == target)
					{
						r[0] = nums[i];
						r[1] = nums[j];
						r[2] = nums[k];
						r[3] = target - (r[0] + r[1] + r[2]);
						res.push_back(r);
						int l = nums[k];
						while (k < n && nums[k] == l)
							k++;
						int rv = nums[a];
						while (a > k && nums[a] == rv)
							a--;
					}
					else if (nums[i] + nums[j] + nums[k] + nums[a] < target)
					{
						k++;
					}
					else
						a--;
				}
				while (j + 1 < n && nums[j + 1] == nums[j])
					j++;
			}
			while (i + 1 < n && nums[i + 1] == nums[i])
				i++;
		}


		return res;
	}
};

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		int n = nums.size();
		vector<vector<int>> res;
		set<vector<int>> s;
		vector<int> r(4);
		sort(nums.begin(), nums.end());
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				int k = j + 1, a = n - 1;
				while (k < a)
				{
					if (nums[i] + nums[j] + nums[k] + nums[a] == target)
					{
						r[0] = nums[i];
						r[1] = nums[j];
						r[2] = nums[k];
						r[3] = target - (r[0] + r[1] + r[2]);
						s.insert(r);
						k++;
						a--;
					}
					else if (nums[i] + nums[j] + nums[k] + nums[a] < target)
					{
						k++;
					}
					else
						a--;
				}
			}
		}
		for (vector<int> r : s)
			res.push_back(r);

		return res;
	}
};

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		int n = nums.size();
		vector<vector<int>> res;
		set<vector<int>> s;
		vector<int> r(4);
		sort(nums.begin(), nums.end());
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				for (int k = j + 1; k < n; k++)
				{
					for (int a = k + 1; a < n; a++)
					{
						if (nums[i] + nums[j] + nums[k] + nums[a] == target)
						{
							r[0] = nums[i];
							r[1] = nums[j];
							r[2] = nums[k];
							r[3] = target - (r[0] + r[1] + r[2]);
							s.insert(r);
						}
					}
				}
			}
		}
		for (vector<int> r : s)
			res.push_back(r);

		return res;
	}
};

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		int n = nums.size();
		vector<vector<int>> res;
		set<vector<int>> s;
		vector<int> r(4);
		sort(nums.begin(), nums.end());
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				for (int k = j + 1; k < n; k++)
				{
					if (binary_search(nums.begin() + k + 1, nums.end(), target - (nums[i] + nums[j] + nums[k])))
					{
						r[0] = nums[i];
						r[1] = nums[j];
						r[2] = nums[k];
						r[3] = target - (r[0] + r[1] + r[2]);
						s.insert(r);
					}
				}
			}
		}
		for (vector<int> r : s)
			res.push_back(r);

		return res;
	}
};
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		int n = nums.size();
		vector<vector<int>> res;
		vector<int> r(4);
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				for (int k = j + 1; k < n; k++)
				{
					for (int a = k + 1; a < n; a++)
					{
						if (nums[i] + nums[j] + nums[k] + nums[a] == target)
						{
							r[0] = nums[i];
							r[1] = nums[j];
							r[2] = nums[k];
							r[3] = nums[a];
							res.push_back(r);
						}
					}
				}
			}
		}
		return res;
	}
};
vector<vector<int> > fourSum(vector<int> &arr, int k) {
	// Your code goes here
	int n = arr.size();
	vector<vector<int>> res;
	vector<int> r(4);
	set<vector<int>> s;
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			for (int a = j + 1; a < n; a++)
			{
				if (binary_search(arr.begin() + a + 1, arr.end(), k - (arr[i] + arr[j] + arr[a])))
				{
					r[0] = arr[i];
					r[1] = arr[j];
					r[2] = arr[a];
					r[3] = k - (r[0] + r[1] + r[2]);
					s.insert(r);
				}
			}
		}
	}
	for (auto i : s)
		res.push_back(i);
	sort(res.begin(), res.end());
	return res;
}

// User function template for C++

// arr[] : int input array of integers
// k : the quadruple sum required
vector<vector<int> > fourSum(vector<int> &arr, int k) {
	// Your code goes here
	int n = arr.size();
	vector<vector<int>> res;
	vector<int> r(4);
	set<vector<int>> s;
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int l = j + 1, ri = n - 1;
			while (l < ri)
			{
				if (arr[i] + arr[j] + arr[l] + arr[ri] == k)
				{
					r[0] = arr[i];
					r[1] = arr[j];
					r[2] = arr[l];
					r[3] = arr[ri];
					s.insert(r);
					l++;
					ri--;
				}
				else if (arr[i] + arr[j] + arr[l] + arr[ri] < k)
				{
					l++;
				}
				else
				{
					ri--;
				}
			}
		}
	}
	for (auto i : s)
		res.push_back(i);
	//sort(res.begin(),res.end());
	return res;
}
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		int n = nums.size();
		vector<vector<int>> res;
		set<vector<int>> s;
		vector<int> r(4);
		sort(nums.begin(), nums.end());
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				for (int k = j + 1; k < n; k++)
				{
					if (binary_search(nums.begin() + k + 1, nums.end(), target - (nums[i] + nums[j] + nums[k])))
					{
						r[0] = nums[i];
						r[1] = nums[j];
						r[2] = nums[k];
						r[4] = target - (r[0] + r[1] + r[2]);
						s.insert(r);
					}
				}
			}
		}
		for (vector<int> r : s)
			res.push_back(r);

		return res;
	}
};
// User function template for C++

// arr[] : int input array of integers
// k : the quadruple sum required
vector<vector<int> > fourSum(vector<int> &arr, int k) {
	// Your code goes here
	int n = arr.size();
	vector<vector<int>> res;
	vector<int> r(4);
	set<vector<int>> s;
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int l = j + 1, ri = n - 1;
			while (l < ri)
			{
				if (arr[i] + arr[j] + arr[l] + arr[ri] == k)
				{
					r[0] = arr[i];
					r[1] = arr[j];
					r[2] = arr[l];
					r[3] = arr[ri];
					res.push_back(r);
					int lvalue = arr[l];
					while (l < n && arr[l] == lvalue)
						l++;
					int rvalue = arr[ri];
					while (ri > l && arr[ri] == rvalue)
						ri--;
				}
				else if (arr[i] + arr[j] + arr[l] + arr[ri] < k)
				{
					l++;
				}
				else
				{
					ri--;
				}
			}
			while (j + 1 < n && arr[j + 1] == arr[j])
				j++;
		}
		while (i + 1 < n && arr[i + 1] == arr[i])
			i++;
	}
	//res.resize(distance(res.begin(),unique(res.begin(),res.end())));
	return res;
}
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	return 0;
}