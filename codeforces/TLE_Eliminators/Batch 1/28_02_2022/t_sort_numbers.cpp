#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	//cin>>t;
	while (t--) {
		// int a[3] = {0}, b[3] = {0};
		// for (int i = 0; i < 3; i++) {
		// 	cin >> a[i];
		// 	b[i] = a[i];
		// }

		// sort(a, a + 3);

		// for (int i = 0; i < 3; i++) {
		// 	cout << a[i] << "\n";
		// }
		// cout << endl;
		// for (int i = 0; i < 3; i++) {
		// 	cout << b[i] << "\n";
		// }
		int a, b, c;
		cin >> a >> b >> c;
		if (a <= b and a <= c) {
			cout << a << "\n";
			if (b <= c) {
				cout << b << "\n" << c << endl;
			}
			else if (c <= b) {
				cout << c << "\n" << b << endl;
			}
		}
		else if (b <= a and b <= c) {
			cout << b << "\n";
			if (a <= c) {
				cout << a << "\n" << c << endl;
			}
			else if (c <= a) {
				cout << c << "\n" << a << endl;
			}
		}
		else if (c <= b and c <= a) {
			cout << c << "\n";
			if (b <= a) {
				cout << b << "\n" << a << endl;
			}
			else if (a <= b) {
				cout << a << "\n" << b << endl;
			}
		}

		cout << "\n" << a << "\n" << b << "\n" << c << endl;
	}


	return 0;
}