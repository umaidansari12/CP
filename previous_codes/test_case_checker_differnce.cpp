#include <bits/stdc++.h>

using namespace std;
//using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	/*long long int x;
	vector<long long int> a, b;
	int count = 0;
	while (cin >> x)
	{
		a.push_back(x);
		count++;
	}
	for (int i = 0; i < (count / 2); i++)
	{
		if (a[i] != a[(count / 2) + i])
			cout << a[i] << " " << a[(count / 2) + i] << " " << i << " " << (count / 2) + i << endl;
	}

	int x = 80;
	int &y = x;
	x++;
	cout << x << " " << (--y) << endl;*/
	int n;
	cin >> n;
	vector<vector<int>> m(n, vector<int>());
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		//m[i].resize(t);
		while (t--)
		{
			int x;
			cin >> x;

			m[i].push_back(x);
		}

	}
	for (int i = 0; i < m.size(); i++)
	{
		for (int j = 0; j < m[i].size(); j++)
			cout << m[i][j] << " ";
		cout << endl;
	}

	return 0;
}
