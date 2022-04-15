#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int findTotalDistance(int input1, int input2[])
{
	int ans = 0;
	for (int i = 1; i < input1; i++)
	{
		ans += abs(input2[i] - input2[i - 1]);
	}
	return ans;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, ans = 0;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	cout << ans << endl;


	return 0;
}