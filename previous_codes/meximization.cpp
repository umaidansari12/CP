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
		int n;
		cin >> n;
		vector<int> a(n);
		map<int, int> m;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			m[a[i]]++;
		}
		//sort(a.begin(), a.end());
		for (auto i : m)
		{
			cout << i.first << " ";
			i.second--;
		}
		for (auto i : m)
		{
			while (--i.second)
				cout << i.first << " ";
		}
		cout << endl;
		/*int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];
		sort(a.begin(), a.end());
		vector<int> b;
		for (int i = 0; i < n; i++) {
		    if (i == 0 || a[i] != a[i - 1]) {
		        b.emplace_back(a[i]);
		    }
		}
		for (int i = 0; i < n; i++) {
		    if (i > 0 && a[i] == a[i - 1]) {
		        b.emplace_back(a[i]);
		    }
		}
		for (auto x : b) cout << x << ' ';
		cout << '\n';*/
	}
	return 0;
}
