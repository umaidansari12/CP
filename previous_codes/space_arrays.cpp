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
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		bool flag = false;
		int diff = 0, lasti = 0;
		sort(a.begin(), a.end());
		for (int i = 0; i < n; i++)
		{
			if (a[i] <= (i + 1))
			{
				lasti = i;
				diff += ((i + 1) - a[i]);
			}
			else
				break;
		}
		if (lasti < n - 1 || diff % 2 == 0)
			cout << "Second\n";
		else
			cout << "First\n";
		/*for (int i = 0; i < n; i++)
		{
			if (a[i] > (i + 1))
			{
				flag = true;
				break;
			}
			diff += (abs(a[i] - (i + 1)));
		}
		if (flag == false && diff % 2 == 0)
			cout << "Second\n";
		else if (flag == false && diff % 2 != 0)
			cout << "First\n";
		else if (flag == true)
			cout << "Second\n";*/

	}
	return 0;
}

