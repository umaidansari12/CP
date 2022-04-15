#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<long long int> solveEven(long long int amount) {
	long long int two = 0, one = 0;
	two = amount / 2;
	one = amount % 2;
	long long int ans1 = one, ans2 = two, diff = INT_MAX;
	while (one <= two) {
		int current_diff = two - one;
		if (diff > current_diff)
		{
			diff = current_diff;
			ans1 = one;
			ans2 = two;
		}
		two--;
		one += 2;
	}
	// cout << ans1 << " " << ans2 << endl;
	return {ans1 + ans2, ans1, ans2};
}

vector<long long int> solveOdd(long long int amount) {
	long long int two = 0, one = amount;
	long long int ans1 = one, ans2 = two, diff = INT_MAX;
	while (one >= two) {
		int current_diff = one - two;
		if (diff > current_diff)
		{
			diff = current_diff;
			ans1 = one;
			ans2 = two;
		}
		two++;
		one -= 2;
	}
	// cout << ans1 << " " << ans2 << endl;
	return {ans1 + ans2, ans1, ans2};
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		long long int amount = 0;
		cin >> amount;
		vector<long long int> odd = solveOdd(amount);
		vector<long long int> even = solveEven(amount);
		if (abs(even[1] - even[2]) < abs(odd[1] - odd[2]))
			cout << even[0];
		else
			cout << odd[0];
		cout << endl;
		//cout << min(solveOdd(amount), solveEven(amount)) << endl;
	}


	return 0;
}