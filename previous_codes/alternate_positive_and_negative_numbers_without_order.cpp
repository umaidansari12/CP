#include <bits/stdc++.h>

using namespace std;
using ll = long long;

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
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int i = 0, j = n - 1;
		while (i <= j)
		{
			if (a[i] < 0)
				swap(a[i], a[j--]);
			else
				i++;
		}
		j = 0;
		while (i < n)
		{
			swap(a[i++], a[j]);
			j += 2;
		}
		for (int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << endl;
	}



	return 0;
}