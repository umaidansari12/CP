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
		string S, T;
		cin >> S >> T;

		int i = 0;

		for (i = 0; i < min(S.size(), T.size()); i++) {
			cout << S[i] << T[i];
		}

		for (; i < max(S.size(), T.size()); i++) {
			if (i < S.size())
				cout << S[i];
			else
				cout << T[i];
		}
		cout << endl;
	}



	return 0;
}