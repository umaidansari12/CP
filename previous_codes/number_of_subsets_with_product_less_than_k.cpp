#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string getBinaryString(int i, int n)
{
	string s = "";
	int count = 0;
	while (i > 0)
	{
		s += to_string(i % 2);
		i /= 2;
		count++;
	}
	while (count < n)
	{
		s += '0';
		count++;
	}
	reverse(s.begin(), s.end());
	return s;
}

long long int solveMeet(vector<int>&a, int n, int k)
{
	long long int count = 0;
	vector<long long int> vect1, vect2, sub1, sub2;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > k)
			continue;
		if (i <= (n / 2))
			vect1.push_back(a[i]);
		else
			vect2.push_back(a[i]);
	}
	int n1 = vect1.size(), n2 = vect2.size();
	for (int i = 0; i < (1 << n1); i++)
	{
		long long pro = 1;
		for (int j = 0; j < n1; j++)
		{
			if (i & (1 << j))
				pro *= vect1[j];
		}
		if (pro <= k)
			sub1.push_back(pro);
	}
	for (int i = 0; i < (1 << n2); i++)
	{
		long long pro = 1;
		for (int j = 0; j < n2; j++)
		{
			if (i & (1 << j))
				pro *= vect2[j];
		}
		if (pro <= k)
			sub2.push_back(pro);
	}

	sort(sub2.begin(), sub2.end());
	for (int i = 0; i < sub1.size(); i++)
	{
		count += upper_bound(sub2.begin(), sub2.end(), (k / sub1[i])) - sub2.begin();
	}
	count--;
	return count;
}

int solve(vector<int>&a, int n, int k)
{
	int count = 0;
	for (int i = 1; i <= pow(2, n) - 1; i++)
	{
		string binary = getBinaryString(i, n);
		long long prod = 1;
		//cout << binary << endl;
		for (int j = 0; j < binary.length(); j++)
		{
			if (binary[j] == '1')
			{
				prod *= a[j];
			}
		}
		if (prod <= k)
			count++;
	}
	return count;
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
		int n, k;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cin >> k;
		cout << solveMeet(a, n, k) << endl;

	}



	return 0;
}