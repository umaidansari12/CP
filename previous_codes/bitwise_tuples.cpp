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
		long long int n, m, count = 0;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			int andBit = 0;
			for (int j = 0; j < pow(2, m); j++)
			{
				andBit &= j;
				if (andBit == 0)
					count++;
			}

		}
		cout << count << endl;
	}


	return 0;
}