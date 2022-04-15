#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}


int SumOfGCD(int n) {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += (i * gcd(i, n));
	}
	return sum;
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
		int n;
		cin >> n;
		cout << SumOfGCD(n) << endl;
	}

	return 0;
}