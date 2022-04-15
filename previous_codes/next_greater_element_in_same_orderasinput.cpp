#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void nextGreaterElement(vector<long long int>&a, int n)
{
	stack<long long int> s;
	vector<long long int> a1(n, 0);
	for (int i = n - 1; i >= 0; i--)
	{
		while (!s.empty() && s.top() <= a[i])
			s.pop();
		if (s.empty())
			a1[i] = -1;
		else
			a1[i] = s.top();
		s.push(a[i]);
	}
	for (int i = 0; i < n; i++)
		cout << a1[i] << " ";
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
		vector<long long int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		/*for (int i = 0; i < n; i++)
		{
			int res = -1;
			for (int j = i + 1; j < n; j++)
			{
				if (a[j] > a[i])
				{
					res = a[j];
					break;
				}
			}
			cout << res << " ";
		}*/
		nextGreaterElement(a, n);
		//cout << endl;
	}


	return 0;
}