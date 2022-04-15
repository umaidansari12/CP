#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void nextSmallerElement(vector<int>&A, int n)
{
	stack<int> s;
	vector<int> r;
	unordered_map<int, int> m;
	s.push(A[0]);
	for (int i = 1; i < A.size(); i++)
	{
		if (s.empty())
		{
			s.push(A[i]);
			continue;
		}
		while (!s.empty() && s.top() > A[i])
		{
			m[s.top()] = A[i];
			s.pop();
		}
		s.push(A[i]);
	}
	while (!s.empty())
	{
		m[s.top()] = -1;
		s.pop();
	}
	for (int i = 0; i < A.size(); i++)
	{
		cout << m[A[i]] << " ";
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