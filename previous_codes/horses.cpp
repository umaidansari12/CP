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
	while (T--)	{
		int n;
		cin >> n;
		vector<int> s(n);
		for (int i = 0; i < n; i++)
			cin >> s[i];
		sort(s.begin(), s.end());
		int ans = INT_MAX;
		for (int i = 0; i <	n - 1; i++)
		{
			ans = min(ans, s[i + 1] - s[i]);
		}
		cout << ans << endl;
	}


	return 0;
}