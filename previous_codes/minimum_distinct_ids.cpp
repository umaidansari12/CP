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
		unordered_map<int, int> m;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			m[x]++;
		}
		int k;
		cin >> k;
		vector<int> v;
		for (auto i = m.begin(); i != m.end(); i++)
		{
			v.push_back(i->second);
		}
		sort(v.begin(), v.end());
		int count = 0;
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] <= k)
			{
				k -= v[i];
				count++;
			}
			else
			{
				break;
			}
		}
		cout << v.size() - count << endl;

	}


	return 0;
}