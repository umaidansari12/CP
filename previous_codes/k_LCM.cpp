#include <bits/stdc++.h>

using namespace std;
using ll = long long;

long long gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

long long lcm(int a, int b)
{
	return (a / gcd(a, b)) * b;
}

void solve1()
{
	int n, k;
	cin >> n >> k;	//cout << "1\n";
	for (int i = 1; i <= n; i++)
	{
		//cout << "2\n";
		for (int j = 1; j <= n; j++)
		{
			//cout << "3\n";
			for (int l = 1; l <= n; l++)
			{
				//cout << "4\n";

				if ((i + j + l) == n)
				{
					ll m = lcm(i, j);
					ll o = lcm(m, l);
					if (o <= (n / 2))
					{
						cout << i << " " << j << " " << l << " \n";
						return;
					}

				}
			}
		}
	}
}

void solve()
{
	int n, k;
	cin >> n >> k;
	/*int n, k;
	    cin >> n >> k;
	    if (n % 2) cout << 1 << ' ' << n / 2 << ' ' << n / 2 << '\n';
	    else if (n % 2 == 0 && n % 4) cout << 2 << ' ' << n / 2 - 1 << ' ' << n / 2  - 1 << '\n';
	    else cout << n / 2 << ' ' << n / 4 << ' ' << n / 4 << '\n';*/

	if (n % 2 != 0)
	{
		n -= 1;
		cout << 1 << " " << n / 2 << " " << n / 2 << endl;
	}
	else if (n % 2 == 0 && (n % 4) != 0)
	{
		n -= 2;
		cout << 2 << " " << n / 2 << " " << n / 2 << endl;
	}
	else if ((n % 2) == 0 && (n % 4) == 0)
	{
		cout << n / 2 << " " << n / 4 << " " << n / 4 << endl;
	}
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	//cout << "hello\n";
	while (t--)
	{
		//cout << "0\n";
		solve();
	}


	return 0;
}