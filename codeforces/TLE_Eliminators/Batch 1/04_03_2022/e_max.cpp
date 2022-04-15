#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long int n, _max = 0, x;
	cin >> n;
	for (long long int i = 0; i < n; i++) {
		cin >> x;
		_max = max(_max, x);
	}

	cout << _max << endl;


	return 0;
}