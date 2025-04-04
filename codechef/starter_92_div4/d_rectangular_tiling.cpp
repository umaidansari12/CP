#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		long long int w, l;
		cin >> w >> l;
		// long long int w1 = w, w2 = 0, p1 = 0, p2 = 0;
		// bool flag = false;
		// 5 - 5 4 3 2 1 0
		// 	0 1 2 3 4 5
		// 	5/2 - 0 1 2 == w/2
		// 6 - 6 5 4 3 2 1 0
		// 	0 1 2 3 4 5 6
		// 	0 1 2 3

		// for (int i = 0; i <= (w / 2); i++) {
		// 	w1 = i;
		// 	w2 = w - i;
		// 	p1 = (2 * w1 + 2 * l);
		// 	if (w2 != 0)
		// 		p2 = 2 * w2 + 2 * l;
		// 	else
		// 		p2 = 0;
		// 	// cout << w1 << " " << w2 << " " << p1 << " " << p2 << endl;
		// 	if (p1 % 4 != 0 and p2 != 0 and p2 % 4 != 0) {
		// 		cout << "YES\n";
		// 		flag = true;
		// 		break;
		// 	}
		// }
		// if (!flag)
		// 	cout << "NO\n";
		if ((w * l) % 2 == 0)
			cout << "YES\n";
		else
			cout << "NO\n";

		// Perimeter formula is 2*(l+b). Perimeter will be divisible by 4 when (l+b) is even. l+b can be even when both the numbers are odd or both are even. If both are even then they can be converted to on odd and even pair. But if l and b both are Odd then we can not convert them. So print No if both are odd else in all cases it possible so print YES.
	}

}