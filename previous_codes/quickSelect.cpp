#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int partition(vector<int>&a, int l, int h)
{
	int i = l - 1;
	for (int j = l; j < h; j++)
	{
		if (a[j] < a[h])
		{
			swap(a[++i], a[j]);
		}
	}
	swap(a[i + 1], a[h]);
	return i + 1;
}

int quickSelect(vector<int>&a, int l, int h, int k)
{
	int p = partition(a, l, h);
	if (p == k - 1)
		return a[p];
	else if (k - 1 < p )
		return quickSelect(a, l, p - 1, k);
	else
		return quickSelect(a, p + 1, h, k);

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
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << quickSelect(a, 0, n - 1, k) << endl;
	}


	return 0;
}