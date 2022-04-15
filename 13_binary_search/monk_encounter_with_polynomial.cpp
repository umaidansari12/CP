#include <bits/stdc++.h>

using namespace std;
using ll = long long;

long long getPolynomial(long long int a, long long int b, long long int c, long long int x)
{
	long long int ans = (a * x * x) + (b * x) + c;
	return ans;
}


int solveLinearSearch()
{
	ll a, b, c;
	ll k;
	cin >> a >> b >> c >> k;
	for (int i = 0; i <= 100000000; i++)
	{
		if (getPolynomial(a, b, c, i) >= k)
			return i;
	}
	return 0;
}

int solveBinarySearch()
{
	ll a, b, c, k;
	cin >> a >> b >> c >> k;
	ll low = 0, high = 100000, mid;
	long long int ans1 = 0, res = 0, ans2;
	// while (high - low > 1)
	// {
	// 	mid = (low + high) / 2;
	// 	if (((a * mid * mid) + (b * mid) + c) >= k)
	// 		high = mid;
	// 	else
	// 	{
	// 		low = mid + 1;
	// 	}
	// }
	// if ((a * low * low + b * low + c) >= k)
	// 	return low;
	// else
	// 	return high;


	// my first approach
	while (low <= high)
	{
		mid = (low + high) / 2;
		//cout << mid << endl;
		ans1 = getPolynomial(a, b, c, mid);//F(mid)
		//ans2 = getPolynomial(a, b, c, mid - 1);//F(mid-1)
		//cout << mid << " " << ans << endl;
		if (ans >= k)
		{
			res = mid;
			high = mid - 1;
		}
		else if (ans < k)
			low = mid + 1;
	}
	return res;



	// if(c>=k) return 0;
	// low = 1;
	//high = ceil(sqrt(k));
	// while (low <= high)
	// {
	// 	mid = (low + high) / 2;
	// 	ans1 = getPolynomial(a, b, c, mid);//F(mid)
	// 	ans2 = getPolynomial(a, b, c, mid - 1);//F(mid-1)
	// 	if (ans1 >= k and ans2 < k)
	// 	{
	// 		return mid;
	// 	}
	// 	else if (ans1 < k)
	// 		low = mid + 1;
	// 	else
	// 		high = mid - 1;
	// }
	// return res;
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
		cout << solveBinarySearch() << '\n';

	}


	return 0;
}