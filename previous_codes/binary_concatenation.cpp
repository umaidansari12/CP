
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

ll BinaryConcatenation(vector<int> a)
{
	ll ans = 0;
	int x = *max_element(a.begin(), a.end());
	int y = *min_element(a.begin(), a.end());
	string binX, binY;
	while (x > 0)
	{
		binX.push_back(x % 2);
		x = x >> 1;
	}
	while (y > 0)
	{
		binY.push_back(y % 2);
		y = y >> 1;
	}
	string binXplusY, binYplusX;
	binXplusY = binX + binY;
	binYplusX = binY + binX;
	ll XplusY = 0, YplusX = 0;
	int n = binXplusY.size();
	for (int i = 0; i < n; i++)
	{
		XplusY += ((ll)binXplusY[i] * pow(2, n - i - 1));
	}
	int m = binYplusX.size();
	for (int i = 0; i < m; i++)
	{
		YplusX += ((ll)binYplusX[i] * pow(2, m - i - 1));
	}
	ans = max(ans, XplusY - YplusX);

	return ans;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	// cin.ignore(); must be there when using getline(cin, s)
	while (T--)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		cout << BinaryConcatenation(a) << endl;
	}
	return 0;
}
