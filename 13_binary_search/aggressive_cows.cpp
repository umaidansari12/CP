#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define INF 1000000000

void solve(ll *a, ll n, ll c, ll idx, vector<ll> &r, ll &res)
{
	if (idx == n and r.size() == c)
	{
		ll min_dist = LLONG_MAX;
		for (int i = 0; i < r.size() - 1; i++)
		{
			min_dist = min(min_dist, abs(r[i + 1] - r[i]));
		}
		if (min_dist != LLONG_MAX)
			res = max(res, min_dist);
		return;
	}
	if (idx >= n)
		return;

	if (r.size() == 0 or r.back() <= a[idx])
	{
		r.push_back(a[idx]);
		solve(a, n, c , idx + 1, r, res);
		r.pop_back();
	}
	solve(a, n, c, idx + 1, r, res);
}

bool isValid(ll *a, ll mid, ll c, ll n)
{
	ll prev = -INF;
	ll cnt = 0;
	for (ll i = 0; i < n; i++)
	{
		if (a[i] - prev >= mid)
		{
			prev = a[i];
			cnt++;
		}
	}
	return cnt >= c;
}

ll BSearch(ll *a, ll n, ll c)
{
	ll low = 0, high = a[n - 1] - a[0], mid, ans = 0; // as given in the constraints array contains atleast 2 elements so we will take maximum height diff of first element and last element
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (isValid(a, mid, c, n))
		{
			ans = max(ans, mid);
			low = mid + 1;
		}
		else
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
		ll n, c;
		cin >> n >> c;
		ll a[n] = {0};
		for (ll i = 0; i < n; i++)
			cin >> a[i];
		ll res = 0;
		vector<ll> r;
		sort(a, a + n);
		//solve(a, n, c, 0, r, res);
		cout << BSearch(a, n, c) << endl;
		//cout << res << endl;

	}

	return 0;
}