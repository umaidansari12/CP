#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> Brute(vector<int> a, int n, int ma)
{
	vector<int> r;
	r.push_back(ma);
	for (int k = 2; k <= n; k++)
	{
		ma = INT_MIN;
		for (int i = 0; i <= n - k; i++)
		{
			int mi = INT_MAX;
			for (int j = i; j < i + k; j++)
			{
				mi = min(a[j], mi);
			}
			ma = max(ma, mi);
		}
		r.push_back(ma);
	}
	return r;
}

vector<int> Better(vector<int>a, int n, int ma)
{
	vector<int> r;
	//r.push_back(ma);
	for (int k = 1; k <= n; k++)
	{
		int ma = INT_MIN, i = 0;
		deque<int> q(k);
		for (i = 0; i < k; i++)
		{
			while (!q.empty() && a[q.back()] >= a[i])
				q.pop_back();
			q.push_back(i);
		}
		for (; i < n; i++)
		{
			ma = max(ma, a[q.front()]);
			while (!q.empty() && q.front() <= (i - k))
				q.pop_front();
			while (!q.empty() && a[q.back()] >= a[i])
				q.pop_back();
			q.push_back(i);
		}
		ma = max(ma, a[q.front()]);
		r.push_back(ma);
	}
	return r;
}

vector <int> maxOfMin(int arr[], int n) {
	// Your code here
	vector<int> r;
	vector<int> left(n, -1), right(n, n);
	stack<int> s;
	for (int i = 0; i < n; i++)
	{
		while (!s.empty() && arr[s.top()] >= arr[i])
			s.pop();
		if (!s.empty())
			left[i] = s.top();
		s.push(i);
	}
	while (!s.empty())
		s.pop();
	for (int i = n - 1; i >= 0; i--)
	{
		while (!s.empty() && arr[s.top()] >= arr[i])
			s.pop();
		if (!s.empty())
			right[i] = s.top();
		s.push(i);
	}
	vector<int> ans(n + 1, 0);
	for (int i = 0; i < n; i++)
	{
		int len = right[i] - left[i] - 1;
		ans[len] = max(ans[len], arr[i]);
	}
	for (int i = n - 1; i >= 1; i--)
	{
		ans[i] = max(ans[i], ans[i + 1]);
	}
	for (int i = 1; i <= n; i++)
		r.push_back(ans[i]);
	return r;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n, ma = INT_MIN;
		cin >> n;
		vector<int> arr(n, 0);
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			ma = max(ma, arr[i]);
		}

		vector<int> r = Better(arr, n, ma);
		for (auto i : r)
			cout << i << " ";
		cout << endl;
	}


	return 0;
}