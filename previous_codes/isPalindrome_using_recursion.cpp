#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void AtoiRecursion(string s, int &temp, int idx)
{
	if (idx == s.size())
		return;
	temp = temp * 10 + (s[idx] - '0');
	AtoiRecursion(s, temp, idx + 1);

}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	int temp = 0;
	AtoiRecursion(s, temp, 0);
	cout << temp << endl;

	return 0;
}