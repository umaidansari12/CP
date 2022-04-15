#include <bits/stdc++.h>

using namespace std;
using ll = long long;

char SmallestCharacter(char* s) {
	int size = sizeof(s) / sizeof(char);
	int count[26] = {0};

	for (int i = 0; s[i] != '\0'; i++) {
		count[s[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		if (count[i] == 0) {
			return i + 'a';
		}
	}

	return 'a';
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		char s[100];
		cin >> s;
		cout << char(SmallestCharacter(s)) << endl;
		fflush(stdin);
	}


	return 0;
}