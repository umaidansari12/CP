#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, anton = 0, danik = 0;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'A')
			anton++;
		else if (s[i] == 'D')
			danik++;
	}

	if (anton > danik) {
		cout << "Anton\n";
	}
	else if (anton < danik) {
		cout << "Danik\n";
	}
	else if (anton == danik) {
		cout << "Friendship\n";
	}



	return 0;
}