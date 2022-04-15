#include <bits/stdc++.h>

using namespace std;
using ll = long long;

long long int reach_stair(int n)
{
	if (n == 0)
		return 1;
	if (n < 0)
		return 0;

	return reach_stair(n - 1) + reach_stair(n - 2) + reach_stair(n - 3);
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	cout << reach_stair(n) << endl;

	return 0;
}