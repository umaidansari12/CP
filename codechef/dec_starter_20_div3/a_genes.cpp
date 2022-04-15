#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t = 1;
	//cin >> t;
	while (t--) {
		char a, b;
		cin >> a >> b;
		map<char, int> m;
		m['R'] = 1;
		m['B'] = 2;
		m['G'] = 3;
		if (m[a] <= m[b])
			cout << a << endl;
		else
			cout << b << endl;
	}

	return 0;
}