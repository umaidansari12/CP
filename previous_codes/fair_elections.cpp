#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n, m;
		long long s1 = 0, s2 = 0;
		cin >> n >> m;
		vector<int> a(n), b(m);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			s1 += a[i];
		}
		for (int i = 0; i < m; i++)
		{
			cin >> b[i];
			s2 += b[i];
		}
		/*if (s1 > s2)
		{
			cout << "0\n";
			return 0;
		}*/
		sort(a.begin(), a.end());
		sort(b.begin(), b.end(), greater<int>());
		long long int count = 0;
		//s1 = 0, s2 = 0;
		for (int i = 0; i < n && i < m; i++)
		{
			if (a[i] < b[i])
			{
				if (s1 > s2)
					break;
				s1 -= a[i];
				s1 += b[i];
				s2 -= b[i];
				s2 += a[i];
				swap(a[i], b[i]);
				count++;

			}
			else
			{
				break;
			}
			/*s1 += a[i];
			s2 += b[i];*/
		}
		if (s1 > s2)
			cout << count << endl;
		else
			cout << -1 << endl;
		/*for (int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << endl;
		for (int i = 0; i < m; i++)
			cout << b[i] << " ";
		cout << endl;*/

	}


	return 0;
}