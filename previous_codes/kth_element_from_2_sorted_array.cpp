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
	while (T--) {
		int n, m, k;
		cin >> n >> m >> k;
		vector<int> a(n), b(m), res;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			res.push_back(a[i]);
		}
		for (int i = 0; i < m; i++)
		{
			cin >> b[i];
			res.push_back(b[i]);
		}
		sort(res.begin(), res.end());
		cout << res[k - 1] << endl;

	}


	return 0;
}