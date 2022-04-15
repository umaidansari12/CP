/*#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, q, m;
	cin >> n >> q >> m;
	long long int pro = 1;
	vector<long long int> a(n), ans;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		pro *= a[i];
	}
	while (q--)
	{
		int x;
		cin >> x;
		long long int an = pro / (long long int)a[x - 1];
		ans.push_back(an % m);
	}
	for (auto i : ans)
		cout << i << "\n";
	return 0;
}*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, q;
	cin >> n >> q;
	long long int m;// pro = 1;
	cin >> m;
	vector<long long int> a(n), ans;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	while (q--)
	{
		int x;
		cin >> x;
		long long int pro = 1;
		for (int i = 0; i < n; i++)
		{
			if (i == (x - 1))
				continue;
			pro *= a[i];
		}
		ans.push_back(pro % m);
	}
	for (auto i : ans)
		cout << i << "\n";


	return 0;
}