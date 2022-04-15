#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	/*cin.tie(NULL);
	cout.tie(NULL);*/
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		long long int sum = 0, pro = 1;
		for (int i = 1; i <= n; i++)
		{
			sum += i;
			pro *= i;
		}
		if (pro % sum == 0)
			cout << "YES\n";
		else
			cout << "NO\n";
	}


	return 0;
}