#include <bits/stdc++.h>

using namespace std;
using ll = long long;

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
			cin >> a[i];
		unordered_map<int, int>  m;
		for (int i = 0; i < n; i++)
		{
			m[a[i]]++;
		}
		for (int i = 0; i < n; i++)
		{
			if (m[a[i]] % 2 != 0)
			{
				cout << a[i] << " ";
			}
		}
		/*for (auto i : m)
		{
			if (i.second % 2 != 0)
			{
				cout << i.first << " ";
			}
		}*/
		cout << endl;
	}


	return 0;
}