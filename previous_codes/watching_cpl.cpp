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
		long long int n, k, sum = 0;
		cin >> n >> k;
		vector<long long int> h(n);
		for (long long int i = 0; i < n; i++)
		{
			cin >> h[i];
			sum += h[i];
		}
		if (sum < (2 * k))
			cout << -1 << endl;
		else if (sum == (2 * k))
			cout << n << endl;
		else
		{
			sort(h.begin(), h.end(), greater<long long int>());
			if (h[0] >= k && h[1] >= k)
				cout << 2 << endl;
			else if (h[0] >= k && h[1] < k)
			{
				long long int i = 0, sum1 = 0;
				for (i = 1; i < n; i++)
				{
					if (sum1 >= k)
						break;
					sum1 += h[i];
				}
				if (sum1 >= k)
					cout << i + 1 << endl;
				else
					cout << -1 << endl;
			}
			else if (h[0] < k && h[1] < k)
			{
				long long int sum1 = 0, i = 0, sum2 = 0, count = 0;
				vector<long long int> m, t;
				for (i = 0; i < n; i++)
				{
					if (sum1 >= k)
						break;
					sum1 += h[i];
					m.push_back(h[i]);
					count++;
				}
				int j = i;
				for (; j < n; j++)
				{
					if (sum2 >= k)
						break;
					sum2 += h[j];
					t.push_back(h[j]);
					count++;
				}
				for (auto i : m)
					cout << i << " ";
				cout << endl;
				for (auto i : t)
					cout << i << " ";
				cout << endl;
				int a = 0;
				for (int b = 0; b < m.size() && a < t.size(); b++)
				{
					if (sum1 - m[b] + t[a] >= k)
					{
						sum1 -= m[b];
						sum1 += t[a];
						sum2 -= t[a];
						sum2 += m[b];
						swap(m[b], t[a++]);
					}
					else
						break;
				}
				for (auto i : m)
					cout << i << " ";
				cout << endl;
				for (auto i : t)
					cout << i << " ";
				cout << endl;
				int sum = 0, count1 = 0;
				j = 0;
				for (j = 0; j < t.size(); j++)
				{
					if (sum >= k)
						break;
					sum += t[j];
					count1++;
				}
				if (sum1 >= k && sum >= k)
					cout << m.size() + count1 << endl;
				else
					cout << -1 << endl;/*				     int low = 0, high = i;
				while (low <= high)
				{

				}*/
			}
		}
		/*sort(h.begin(), h.end(), greater<long long int>());
		long long int sum1 = 0, sum2 = 0, count = 0, f1 = 0, f2 = 0;
		for (long long int i = 0; i < n; i += 2)
		{
			if (sum1 >= k)
			{
				//f1 = 1;
				break;
			}
			sum1 += h[i];
			count++;
		}
		for (int i = 1; i < n; i += 2)
		{
			if (sum2 >= k)
			{
				//f2 = 1;
				break;
			}
			sum2 += h[i];
			count++;
		}
		//cout << endl << sum1 << " " << sum2 << " " << count << endl;
		if (sum1 >= k && sum2 >= k)
			cout << count << endl;
		else
			cout << -1 << endl;*/
	}


	return 0;
}