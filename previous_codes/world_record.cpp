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
		double k1, k2, k3, v;
		cin >> k1 >> k2 >> k3 >> v;
		double res = k1 * k2 * k3 * v;
		double ans = double(100.00) / res;
		ans = (int)(ans * 100 + 0.5);
		ans = (float) ans / 100;
		cout << ans << endl;
		//cout << ans << endl;
		if (ans < double(9.58))
			cout << "YES\n";
		else
			cout << "NO\n";
	}


	return 0;
}

/*
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
		double k1, k2, k3, v;
		cin >> k1 >> k2 >> k3 >> v;
		double res = k1 * k2 * k3 * v;
		double ans = double(100.00) / res;
		ans = (double)((ans * 100) + 0.5);
		ans = (float) ans / 100;
		//cout << ans << endl;
		//cout << ans << endl;
		ans=ans-9.58;
		if (ans < 0)
			cout << "YES\n";
		else
			cout << "NO\n";
	}


	return 0;
}
*/