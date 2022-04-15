#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void nextSmallerElement(vector<int>&a, int n)
{
	stack<int> s;
	s.push(a[0]);
	for (int i = 1; i < n; i++)
	{
		if (s.empty())
		{
			s.push(a[i]);
			continue;
		}
		while (!s.empty() && s.top() > a[i])
		{
			cout << a[i] << " ";
			s.pop();
		}
		s.push(a[i]);
	}
	while (!s.empty())
	{
		cout << -1 << " ";
		s.pop();
	}
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
		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		/*for (int i = 0; i < n; i++)
		{
			int res = -1;
			for (int j = i + 1; j < n; j++)
			{
				if (a[j] < a[i])
				{
					res = a[j];
					break;
				}
			}
			cout << res << " ";
		}
		cout << endl;*/
		nextSmallerElement(a, n);
	}


	return 0;
}