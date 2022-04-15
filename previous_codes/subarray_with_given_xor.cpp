#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int subarrayWithGivenXor(vector<int>&a, int n, int m)
{
	vector<int> xorArr(n);
	xorArr[0] = a[0];
	for (int i = 1; i < n; i++)
	{
		xorArr[i] = xorArr[i - 1] ^ a[i];
	}
	int ans = 0;
	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++)
	{
		int tmp = m ^ xorArr[i];
		ans += mp[tmp];
		if (xorArr[i] == m)
			ans++;
		mp[xorArr[i]]++;
	}
	return ans;
}

int subarray_with_given_xor(vector<int> A, int n, int B)
{
	int ans = 0, tmp = 0;
	unordered_map<int, int> m;
	for (int i = 0; i < n; i++)
	{
		tmp = tmp ^ A[i];
		ans += m[tmp];
		if (A[i] == B)
		{
			ans++;
		}
		m[A[i]]++;
	}
	return ans;
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
		int n, m;
		cin >> n >> m;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		cout << subarrayWithGivenXor(a, n, m);
		cout << subarray_with_given_xor(a, n, m) << endl;
	}


	return 0;
}