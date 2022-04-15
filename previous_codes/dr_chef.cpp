#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		ll n, x;
		cin >> n >> x;
		vector <ll> a(n);
		for (ll i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		ll c = 0;
		for (ll i = 0; i < n; i++)
		{
			if (x < a[i])
			{
				while (x < a[i])
				{
					x = x * 2;
					c++;
				}
				c++;
				x = 2 * a[i];
			}
			else
			{
				if (a[i] > x / 2)
				{
					x = 2 * a[i];
					c++;
				}
				else
				{
					c++;
				}

			}
		}

		cout << c << endl;

	}


	return 0;
}
/*#include<bits/stdc++.h>
#define int      long long int
#define nitro    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define pb       push_back
#define pi       3.1415926535897932384626
#define mod      1000000007
#define endl     '\n'
#define DEBUG    false
#define F        first
#define S        second
#pragma GCC optimize "trapv"

using namespace std;

int32_t main()
{
	nitro;
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
	int t;
	cin >> t;
	while (t--)
	{
		int n, x;
		cin >> n >> x;
		vector<int> v(n);
		for (int& i : v)
			cin >> i;
		sort(v.begin(), v.end());
		vector<int>::iterator it = lower_bound(v.begin(), v.end(), x);
		int lb = it - v.begin();
		int d = 0;
		for (int i = lb; i < n; i++)
		{
			if (x < v[i])
			{
				while (x < v[i])
				{
					x = 2 * x;
					d++;
				}
				d++;
			}
			else
				d++;
			x = 2 * v[i];
		}
		int tot = lb + d;
		if (lb != 0)
		{
			d = 0;
			lb--;
			for (int i = lb; i < n; i++)
			{
				if (x < v[i])
				{
					while (x < v[i])
					{
						x = 2 * x;
						d++;
					}
					d++;
				}
				else
					d++;
				x = 2 * v[i];
			}
			int ans = min(d + lb, tot);
			cout << ans << endl;
		}
		else
			cout << tot << endl;
	}
	return 0;
}*/