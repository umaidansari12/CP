#include <bits/stdc++.h>

using namespace std;
using ll = long long;


bool oddString(string s)
{
	long long int n = 0;
	for (int i = 0; i < s.size(); i++)
	{
		n = n * 10 + s[i] - '0';
	}
	//cout << n << endl;
	return n % 2 != 0;
}
string largestOddNumber(string num) {
	int n = num.size();
	string ans = "";
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			string s = num.substr(i, j - i + 1);
			if (oddString(s))
			{
				if (s.length() > ans.length())
				{
					ans = s;
				}
			}
		}
	}
	return ans;

}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	cin.ignore();
	while (t--)
	{
		string s;
		cin >> s;
		cout << largestOddNumber(s) << endl;
	}


	return 0;
}