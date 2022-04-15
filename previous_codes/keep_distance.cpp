#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool isFeasible(int mid, int arr[], int n, int k)
{

	int pos = arr[0];


	int elements = 1;


	for (int i = 1; i < n; i++) {
		if (arr[i] - pos >= mid) {
			pos = arr[i];
			elements++;
			if (elements == k)
				return true;
		}
	}
	return false;
}

int largestMinDist(int arr[], int n, int k)
{

	sort(arr, arr + n);
	int res = -1;
	int left = 1, right = arr[n - 1];
	while (left < right) {
		int mid = (left + right) / 2;
		if (isFeasible(mid, arr, n, k)) {
			res = max(res, mid);
			left = mid + 1;
		}
		else
			right = mid;
	}

	return res;
}

void keepDistance(int n, int m, vector<int> &a, vector<vector<int>> &res, vector<int>& r, int j)
{
	// Write Your Code here
	if (r.size() == m)
	{
		res.push_back(r);
		return;
	}
	for (int i = j; i < n ; i++)
	{
		r.push_back(a[i]);
		keepDistance(n, m, a, res, r, i + 1);
		r.pop_back();
	}

}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	// int result = keepDistance(n, m, a, res, r, 0);
	// cout << result << "\n";
	vector<vector<int>> res;
	vector<int> r;
	keepDistance(n, m, a, res, r, 0);
	int ans = INT_MIN;
	for (int i = 0; i < res.size(); i++)
	{
		int mi = INT_MAX;
		for (int j = 1; j < m; j++)
			mi = min(mi, res[i][j] - res[i][j - 1]);
		ans = max(mi, ans);

	}
	cout << ans << endl;
}