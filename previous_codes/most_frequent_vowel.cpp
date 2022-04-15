#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int count[26] = {0};
	for (int i = 0; i < n; i++) {
		if (s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u')
			count[s[i] - 'a']++;
	}
	int _max = 0, index = -1;
	char ans;
	for (int i = 0; i < 26; i++) {
		if (count[i] != 0 and count[i] > _max) {
			_max = count[i];
			ans = i + 'a';
		}
	}

	cout << ans << endl;


	return 0;
}