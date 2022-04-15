#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> a;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;

	for (int i = 1; i <= 2000; i++)
	{
		if (i % 3 == 0 or (i % 10 == 3))
		{
			continue;
		}
		else
			a.push_back(i);
	}

	while (t--)
	{
		int k;
		cin >> k;
		cout << a[k - 1] << '\n';
	}


	return 0;
}