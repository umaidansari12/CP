#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
	int w1, w2, x1, x2, M;
	cin >> w1 >> w2 >> x1 >> x2 >> M;
	int weightChange = w2 - w1, flag = 0;
	if (weightChange >= M * x1 && weightChange <= M * x2)
	{
		flag = 1;
	}

	if (flag)
		cout << "1\n";
	else
		cout << "0\n";

}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}


	return 0;
}