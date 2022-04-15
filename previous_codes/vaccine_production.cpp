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
		int d1, d2, v1, v2, p, day = 0;
		cin >> d1 >> v1 >> d2 >> v2 >> p;
		if (d1 == d2)
		{
			day += d1 - 1;
			if (p % (v1 + v2) == 0)
			{
				cout << day + p / (v1 + v2) << endl;
			}
			else
			{
				cout << day + (p / (v1 + v2)) + 1 << endl;
			}
		}
		else
		{

			if (d1 < d2)
			{
				day += d1 - 1;
				p = (p - ((d2 - d1) * v1));
				day += (d2 - d1);
			}
			else if (d2 < d1)
			{
				day += d2 - 1;
				p = (p - ((d1 - d2) * v2));
				day += (d1 - d2);
			}
			if (p <= 0)
				cout << day << endl;
			if (p % (v1 + v2) == 0 && p > 0)
			{
				cout << day + p / (v1 + v2) << endl;
			}
			else if (p % (v1 + v2) != 0 && p > 0)
			{
				cout << day + (p / (v1 + v2)) + 1 << endl;
			}


		}
	}
	return 0;
}


#include <bits/stdc++.h>
using namespace std;

int main()
{

	int D1, V1, D2, V2, P;
	cin >> D1 >> V1 >> D2 >> V2 >> P;

	if (D1 > D2)
	{
		swap(D1, D2);
		swap(V1, V2);
	}

	int d = (P / V1) + (P % V1 > 0) + D1 - 1;

	if (d < D2)
		cout << d << endl;
	else
	{
		int num = P + (D1 - 1) * V1 + (D2 - 1) * V2;
		int den = V1 + V2;
		d = (num / den) + (num % den > 0);
		cout << d << endl;
	}

	return 0;