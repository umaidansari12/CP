#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, server = 0, a = 0, b = 0;
		cin >> N;
		string s;
		cin >> s;
		for (int i = 0; i < N; i++) {
			if (server == 0 and s[i] == 'A')
				a++;
			else if (server == 1 and s[i] == 'B')
				b++;
			else
				server = 1 - server;
		}
		cout << a << " " << b << endl;
	}
}