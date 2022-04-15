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
		int n, checksum = 0, mi = 1e9;
		cin >> n;
		vector<int> a(n), b(n);
		map<int, int> m1, m2, m;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			//checksum ^= a[i];
			m[a[i]]++;
			m1[a[i]]++;
			mi = min(mi, a[i]);
		}
		for (int i = 0; i < n; i++)
		{
			cin >> b[i];
			//checksum ^= b[i];
			m2[b[i]]++;
			m[b[i]]--;
			mi = min(mi, b[i]);
		}
		//checksum is used to cancel all the occurences of element x if it occured even times
		/*if (checksum)
		{
			cout << -1 << endl;
			continue;
		}*/
		for (auto i : m)
		{
			if (i.second % 2 != 0)
			{
				cout << -1 << endl;
				checksum = 1;
				break;
			}

		}
		if (checksum)
		{
			continue;
		}
		vector <int> A, B;
		for (auto i : m1)
		{

			if (m2.find(i.first) != m2.end())
			{
				int dx = min(i.second, m2[i.first]);
				m1[i.first] -= dx;//removing the common elements from both maps
				m2[i.first] -= dx;
			}
		}
		for (auto i : m1)
		{
			for (int j = 0; j < (i.second) / 2; j++)
			{
				A.push_back(i.first);//transferring half of the elements in final array
			}
		}
		for (auto i : m2)
		{

			for (int j = 0; j < (i.second) / 2; j++)
			{
				B.push_back(i.first);
			}
		}
		int res = 0;
		reverse(B.begin(), B.end());
		for (int i = 0; i < A.size(); i++)
		{
			res += min(2 * mi, min(A[i], B[i]));
		}
		cout << res << endl;

	}
	return 0;
}
