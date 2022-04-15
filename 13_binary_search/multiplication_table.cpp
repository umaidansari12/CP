#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// codeforces 256 div2 d problem

// binary search brute force 1800

/*
    i|                  | elements < x    |
    1|1 2 3  4  5  6 ...|(x-1)/1       |
    2|2 4 6  8 10 12 ...|(x-1)/2     |
    3|3 6 9 12 15 18 ...|(x-1)/3    |
    . . .
    Let f(x) the number of elements on the multiplication table that are less than x.
    f can be compute by iterating each row and check how many numbers are less than x,
    that is (x-1)/i, but you have to remember that you only have m columns,
    so you take min(m,(x-1)/i). With binary search we want to find largest x so that f(x) < k.
*/

///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1


ll n, m, k;

ll isValid(ll mid)
{
	ll res = 0;
	for (int i = 1; i <= n; i++)
	{
		res += min(m, (mid - 1) / i);
	}
	return res;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// int t;
	// cin >> t;
	// while (t--)
	// {
	cin >> n >> m >> k;

	ll low = 1 , high = ((ll)n * (ll)m), mid, res = -1;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		ll ans = isValid(mid);
		if (ans < k)
		{
			res = max(res, mid);
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	cout << res << endl;
	// vector<ll> a;
	// for (int i = 1; i <= n; i++)
	// {
	// 	for (int j = 1; j <= m; j++)
	// 		a.push_back(i * j);
	// }
	// sort(a.begin(), a.end());
	// cout << a[k - 1] << '\n';
	// }



	return 0;
}