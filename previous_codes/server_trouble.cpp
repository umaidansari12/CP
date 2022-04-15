#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		ll n, k;
		cin >> n >> k;
		ll d = ceil(float(n) / float(k));
		int rem = n % k;

		if (rem == 0)
		{
			/*int dis = n / k;
			int pair = n / dis;*/
			cout << d << " " << k << endl;
		}
		else
		{
			/*vector<int> a;
			k--;
			a.push_back(1);*/
			/*int dis = n / k;
			int pair = n % k;*/
			/*for (int i = dis; i <= n; i += dis)
				a.push_back(i);*/
			/*for (auto i : a)
				cout << i << " ";
			cout << endl;*/
			cout << d << " " << rem << endl;

		}
	}


	return 0;
}