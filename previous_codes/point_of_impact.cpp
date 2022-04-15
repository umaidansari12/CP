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
		int n, k, x, y;
		cin >> n >> k >> x >> y;
		int diff1 = abs(x - y);
		if (diff1 == 0 || x == n && y == n)
		{
			if (diff1 == 0)
			{
				cout << n << " " << n << endl;
				continue;
			}
			cout << x << " " << y << endl;
		}
		else if (x > y)
		{
			long long xx = k % 4;
			long long diff = x - y;

			if (xx == 0)
			{
				cout << diff << " " << 0 << endl;
			}
			else if (xx == 1)
			{
				cout << n << " " << n - diff << endl;
			}
			else if (xx == 2)
			{
				cout << n - diff << " " << n << endl;
			}
			else
			{
				cout << 0 << " " << diff << endl;
			}
		}
		else
		{
			int xx = k % 4;
			int diff = y - x;
			if (xx == 0)
			{
				cout << 0 << " " << diff << endl;
			}
			else if (xx == 1)
			{
				cout << n - diff << " " << n << endl;
			}
			else if (xx == 2)
			{
				cout << n << " " << n - diff << endl;
			}
			else
			{
				cout << diff << " " << 0 << endl;
			}
		}
		/*vector<vector<int>> b(n + 1, vector<int>(n + 1, 0));
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				cout << b[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		int count = 0;
		int dir_x = 1, dir_y = 1;
		while (count != k)
		{
			if (x == 0 && y == 0)
				break;
			else if (x == 0 && y == n)
				break;
			else if (x == n && y == 0)
				break;
			else if (x == n && y == n)
				break;
			if (x == 0 || x == n)
				dir_x = (-1) * dir_x;
			if (y == 0 || y == n)
				dir_y = (-1) * dir_y;
			int steps = 0;
			if (dir_x == 1)
			{
				steps = n - x;
				if (dir_y == 1)
					y = (y + steps) % n;
				else
					y = (y - steps < 0) ? 0 : y - steps;
			}
			else if (dir_x < 1)
			{
				steps = n - y;
			}


			count++;
		}*/
	}
	return 0;
}
