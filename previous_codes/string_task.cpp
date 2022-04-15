#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s, s1;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'A' || s[i] == 'a' || s[i] == 'E' || s[i] == 'e' || s[i] == 'I' || s[i] == 'i' || s[i] == 'O' || s[i] == 'o' || s[i] == 'U' || s[i] == 'u' || s[i] == 'Y' || s[i] == 'y')
		{
			continue;
		}
		else
		{
			s1 += '.';
			s1 += tolower(s[i]);
		}
	}
	cout << s1 << endl;
	return 0;
}