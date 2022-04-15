#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	while (t--) {
		int n;
		cin >> n;
		int a[n], b[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
			cin >> b[i];
		sort(a, a + n);
		sort(b, b + n);
		long long int max_score = 0, min_score = 0, another_score = 0;
		for (int i = 0, j = n - 1; i < n and j >= 0; i++, j--) {
			max_score += (a[i] * b[i]);
			//min_score += (a[i] * b[j]);
			min_score += (a[i] * b[n - i - 1]);
		}
		cout << min_score << " " << max_score << endl;
	}


	return 0;
}