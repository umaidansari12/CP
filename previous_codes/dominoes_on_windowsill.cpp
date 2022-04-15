#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>wakatime
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
		int n, k1, k2, w, b;
		cin >> n >> k1 >> k2 >> w >> b;
		if ((w + b) == 0)
		{
			cout << "YES\n";
			continue;
		}
		vector<vector<int>> a(2, vector<int>(n, 1));
		for (int i = 0; i < k1; i++)
		{
			a[0][i] = 0;
		}
		for (int i = 0; i < k2; i++)
			a[1][i] = 0;
		/*for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < n; j++)
				cout << a[i][j] << " ";
			cout << endl;
		}*/
		for (int i = 0; i < n; i++)
		{
			if (a[0][i] == 0 && a[1][i] == 0)
			{
				a[0][i] = a[1][i] = -1;
				w--;
				//w = max(0, w--);
			}
			else if ((i + 1 < n) && (a[0][i] == 0 && a[0][i + 1] == 0))
			{
				a[0][i] = a[0][i + 1] = -1;
				w--;
				//w = max(0, w--);
			}
			else if ((i + 1 < n) && (a[1][i] == 0 && a[1][i + 1] == 0))
			{
				a[1][i] = a[1][i + 1] = -1;
				w--;
				//w = max(0, w--);
			}
			if (a[0][i] == 1 && a[1][i] == 1)
			{
				a[0][i] = a[1][i] = -1;
				b--;
				//b = max(0, b--);
			}
			else if ((i + 1 < n) && (a[0][i] == 1 && a[0][i + 1] == 1))
			{
				a[0][i] = a[0][i + 1] = -1;
				b--;
				//b = max(0, b--);
			}
			else if ((i + 1 < n) && (a[1][i] == 1 && a[1][i + 1] == 1))
			{
				a[1][i] = a[1][i + 1] = -1;
				b--;
				//b = max(0, b--);
			}
		}
		//cout << w << " " << b << endl;
		if ((w + b) == 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		/*for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < n; j++)
				cout << a[i][j] << " ";
			cout << endl;
		}*/
		//cout << endl;
	}
	return 0;
}
