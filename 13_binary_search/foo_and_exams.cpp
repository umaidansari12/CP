#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll a, b, c, d, k;

ll F(ll mid, ll a, ll b, ll c, ll d)
{
	return (a * mid * mid * mid) + (b * mid * mid) + (c * mid) + d;
}

ll BSearch1(ll a, ll b, ll c, ll d, ll k)
{
	ll low = 0 , high = ceil(sqrt(k)), ans = 0, mid;
	high = 799000;
	//since ((10^6)^3) = 10^18

	//so upperbound for high is 10^6
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		ll F1 = F(mid, a, b, c, d);
		ll F2 = F(mid + 1, a, b, c, d);
		if (F1 <= k and F2 > k)
		{
			return mid;
			// ans = mid;
			// low = mid + 1;
		}
		else if (F1 <= k)
			low = mid + 1;
		else if (F1 > k)
			high = mid - 1;
	}
	return ans;
}

#include <bits/stdc++.h>

using namespace std;
#define ll unsigned long long int

ll a, b, c, d, k;

ll F(ll mid, ll a, ll b, ll c, ll d)
{
	return (a * mid * mid * mid) + (b * mid * mid) + (c * mid) + d;
}


int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> a >> b >> c >> d >> k;
		if (d >= k)
			cout << "0\n";
		else
		{
			ll low = 0 , high = 1000000, ans = 0, mid;
			while (low <= high)
			{
				mid = low + (high - low) / 2;
				ll F1 = F(mid, a, b, c, d);
				ll F2 = F(mid + 1, a, b, c, d);
				if (F1 <= k and F2 > k)
				{
					ans = mid;
					break;
				}
				else if (F1 <= k)
					low = mid + 1;
				else
					high = mid - 1;
			}
			cout << ans << '\n';
		}

	}


	return 0;
}
#include <bits/stdc++.h>

using namespace std;
#define ll unsigned long long int

ll a, b, c, d, k;

ll F(ll mid, ll a, ll b, ll c, ll d)
{
	return (a * mid * mid * mid) + (b * mid * mid) + (c * mid) + d;
}


int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> a >> b >> c >> d >> k;
		if (d >= k)
			cout << "0\n";
		else
		{
			ll low = 0 , high = ceil(cbrt(k)) + 1, ans = 0, mid;
			while (low <= high)
			{
				mid = low + (high - low) / 2;
				ll F1 = F(mid, a, b, c, d);
				ll F2 = F(mid + 1, a, b, c, d);
				if (F1 <= k and F2 > k)
				{
					ans = mid;
					break;
				}
				else if (F1 <= k)
					low = mid + 1;
				else
					high = mid - 1;
			}
			cout << ans << '\n';
		}

	}


	return 0;
}

ll BSearch(ll a, ll b, ll c, ll d, ll k)
{
	ll low = 0 , high = ceil(sqrt(k)), ans = 0, mid;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		ll F1 = F(mid, a, b, c, d);
		//ll F2 = F(mid + 1, a, b, c, d);
		if (F1 <= k)
		{
			//return mid;
			ans = mid;
			low = mid + 1;
		}
		// else if (F1 < k)
		// 	low = mid + 1;
		else if (F1 > k)
			high = mid - 1;
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
		cin >> a >> b >> c >> d >> k;
		//cout << a << " " << b << " " << c << " " << d << " " << k << '\n';
		// ll low = 1, high = ceil(sqrt(k)), ans = 0;
		// for (ll i = low; i <= high; i++)
		// {
		// 	if (F(i + 1, a, b, c, d) > k and F(i, a, b, c, d) <= k)
		// 	{
		// 		ans = i;
		// 		break;
		// 	}
		// }
		// cout << ans << '\n';
		cout << BSearch(a, b, c, d, k) << '\n';
	}


	return 0;
}