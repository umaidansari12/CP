#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*
1
9 4
2 8 -1 -1 -1 13 -1 15 20
5 7 9 25
*/

void move(int a[], int size) {
	int j = size - 1;
	for (int i = size - 1; i >= 0; i--) {
		if (a[i] != -1) {
			a[j] = a[i];
			j--;
		}
	}
	// for (int i = 0; i < size; i++) {
	// 	if (a[i] == -1)
	// 		break;
	// 	a[i] = -1;
	// }
}
void merge(int a[], int n, int b[], int m) {
	int i = n, j = 0, k = 0;
	while (k < (n + m)) {
		if ((j == n) or (i < (n + m) and a[i] <= b[j])) {
			a[k] = a[i];
			i++;
			k++;
		}
		else {
			a[k] = b[j];
			j++;
			k++;
		}
	}
}

void display(int a[], int size) {
	for (int i = 0; i < size; i++)
		cout << a[i] << " ";
	cout << endl;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int mplusn, m, n;
		cin >> mplusn >> m;
		n = mplusn - m;
		int a[mplusn] = {0}, b[m] = {0};
		for (int i = 0; i < mplusn; i++ ) {
			cin >> a[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> b[i];
		}
		// Let first array be mPlusN[] and other array be N[]
		// 1) Move m elements of mPlusN[] to end.
		// 2) Start from nth element of mPlusN[] and 0th
		// element of N[] and merge them into mPlusN[].
		move(a, n + m);
		display(a, n + m);
		merge(a, n, b, m);
		display(a, n + m);
	}

	return 0;
}