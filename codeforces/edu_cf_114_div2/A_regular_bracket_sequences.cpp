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
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int left = i;
			int right = n - i;
			int count = left;
			while (count--) {
				cout << "(";
			}
			count = left;
			while (count--) {
				cout << ")";
			}
			count = right;
			while (count--) {
				cout << "(";
			}
			count = right;
			while (count--) {
				cout << ")";
			}
			cout << endl;
		}
	}


	return 0;
}