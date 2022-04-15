#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void processString(int n, string strs) {
	reverse(strs.begin(), strs.begin() + n);
	reverse(strs.end() - n, strs.end());
	cout << strs << endl;


}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string str;
		cin >> str;
		processString(n, str);
	}


	return 0;
}