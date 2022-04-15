#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string getBinaryString(int n)
{
	string s;
	while (n)
	{
		s += to_string(n % 2);
		n /= 2;
	}
	reverse(s.begin(), s.end());
	return s;
}

void generatePermutations(vector<string> &b, string res, int l, int r, int &ans)
{
	if (l == r + 1)
	{
		int count = 0;
		//cout << res << endl;
		for (int i = 0; i < res.size(); i++)
		{
			if (res[i] == res[i + 1] == '1')
				count++;
		}
		ans = min(count, ans);
		return;
	}
	for (int i = l; i <= r; i++)
	{
		swap(b[l], b[i]);
		generatePermutations(b, res + b[l], l + 1, r, ans);
		swap(b[l], b[i]);
	}
}

int solve()
{
	int n;
	cin >> n;
	vector<ll> a(n);
	vector<string> b(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		b[i] = getBinaryString(a[i]);
		//cout << b[i] << " ";
	}
	int ans = INT_MAX;
	generatePermutations(b, "", 0, b.size() - 1, ans);
	return ans;
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