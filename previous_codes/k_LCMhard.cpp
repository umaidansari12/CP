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

vector <int> solve(int n)
{
	if (n % 2)
		return {1, n / 2, n / 2};
	else if ((n % 2) == 0 && (n % 4))
		return {2, n / 2 - 1, n / 2 - 1};
	else
		return {n / 2, n / 4, n / 4};
}


int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	// cin.ignore(); must be there when using getline(cin, s)
	while (T--)
	{
		int n, k;
		cin >> n >> k;
		vector<int> a = solve(n - k + 3);
		for (int i = 0; i < k; i++)
		{
			cout << (i < 3 ? a[i] : 1) << " ";
		}
		cout << endl;


	}
	return 0;
}
