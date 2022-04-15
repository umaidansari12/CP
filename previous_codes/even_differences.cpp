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
		long long int n;
		cin >> n;
		vector<long long int> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		long long int op = 0;
		//sort(v.begin(), v.end());
		while (true)
		{
			bool f = true;
			//cout << v[0] << " ";
			for (int i = 1; i < n - 1; i++)
			{
				while ((v[i] - v[i - 1]) % 2 != 0 && (v[i + 1] - v[i]) % 2 != 0)
				{
					f = false;
					if (v[i] > v[i - 1])
						v[i]++;
					else
						v[i - 1]++;
					op++;
				}
				//cout << v[i] << " ";
			}
			//cout << v[n - 1] << endl;
			if (f)
				break;
		}
		cout << op << endl;
	}
	return 0;
}
