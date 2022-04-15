#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int _size = s.size();
		if (_size <= 10) {
			cout << s << endl;
		}
		else {
			cout << s[0] << to_string(_size - 2) << s[_size - 1] << endl;
		}
	}


	return 0;
}