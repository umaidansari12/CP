#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	long long int power(int a, long long int b) {
		//complete the function here
		if (b == 0)
			return 1;
		if (b % 2 == 0)
		{
			long long y = power(a, b / 2);
			return ((y % 1000000007) * (y % 1000000007)) % 1000000007;
		}
		else
		{
			return ((a % 1000000007) * (power(a, b - 1) % 1000000007)) % 1000000007;
		}
	}
};

long long power(long long n, long long y)
{
	long long prod = 1, mod = pow(10, 9) + 7;
	while (y--)
	{
		prod *= n;
		if (prod > mod)
		{
			prod %= mod;
		}
	}
	return prod;
}

int main() {
	//code
	int t;
	cin >> t;
	while (t--)
	{
		long long n, y;
		cin >> n >> y;
		cout << power(n, y) << endl;
	}
	return 0;
}