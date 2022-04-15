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

/*string orthodoxDistinction(vector<ll> a, int n)
{
	map<ll, int> m;
	//sort(a.begin(), a.end());
	//int c = a[n - 1];
	for (int i = 1; i < n ; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			ll o = 0;
			for (int k = j; k < j + i; k++)
			{
				o = o | a[k];
			}
			m[o]++;
		}
	}
	for (auto i : m)
	{
		if (i.second > 1 && i.second % 2 == 1)
			return "NO";
	}

	return "YES";
}

*/
string orthodoxDistinction(vector<ll> a, int n)
{
	if (n > 60)
		return "NO";
	set<ll> s;
	bool flag = true;
	for (int i = 0; i < n; i++)
	{

		ll cur = 0;
		for (int j = i; j < n; j++)
		{
			cur |= a[j];
			if (s.find(cur) != s.end())
			{
				flag = false;
				break;
			}
			s.insert(cur);
		}
		if (!flag)
			break;
	}
	if (flag)
		return "YES";
	return "NO";

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
		vector <ll> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		cout << orthodoxDistinction(a, n) << endl;
	}
	return 0;
}
