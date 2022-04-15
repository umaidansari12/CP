#include <bits/stdc++.h>

using namespace std;
using ll = long long;


int fun1()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n, m, x;
		cin >> n >> m >> x;
		int count = 0;
		vector<int> a(n), b(m);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < m; i++)
			cin >> b[i];
		string s;
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		for (int i = 0; i < n; i++)
		{
			if (binary_search(b.begin(), b.end(), x - a[i]))
			{
				int idx = lower_bound(b.begin(), b.end(), x - a[i]) - b.begin();
				s = s + (to_string(a[i]) + " " + to_string(b[idx]) + ", ");
			}
		}
		if (s.size() == 0)
			cout << -1 << endl;
		else
		{
			for (int i = 0; i < s.size() - 2; i++)
				cout << s[i];
			cout << endl;
		}
	}


	return 0;
}
int fun() {
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, x;
		cin >> n >> m >> x;
		vector<int> v(n, 0), v1(m, 0);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		for (int i = 0; i < m; i++)
			cin >> v1[i];
		sort(v.begin(), v.end());
		sort(v1.begin(), v1.end());
		int flag = 1, flag1 = 0;;
		for (int i = 0; i < n; i++)
		{
			if (binary_search(v1.begin(), v1.end(), x - v[i]))
			{	if (flag1)
				{
					cout << "," << " ";
				}
				flag = 0;
				flag1 = 1;
				int ans = lower_bound(v1.begin(), v1.end(), x - v[i]) - v1.begin();
				cout << v[i] << " " << v1[ans];
			}

		}
		if (flag)
			cout << -1 << endl;
		else
			cout << endl;
	}
	return 0;
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
		int n, m, x;
		cin >> n >> m >> x;
		int count = 0;
		vector<int> a(n), b(m);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < m; i++)
			cin >> b[i];
		string s;
		//	sort(a.begin(), a.end());
		//	sort(b.begin(), b.end());
		map<int, int> c;
		for (int i = 0; i < n; i++)
		{
			c[a[i]]++;
		}
		//string s;
		for (int i = 0; i < m; i++)
		{
			if (c.find(x - b[i]) != c.end())
			{
				s = s + (to_string(x - b[i]) + " " + to_string(b[i]) + ", ");
			}
		}
		/*
		int low = 0,  high = m - 1;
		string s = "";
		while (true)
		{
			if (a[low] + b[high] == x)
			{
				count++;
				s = s + (to_string(a[low]) + " " + to_string(b[high]) + ", ");
				low++;
				high--;
				if (low >= n)
					break;
				if (high < 0)
					break;
			}
			else if (a[low] + b[high] < x)
			{
				if (low >= n)
					break;
				else
					low++;
			}
			else if (a[low] + b[high] > x)
			{
				if (high < 0)
					break;
				else
					high--;
			}
		}*/
		if (s.size() == 0)
			cout << -1 << endl;
		else
		{
			for (int i = 0; i < s.size() - 2; i++)
				cout << s[i];
			cout << endl;
		}
	}


	return 0;
}