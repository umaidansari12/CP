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
		int n, d;
		cin >> n >> d;
		vector<int> risk, nrisk;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			if (x <= 9 || x >= 80)
			{
				risk.push_back(x);
			}
			else
			{
				nrisk.push_back(x);
			}
		}
		int ans1 = (risk.size() % d == 0) ? risk.size() / d : (risk.size() / d) + 1;
		int ans2 = (nrisk.size() % d == 0) ? nrisk.size() / d : (nrisk.size() / d) + 1;
		cout << ans1 + ans2 << endl;
	}


	return 0;
}