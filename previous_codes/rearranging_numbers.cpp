#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//Try to rearrange the digits in increasing order. Think about handling zeroes.

//C++


class Solution
{
public:
	string smallestnum(string N)
	{
		int a[10] = {0};
		int n = N.length();
		for (int i = 0; i < n; i++)
		{
			a[N[i] - '0']++;
		}

		int i = 1;
		while (a[i] == 0)
			i++;

		string fans = "";
		fans += i + '0';
		a[i]--;
		for (int i = 0; i < 10; i++)
		{
			if (a[i] > 0)
			{	int a[10] = {0};
				int n = N.length();
				for (int i = 0; i < n; i++)
				{
					a[N[i] - '0']++;
				}

				int i = 1;
				while (a[i] == 0)
					i++;

				string fans = "";
				fans += i + '0';
				a[i]--;
				for (int i = 0; i < 10; i++)
				{
					if (a[i] > 0)
					{
						while (a[i] > 0)
						{
							fans += i + '0';
							a[i]--;
						}
					}
				}
				return fans;
				while (a[i] > 0)
				{
					fans += i + '0';
					a[i]--;
				}
			}
		}
		return fans;
	}
};


int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		string s;
		cin >> s;
		sort(s.begin(), s.end());
		int c = count(s.begin(), s.end(), '0');
		cout << c << endl;
		swap(s[0], s[c]);
		cout << s << endl;

	}


	return 0;
}