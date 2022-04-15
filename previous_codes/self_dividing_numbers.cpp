#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool solve(int num)
{
	int temp = num;
	while (temp > 0)
	{
		int n = temp % 10;
		temp = temp / 10;
		if (n == 0)
			return false;
		if (num % n != 0)
			return false;
	}
	return true;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int left, right;
		cin >> left >> right;
		vector<int> res;
		for (int i = left; i <= right; i++)
		{
			if (solve(i))
				res.push_back(i);
		}
		for (auto i : res)
			cout << i << " ";
		cout << endl;
	}
	return 0;
}