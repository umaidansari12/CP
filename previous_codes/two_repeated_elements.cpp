#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll fact(int n)
{
	ll p = 1;
	for (int i = 1; i <= n; i++)
	{
		p *= i;
	}
	return p;
}


void repeated_element(vector<int> a, int n)
{
	//TLE dera hai
	unordered_map<int, int> m;
	for (int i = 0; i < n + 2; i++)
	{
		if (m[a[i]] == 1)
			cout << a[i] << " ";
		else
			m[a[i]]++;
	}
	cout << endl;
}

void Repeated_Element(vector<int> a, int n)
{
	ll s = 0, p = 1;
	for (int i = 0; i < n + 2; i++)
	{
		s += a[i];
		p *= a[i];
	}
	s = s - ((n * (n + 1)) / (int)2);//s is x+y now
	p = p / (ll)fact(n); //p is xy now
	ll d = sqrt((s * s) - 4 * p);
	ll x = (s + d) / 2;
	ll y = (s - d) / 2;
	cout << x << " " << y << endl;
}
int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> a(n + 2);
		for (int i = 0; i < n + 2; i++)
		{
			cin >> a[i];
		}
		repeated_element(a, n);

	}


	return 0;
}