#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		string s;
		string no = to_string(n);
		int t = n, sum = 0;
		while (t > 0)
		{
			sum += (t % 10);
			t /= 10;
		}
		cout << sum << endl;
		for (int i = 0; i < no.size(); i++)
		{
			//cout << no[i] << " ";
			char c = no[i] + '0' + 1;

			//cout << (int)c << " " << endl;
			s += (c);
		}
		cout << s << endl;
		string ne;
		for (int i = 0; i < (sum / no.size()); i++)
			ne += s;
		ne += (s.substr(0, sum % no.size()));
		cout << ne << endl;
		int f = 0, i = 0, j = ne.size() - 1;
		while (i <= j)
		{
			if (ne[i++] != ne[j++])
			{
				f = 1;
				break;
			}
		}
		if (f)
			cout << "No\n";
		else
			cout << "Yes\n";


		// (int i = 0; i < )
		//return true;
	}


	return 0;
}