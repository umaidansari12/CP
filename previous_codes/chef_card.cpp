#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll sum_of_digits(int n)
{
	ll sum = 0;
	while (n > 0)
	{
		sum += (n % 10);
		n = n / 10;
	}
	return sum;
}

for (int i = 0; i < 100000000; i++)
{
	if ()
		cout << i << " " << countx[i] << "---" << y << " " << county[i] << endl;
}

void chef_card()
{
	int n;
	cin >> n;
	int c = 0, m = 0;
	for (int i = 0; i < n; i++)
	{
		int chef, monty;
		cin >> chef >> monty;
		if (chef == monty)
		{
			c++;
			m++;
		}
		else
		{
			ll sc = sum_of_digits(chef);
			ll sm = sum_of_digits(monty);
			if (sc == sm)
			{
				c++;
				m++;
			}
			else if (sc > sm)
			{
				c++;
			}
			else if (sc < sm)
			{
				m++;
			}
		}

	}
	if (c == m)
	{
		cout << "2 " << c << endl;
	}
	else if (c > m)
	{
		cout << "0 " << c << endl;
	}
	else
	{
		cout << "1 " << m << endl;
	}
}

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		chef_card();
	}
	return 0;
}