#include <bits/stdc++.h>

using namespace std;
using ll = long long;

float square_root(int n, int p)
{
	int s = 0, e = n;
	float ans;
	while (s <= e)
	{
		int mid = (s + e) / 2;
		if (mid * mid == n)
			return mid;
		if (mid * mid < n)
		{
			ans = mid;
			s = mid + 1;
		}
		else
			e = mid - 1;
	}
	float inc = 0.1;
	for (int i = 1; i <= p; i++)
	{
		while (ans * ans <= n)//as precision lies between 0 to 9 so linear search otherwise we can also do binary search to find value for each precision
			ans += inc;//until the decimal number becomes equal to n
		ans -= inc;//one step back
		inc /= (10.0);
	}
	return ans;

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
		int n, p;
		cin >> n >> p; //p is for precision
		float ans = square_root(n, p);
		printf("%f\n", ans);
	}



	return 0;
}