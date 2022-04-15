#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int Solution::findMedian(vector<vector<int> > &A) {
	int n = A.size(), m = A[0].size();
	int min = INT_MAX, max = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		if (min > A[i][0])
			min = A[i][0];
		if (max < A[i][m - 1])
			max = A[i][m - 1];
	}
	int d = (1 + n * m) / 2;
	while (min < max)
	{
		int mid = (min + max) / 2;
		int count = 0;
		for (int i = 0; i < n; i++)
			count += upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin();
		if (count < d)
			min = mid + 1;
		else
			max = mid;
	}
	return min;
}


int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> a(n, vector<int>(m, 0));
		vector<int> res;
		for (int i = 0; i < n; i++)
		{

			for (int j = 0; j < m; j++)
			{
				cin >> a[i][j];
				res.push_back(a[i][j]);
			}
		}
		sort(res.begin(), res.end());
		int p = n * m;
		cout << res[(p / 2)] << endl;
	}


	return 0;
}