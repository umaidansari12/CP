#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int ladder(int n)
{
	if (n < 0)
		return 0;
	if (n == 0)
		return 1;
	return ladder(n - 1) + ladder(n - 2) + ladder(n - 3);
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
		int n;
		cin >> n;
		cout << ladder(n) << endl;
	}


	return 0;
}