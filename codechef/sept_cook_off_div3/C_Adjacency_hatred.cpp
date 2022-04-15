#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
	int n, x;
	cin >> n;
	vector<long long int> even, odd;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if ((x % 2) == 0)
			even.push_back(x);
		else
			odd.push_back(x);
	}
	if (even.size() == 0 or odd.size() == 0)
		cout << -1 << endl;
	else
	{
		sort(even.begin(), even.end());
		sort(odd.begin(), odd.end());
		for (auto i : odd)
			cout << i << " ";
		for (auto i : even)
			cout << i << " ";
		cout << endl;
	}

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
		// int n;
		// cin >> n;
		// vector<long long int> a(n), even, odd, temp(n, 0);
		// for (int i = 0; i < n; i++)
		// {
		// 	cin >> a[i];
		// 	if ((a[i] % (long long int)2) == 0)
		// 		even.push_back(a[i]);
		// 	else
		// 		odd.push_back(a[i]);
		// }
		// if (even.size() != odd.size())
		// 	cout << "-1\n";
		// else {
		// 	int i = 0, j = 0, k = 0, sum = 0;
		// 	sort(odd.begin(), odd.end());
		// 	sort(even.begin(), even.end());
		// 	for (int i = 0; i < n; i++) {
		// 		if ((i % 2) == 0)
		// 		{
		// 			if (k < odd.size())
		// 				temp[i] = odd[k++];
		// 			else //if (j < even.size())
		// 				temp[i] = even[j++];
		// 		}
		// 		else
		// 		{
		// 			if (j < even.size())
		// 				temp[i] = even[j++];
		// 			else //if (k < odd.size())
		// 			{
		// 				temp[i] = odd[k++];
		// 			}
		// 		}
		// 	}
		// 	for (int i = 0; i < (n - 1); i++) {
		// 		sum += abs(temp[i] - temp[i + 1]);
		// 	}
		// 	if ((sum % 2) == 0)
		// 		cout << "-1" << endl;
		// 	else
		// 	{
		// 		//cout << sum << endl;
		// 		for (auto i : temp)
		// 			cout << i << " ";
		// 		cout << endl;
		// 	}

	}


	return 0;
}