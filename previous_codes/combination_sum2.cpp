#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
	//Brute force gives TLE
	void findcombination(int ind, int target, vector<int> arr, vector<int>&ds, set<vector<int>>&ans)
	{
		if (ind == arr.size())
		{
			if (target == 0)
				ans.insert(ds);
			return;
		}
		if (arr[ind] <= target)
		{
			ds.push_back(arr[ind]);
			findcombination(ind + 1, target - arr[ind], arr, ds, ans);
			ds.pop_back();
		}
		findcombination(ind + 1, target, arr, ds, ans);

	}
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		set<vector<int>>ans;
		sort(candidates.begin(), candidates.end());
		vector<int> ds;
		vector<vector<int>> res;
		findcombination(0, target, candidates, ds, ans);
		for (auto i : ans)
			res.push_back(i);
		return res;

	}

	void solve(int ind, int target, vector<int>&arr, vector<int>&ds, vector<vector<int>>&ans)
	{
		if (target == 0)
		{
			ans.push_back(ds);
			return ;
		}
		for (int i = ind; i < arr.size(); i++)
		{
			if (i > ind && arr[i] == arr[i - 1])
				continue;
			if (arr[i] > target)
				break;
			ds.push_back(arr[i]);
			solve(i + 1, target - arr[i], arr, ds, ans);
			ds.pop_back();
		}
	}
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<int> ds;
		vector<vector<int>> ans;
		sort(candidates.begin(), candidates.end());
		solve(0, target, candidates, ds, ans);
		return ans;

	}
};

void combinationSum2(vector<int>&a, int sum, vector<vector<int>>&res, vector<int>&r, int i, int n)
{
	if (sum < 0)
		return;
	if (sum == 0)
	{
		res.push_back(r);
		return;
	}
	for (int j = i; j < n; j++)
	{
		if (sum - a[j] >= 0)
		{
			r.push_back(a[j]);
			combinationSum2(a, sum - a[j], res, r, j + 1, n);
			r.pop_back();
		}
	}
	return;
}

void solve(vector<int>&A, int sum, vector<vector<int>>&res, vector<int> r, int i)
{
	if (sum < 0)
		return;
	if (sum == 0)
	{
		res.push_back(r);
		return;
	}
	for (int j = i; j < A.size(); j++)
	{
		if (sum - A[j])
		{
			r.push_back(A[j]);
			solve(A, sum - A[j], res, r, j + 1);
			r.pop_back();
		}
	}
}


vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
	// Do not write main() function.
	// Do not read input, instead use the arguments to the function.
	// Do not print the output, instead return values as specified
	// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more d
	sort(A.begin(), A.end());
	vector<vector<int>> res;
	vector<int> r;
	solve(A, B, res, r, 0);
	sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());
	return res;
}

class Solution {
public:
	void solve(vector<int>&a, int sum, vector<vector<int>>&res, vector<int>&r, int i, int n)
	{
		if (sum < 0)
			return;
		if (sum == 0)
		{
			res.push_back(r);
			return;
		}
		for (int j = i; j < n; j++)
		{
			if (sum - a[j] >= 0)
			{
				r.push_back(a[j]);
				solve(a, sum - a[j], res, r, j + 1, n);
				r.pop_back();
			}
		}
		return;
	}
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> res;
		vector<int> r;
		sort(candidates.begin(), candidates.end());
		solve(candidates, target, res, r, 0, candidates.size());
		sort(res.begin(), res.end());
		res.erase(unique(res.begin(), res.end()), res.end());
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
	while (T--) {
		int n, b;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cin >> b;
		sort(a.begin(), a.end());
		//a.erase(unique(a.begin(), a.end()), a.end());
		vector<vector<int>> res;
		vector<int> r;
		combinationSum2(a, b, res, r, 0, n);
		sort(res.begin(), res.end());
		res.erase(unique(res.begin(), res.end()), res.end());
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
    void solve(vector<int>&a,int sum,vector<vector<int>>&res,vector<int>&r,int i,int n)
    {
        if(sum<0)
            return;
        if(sum==0)
        {
            res.push_back(r);
            return;
        }
        for(int j=i;j<n;j++)
        {
            if(sum-a[j]>=0)
            {
                r.push_back(a[j]);
                solve(a,sum-a[j],res,r,j+1,n);
                r.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> r;
        sort(candidates.begin(),candidates.end());
        solve(candidates,target,res,r,0,candidates.size());
        sort(res.begin(),res.end());
        res.erase(unique(res.begin(),res.end()),res.end());
        return res;

    }
};
*/