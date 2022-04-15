#include <bits/stdc++.h>

using namespace std;
using ll = long long;

long long int power(long long int a, long long int b, long long int n)
{
	if (n == 0)
		return (long long int)1;
	return (long long int)((long long int)a * (long long int)power(a, b, n - 1)) * ((long long int)b * (long long int)power(a, b, n - 1));
}

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n, a, b;
		cin >> n >> a >> b;
		long long int r = power(a, b, n);
		cout << r << endl;
	}


	return 0;
}