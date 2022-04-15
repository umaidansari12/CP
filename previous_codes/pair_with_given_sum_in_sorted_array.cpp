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
		int n, k;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cin >> k;
		int i = 0, j = n - 1, flag = 0;
		while (i < j)
		{
			if (a[i] + a[j] == k)
			{
				flag = 1;
				cout << a[i] << " " << a[j] << " " << k << " \n";
				i++;
				j--;
			}
			else if (a[i] + a[j] < k)
				i++;
			else
				j--;
		}
		if (!flag)
			cout << -1 << endl;
	}



	return 0;
}