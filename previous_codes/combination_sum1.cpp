#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*Think how can you use recursion with current index and target sum in order to generate all combinations.
In every recursion run, you either include the element in the combination or you don’t. To account for multiple occurrences of an element, make sure you call the next function without incrementing the current index.*/

void choose(const vector<int>& A, int index, int target, vector<int> current, vector<vector<int>>& ans) {
	if (target == 0) ans.push_back(current);

	for (auto i = index; i < A.size(); ++i) {
		if (A[i] > target) break;

		current.push_back(A[i]);
		choose(A, i, target - A[i], current, ans);
		current.pop_back();
	}
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
	sort(A.begin(), A.end());
	A.erase(unique(A.begin(), A.end()), A.end());

	vector<vector<int>> ans;
	choose(A, 0, B, {}, ans);
	return ans;
}

class Solution {
public:
	void solve(vector<int>&A, int ind, int n, int B, vector<int>&r, vector<vector<int>>&res)
	{
		if (ind >= n || B < 0)
		{
			return ;
		}
		if (B == 0)
		{
			res.push_back(r);
		}
		while (ind < n && A[ind] <= B)
		{
			r.push_back(A[ind]);
			solve(A, ind, n, B - A[ind], r, res);
			ind++;
			r.pop_back();
		}
		// solve(A,ind+1,n,B,r,s);
	}
	vector<vector<int> > combinationSum(vector<int> &A, int B) {
		// Your code here
		sort(A.begin(), A.end());
		A.erase(unique(A.begin(), A.end()), A.end());
		vector<vector<int>> res;
		vector<int> r;
		//set<vector<int>> s;
		solve(A, 0, A.size(), B, r, res);
		/*for(auto i:s)
		res.push_back(i);*/
		return res;
	}
};


class Solution {
public:
	void solve(vector<int>&A, int ind, int n, int B, vector<int>&r, set<vector<int>>&s)
	{
		if (ind >= n || B < 0)
		{
			return ;
		}
		if (B == 0)
		{
			s.insert(r);
		}
		if (A[ind] <= B)
		{
			r.push_back(A[ind]);
			solve(A, ind, n, B - A[ind], r, s);
			//ind++;
			r.pop_back();
		}
		solve(A, ind + 1, n, B, r, s);
	}
	vector<vector<int> > combinationSum(vector<int> &A, int B) {
		// Your code here
		sort(A.begin(), A.end());
		A.erase(unique(A.begin(), A.end()), A.end());
		vector<vector<int>> res;
		vector<int> r;
		set<vector<int>> s;
		solve(A, 0, A.size(), B, r, s);
		for (auto i : s)
			res.push_back(i);
		return res;
	}
};


class SolutionGFG {
public:
	void solve(vector<int>&A, int ind, int n, int B, vector<int>&r, set<vector<int>>&s)
	{
		if (ind == n)
		{
			if (B == 0)
			{
				s.insert(r);
			}
			return ;
		}
		if (A[ind] <= B)
		{
			r.push_back(A[ind]);
			solve(A, ind, n, B - A[ind], r, s);
			r.pop_back();
		}
		solve(A, ind + 1, n, B, r, s);
	}
	vector<vector<int> > combinationSum(vector<int> &A, int B) {
		// Your code here
		sort(A.begin(), A.end());
		vector<vector<int>> res;
		vector<int> r;
		set<vector<int>> s;
		solve(A, 0, A.size(), B, r, s);
		for (auto i : s)
			res.push_back(i);
		return res;
	}
};
class Solution {
public:
	void findcombination(int ind, int target, vector<int> arr, vector<int>&ds, vector<vector<int>>&ans)
	{
		if (ind == arr.size())
		{
			if (target == 0)
				ans.push_back(ds);
			return;
		}
		if (arr[ind] <= target)
		{
			ds.push_back(arr[ind]);
			findcombination(ind, target - arr[ind], arr, ds, ans);
			ds.pop_back();
		}
		findcombination(ind + 1, target, arr, ds, ans);

	}
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>>ans;
		vector<int> ds;
		findcombination(0, target, candidates, ds, ans);
		return ans;

	}
};

void combinationSum1(vector<int>&a, int sum, vector<vector<int>>&res, vector<int>&r, int i)
{
	if (sum < 0)
		return;
	if (sum == 0)
	{
		res.push_back(r);
		return;
	}
	while (i < a.size() && sum - a[i] >= 0)
	{
		r.push_back(a[i]);
		combinationSum1(a, sum - a[i], res, r, i);
		i++;
		r.pop_back();
	}
}


int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n, b;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cin >> b;
		//sort(a.begin(), a.end());
		//a.erase(unique(a.begin(), a.end()), a.end());
		vector<vector<int>> res;
		vector<int> r;
		combinationSum1(a, b, res, r, 0);
		if (res.size() == 0)
			cout << "Empty\n";
		else
		{
			for (vector<int> i : res)
			{
				cout << "(";
				for (int j = 0; j < i.size(); j++)
				{
					cout << i[j];
					if (j != i.size() - 1)
						cout << " ";
				}
				cout << ")";
			}
			cout << endl;
		}
	}


	return 0;
}

/*class Solution {
public:
	void solve(vector<int>&a, int sum, vector<vector<int>>&res, vector<int>&r, int i)
	{
		if (sum < 0)
			return;
		if (sum == 0)
		{
			res.push_back(r);
			return;
		}
		while (i < a.size() && sum - a[i] >= 0)
		{
			r.push_back(a[i]);
			solve(a, sum - a[i], res, r, i);
			i++;
			r.pop_back();
		}
	}
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> res;
		vector<int> r;
		sort(candidates.begin(), candidates.end());
		candidates.erase((candidates.begin(), candidates.end()), candidates.end());
		solve(candidates, target, res, r, 0);
		return res;

	}
};

void solve(vector<int>&A, int sum, vector<vector<int>>&res, vector<int>&r, int i)
{
	if (sum < 0)
		return;
	if (sum == 0)
	{
		res.push_back(r);
		return;
	}
	while (i < A.size() && sum - A[i] >= 0)
	{
		r.push_back(A[i]);
		solve(A, sum - A[i], res, r, i);
		i++;
		r.pop_back();
	}
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
	vector<vector<int>> res;
	vector<int> r;
	sort(A.begin(), A.end());
	A.erase(unique(A.begin(), A.end()), A.end());
	solve(A, B, res, r, 0);
	return res;
}
*/