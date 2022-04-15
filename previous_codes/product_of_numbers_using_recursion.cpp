#include <bits/stdc++.h>

using namespace std;
using ll = long long;

long long int product(vector<int> a, int idx, int n)
{
	if (idx == n)
		return 1;
	return a[idx] * product(a, idx + 1, n);
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << product(a, 0, n);


	return 0;
}