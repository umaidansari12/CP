#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*strength of a password is defined as the sum of unique characters that are found in every possible every substring*/

long long int solve(string s) {
	long long int sum = 0;
	for (int i = 0; i < s.size(); i++) {
		map<char, int> m;
		for (int j = i; j < s.size(); j++) {
			m[s[j]]++;
			sum += m.size();
		}

	}
	return sum;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin	>> t;
	while (t--) {
		string s;
		cin >> s;

		cout << solve(s) << endl;
	}


	return 0;
}