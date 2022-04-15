#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void negative_subarray(vector<int> &a, int n, int k)
{
	deque<int> q(k);
	int i = 0;
	for (i = 0; i < k; i++)
	{
		while (!q.empty() && a[q.back()] > 0)
		{
			q.pop_back();
		}
		q.push_back(i);
	}
	for (; i < n; i++)
	{
		if (a[q.front()] > 0)
			cout << "0 ";
		else
			cout << a[q.front()] << " ";
		while (!q.empty() && q.front() <= i - k)
		{
			q.pop_front();
		}
		while (!q.empty() && a[q.back()] > 0)
		{
			q.pop_back();
		}
		q.push_back(i);
	}
	if (a[q.front()] > 0)
		cout << "0" << endl;
	else
		cout << a[q.front()] << endl;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		cin >> k;
		negative_subarray(a, n, k);
	}


	return 0;
}