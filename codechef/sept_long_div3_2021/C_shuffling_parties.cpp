#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve1() {
	int n, x;
	cin >> n;
	vector<long long int> even, odd;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x % 2 == 0)
			even.push_back(x);
		else
			odd.push_back(x);
	}
	// for (auto i : even)
	// 	cout << i << " ";
	// cout << endl;
	// for (auto i : odd)
	// 	cout << i << " ";
	// cout << endl;
	// if (even.size() == odd.size())
	// 	cout << n << endl;
	// else
	// 	cout << n - (abs((int)even.size() - (int)odd.size())) << endl;
	long long int sum = 0;
	int even_idx = 0, odd_idx = 0, idx = 1;
	bool f = true;
	while (even_idx < even.size() and odd_idx < odd.size()) {
		if ((idx % 2) != 0)
		{
			//if (even_idx < even.size())
			sum = sum + ((even[even_idx] + idx) % 2);
			even_idx++;
			idx++;
		}
		else
		{
			sum = sum + ((odd[odd_idx] + idx) % 2);
			odd_idx++;
			idx++;
		}
	}
	while (odd_idx < odd.size())
	{
		sum = sum + ((odd[odd_idx] + idx) % 2);
		odd_idx++;
		idx++;
	}
	while (even_idx < even.size())
	{
		sum = sum + ((even[even_idx] + idx) % 2);
		even_idx++;
		idx++;
	}

	cout << sum << endl;
}

void solve() {
	int n, x, even = 0, odd = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x % 2 == 0)
			even++;
		else
			odd++;
	}
	int count1 = min(odd, (n / 2));
	int count2 = min(even, ((n + 1) / 2));
	cout << count1 + count2 << endl;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		solve();

	}


	return 0;
}