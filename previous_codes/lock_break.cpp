#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void combinations(string &a, int idx, int n, string s)
{
	if (idx == n) {
		if (s.size() == 3) {
			cout << s << endl;
			return;
		}
	}
	combinations(a, idx + 1, n, s + a[idx]);
	combinations(a, idx + 1, n, s);
}
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string a = "0123456789";
	string s = "";
	combinations(a, 0, 10, s);


	return 0;
}