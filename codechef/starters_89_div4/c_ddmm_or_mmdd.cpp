#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		int date = 10 * (s[0] - '0') + (s[1] - '0');
		int month = 10 * (s[3] - '0') + (s[4] - '0');
		// cout << date << " " << month << endl;
		if (date > 12)
			cout << "DD/MM/YYYY\n";
		else if (month > 12)
			cout << "MM/DD/YYYY\n";
		else
			cout << "BOTH\n";
	}
}