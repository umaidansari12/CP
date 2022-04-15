#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second

using namespace std;

void solve()
{
	int n;
	long long int ans = INT_MIN;
	cin >> n;
	vector<long long int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	unordered_map<int, int> count;
	for (int i = 0; i < n; i++)
	{
		long long int sum = 0;
		for (int j = i; j < n; j++)
		{
			sum += a[j];
			count[sum]++;
		}
	}
	for (auto i : count)
	{
		cout << i.first << " " << i.second << endl;
		ans = max(ans, (long long int)i.first * (long long int)count[i.first]);
	}
	cout << ans << endl;
	cout << endl;
}

int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	// cin.ignore(); must be there when using getline(cin, s)
	while (T--)
	{
		solve();
	}
	return 0;
}
