#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string solve()
{
	int x1, x2, y1, y2, z1, z2, count = 0;
	cin >> x1 >> x2 >> y1 >> y2 >> z1 >> z2;
	//cout << (z1 - z2) << endl;
	if (x2 >= x1)
	{
		count++;
		//cout << "x ";
	}
	else
		return "NO";
	if (y2 >= y1)
	{
		count++;
		//cout << "y ";
	}
	else
		return "NO";
	if ((z2 <= z1))
	{
		count++;
		//cout << "z ";
	}
	else
		return "NO";
	//cout << count << endl;
	return count == 3 ? "YES" : "NO";
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		cout << solve() << endl;
	}


	return 0;
}