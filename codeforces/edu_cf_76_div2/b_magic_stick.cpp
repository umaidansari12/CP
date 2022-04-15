#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*1 cannot be transformed into any other number. 2 can be transformed into 3 or 1, and 3 can be transformed only into 2. It means that if x=1, then only y=1 is reachable; and if x=2 or x=3, then y should be less than 4.

Otherwise, we can make x as large as we want, so if x>3, any y is reachable.*/

string solve(ll x, ll y) {
	if (x >= y) {
		return "YES";
	}
	else {
		if (x % 2 == 0 and x >= 1) {
			ll a = 3 * x;
			a /= 2;
			if (a % 2 == 1 and a >= x) {
				return "YES";
			}
			else {
				return "NO";
			}
		}
		else if (x % 2 == 1 and x >= 1) {
			ll y = x;
			x--;
			ll a = 3 * x;
			a /= 2;
			if (a % 2 == 1 and a >= y) {
				return "YES";
			}
			else {
				return "NO";
			}
		}
	}

	return "NO";
}

string solve1(ll x, ll y) {
	if (x > 3)
		return "YES";
	else if (x == 1) {
		if (y == 1)
			return "YES";
		else
			return "NO";
	}
	else if (y <= 3)
		return "YES";
	return "NO";
}


int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		ll x, y;

		cin >> x >> y;
		cout << solve1(x, y) << endl;
	}


	return 0;
}