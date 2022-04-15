#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool validCoupon(string s) {

	if (s.size() % 2 == 1)
		return false;

	stack<char> stk;
	for (auto ch : s) {
		if (!stk.empty() and stk.top() == ch) {
			stk.pop();
		}
		else {
			stk.push(ch);
		}
	}

	return stk.empty();

}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin >> tc;
	while (tc--) {
		string s;
		cin >> s;
		if (validCoupon(s))
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}