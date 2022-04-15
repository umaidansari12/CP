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
		int n, x;
		cin >> n >> x;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		int i = 0, j = n - 1, f = 0;
		while (i <= j)
		{
			if (a[i] + a[j] == x)
			{
				cout << "Yes" << endl;
				f = 1;
				break;
			}
			else if (a[i] + a[j] > x)
				j--;
			else
				i++;
		}
		if (f)
			cout << "No" << endl;
	}


	return 0;
}