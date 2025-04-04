#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		long long int n, k;
		cin >> n >> k;
		// long long int number_of_elements_in_single_partition = n - (k - 1LL) * 2LL;
		// long long int pairs = number_of_elements_in_single_partition / 2 + number_of_elements_in_single_partition % 2;
		// if (pairs % 2 == 0)
		// 	cout << "NO\n";
		// else
		// 	cout << "YES\n";


		// cout << partition << endl;
		// if (number_of_elements_in_single_partition % 2 == 0) {
		// 	// partition = partition / 2;
		// 	// // cout << partition << endl;
		// 	// if (partition % 2 != 0)
		// 	// 	cout << "YES\n";
		// 	// else
		// 	// 	cout << "NO\n";
		// }
		// else
		// 	cout << "NO\n";
		if (n < (2 * k)) {
			cout << "NO\n";
		}
		else {
			long long int odd_numbers = n / 2 + n % 2, even_numbers = n / 2;
			if ((odd_numbers - k) % 2 == 0)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}