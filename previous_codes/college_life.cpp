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
		int n, e, h, a, b, c, cost = 0;
		cin >> n >> e >> h >> a >> b >> c;
		bool fa = false, fb = false, fc = false;
		int t = 3;
		while (t--)
		{
			if ((a < b && a < c) && fa == false)
			{
				//cout << "A : " << e / 2 << " " << n << " ";
				n -= (e / 2);
				cost += ((e / 2) * a);
				e = e % 2;
				fa = true;
			}
			else if ((b < a && b < c) && fb == false)
			{
				n -= (h / 3);
				cost += ((h / 3) * b);
				h %= 3;
				fb = true;
			}
			else if ((c < a && c < b) && fc == false)
			{
				int d = min(min(h, e), n);
				n -= (d);
				cost += ((d) * c);
				h %= d;
				e %= d;
				fc = true;
			}
			if (n == 0)
				break;
			if (fa == true && fb == true && fc == true)
				break;
		}
		if (n > 0)
			/*cout << cost << endl;*/ cout << n << " " << -1 << endl;
		else
			cout << cost << endl;
	}
	return 0;
}
