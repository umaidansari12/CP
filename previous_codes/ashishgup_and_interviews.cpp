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
int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	// cin.ignore(); must be there when using getline(cin, s)
	while (T--)
	{
		long long int n, k;
		cin >> n >> k;
		vector<long long int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int solved = 0, sk = 0;
		float nn = (float)n / 2;
		int p = (ceil(nn));
		int cnt1 = count(a.begin(), a.end(), 1);
		int cnt0 = count(a.begin(), a.end(), 0);
		for (int i = 0; i < n; i++)
		{
			if (a[i] >= 0)
				solved++;
			if (a[i] > k)
				sk++;

		}
		cout << solved << " " << p << " " << sk << " " << nn << endl;
		bool t = false, b = false;
		if (solved < p && sk >= 1)
		{
			cout << "Too Slow\n";
		}
		else if (solved < p)
		{
			cout << "Rejected\n";
		}
		else if ((cnt1 + cnt0) == n)
		{
			cout << "Bot\n";
		}
		else
		{
			cout << "Accepted\n";
		}
		if (r == false && )

		}
	return 0;
}
