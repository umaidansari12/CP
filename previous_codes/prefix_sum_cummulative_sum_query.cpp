#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int n, q, i, j;
	cin >> n;
	vector<int> a(n), prefixSum(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (i == 0)
			prefixSum[i] = a[i];
		else
			prefixSum[i] = prefixSum[i - 1] + a[i];
	}
	cin >> q;
	while (q--)
	{
		cin >> i >> j;
		if (i == 0)
			cout << prefixSum[j] << endl;
		else
			cout << prefixSum[j] - prefixSum[i - 1] << endl;
	}


	return 0;
}