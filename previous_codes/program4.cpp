#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool isVowel(char ch) {
	if (ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u' or ch == 'A' or ch == 'E' or ch == 'I' or ch == 'O' or ch == 'U') {
		return true;
	}
	return false;
}
int main()
{
	string s;
	cin >> s;
	int n = s.size(), count = 0;
	for (int i = 0; i < (n - 1); i++) {
		if (isVowel(s[i]) and !isVowel(s[i + 1]))
			count++;
	}
	cout << count << endl;


	return 0;
}