#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string solve2() {
	long long int a, b, p, q;
	cin >> a >> b >> p >> q;

	long long int _min = p / a; //min(p / (long long)a, q / (long long)b);
	long long int _max = q / b; //max(p / (long long)a, q / (long long)b);

	if (_max == _min or (_max - _min) % 2 == 1)
		return "YES";
	return "NO";
}

string solve1() {
	long long int a, b, p, q, x = 0, y = 0;
	cin >> a >> b >> p >> q;
	x = a, y = b;
	int _max = max(p / a, q / b);
	vector<long long int> odd, even;
	for (int i = 0; i < _max; i++) {
		odd.push_back(x);
		even.push_back(y);
		odd.push_back(y);
		even.push_back(x);
		x += a;
		y += b;
	}

	for (int i = 0; i < odd.size(); i++) {
		if ((odd[i] == p and odd[i + 1] == q) or (odd[i] == q and odd[i + 1] == p))
			return "YES";
	}

	for (int i = 0; i < even.size(); i++) {
		if ((even[i] == p and even[i + 1] == q) or (even[i] == q and even[i + 1] == p))
			return "YES";
	}
	return "NO";

}

string solve() {

	long long int a, b, p, q;
	cin >> a >> b >> p >> q;

	if ((p % a) == 0 and (q % b) == 0) {
		long long int _min = min(p / (long long)a, q / (long long)b);
		long long int _max = max(p / (long long)a, q / (long long)b);

		if (_max - _min <= 1)
			return "YES";
	}
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
		cout << solve() << endl;

	}


	return 0;
}
