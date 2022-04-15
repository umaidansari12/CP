#include <bits/stdc++.h>

using namespace std;
using ll = long long;


void nger(vector<ll>a, int n)
{
	/*vector<long long> r;
	for (int i = 0; i < n - 1; i++)
	{
		int j;
		for (j = i + 1; j < n; j++)
		{
			if (arr[j] > arr[i])
			{
				r.push_back(arr[j]);
				break;
			}
		}
		if (j == n)
			r.push_back(-1);
	}
	r.push_back(-1);
	return r;
	for (int i = 0; i < n - 1; i++)
	{
		int j;
		for (j = i + 1; j < n; j++)
		{
			if (a[j] > a[i])
			{
				cout << a[j] << " ";
				break;
			}
		}
		if (j == n)
			cout << -1 << " ";
	}
	cout << -1 << " " << endl;*/
	//NGE in same order as input
	stack<ll> s;
	vector<ll> r;
	for (int i = n - 1; i >= 0; i--)
	{
		while (!s.empty() && a[i] >= s.top())
			s.pop();
		if (s.size() == 0)
			r.push_back(-1);
		else
			r.push_back(s.top());
		s.push(a[i]);
	}
	reverse(r.begin(), r.end());
	for (auto i : r)
		cout << i << " ";
	cout << endl;
}

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
		vector<ll> a(n, 0);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		nger(a, n);

	}


	return 0;
}