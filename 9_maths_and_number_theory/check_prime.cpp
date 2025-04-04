#include<iostream>
using namespace std;

int main() {
	// Write your code here
	int n, cnt = 0;
	cin >> n;
	// O(N) -> the numbers which has exactly 2 factors are known as prime numbers.
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			cnt++;
		}
	}
	if (cnt == 2) {
		cout << "true";
	}
	else {
		cout << "false";
	}

}


int main_2() {
	// Write your code here
	int n, cnt = 0;
	cin >> n;

	// O(sqrt(N)) -> counting all factors
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			cnt++;
			if ((n / i) != i) {
				cnt++;
			}
		}
	}
	if (cnt == 2) {
		cout << "true";
	}
	else {
		cout << "false";
	}

}
