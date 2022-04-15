/*#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void chefinaSwaps(vector<ll> &a, vector<ll> &b)
{
	unordered_map<ll, ll> m, m1, m2;
	ll mi = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		mi = min(a[i], mi);
		m[a[i]]++;
	}
	for (int i = 0; i < n; i++)
	{
		mi = min(b[i], mi);
		m[b[i]]++;
	}
	int flag = 0;
	for (auto i : m)
	{
		if (i.second % 2 == 1)
		{
			flag = 1;
			break;
		}
		else
		{
			m1[i.first] = i.second / 2;
		}
	}
	if (flag)
	{
		cout << "-1\n";
		return;
	}
	else
	{
		m2 = m1;
		vector<ll> v1, v2;
		for (int i = 0; i < n; i++)
		{
			if (m1[a[i]])
				m1[a[i]]--;
			else
				v1.push_back(a[i]);
		}
		for (int i = 0; i < n; i++)
		{
			if (m2[b[i]])
				m2[b[i]]--;
			else
				v2.push_back(b[i]);
		}
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		ll y = v1.size();
		if (y == 0)
			cout << "0\n";
		else
		{
			ll ans = 0;
			for (int i = 0; i < y; i++)
			{
				ans += min(2 * mi, min(v1[i], v2[i]));
			}
			cout << ans << "\n";
		}

	}
}

/*void chefinaSwaps(int n, vector<int>&a, vector <int>&b)
{
	int c = 0;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	if (a == b)
	{
		cout << 0;
	}
	vector <int> s;
	s.insert(s.begin(), b.begin(), b.end());
	s.insert(s.begin(), a.begin(), a.end());
	cout << "s\n";
	for (auto i : s)
	{
		cout << i << " ";
	}
	cout << endl;
}


int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector <ll> a(n);
		vector <ll> b(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> b[i];
		}
		chefinaSwaps(n, a, b);
	}
	return 0;
}
*/

/*int chefinaSwaps(int n, vector<ll>&a, vector<ll>&b)
{
	map<ll, int> m1, m2;
	int c = 0;
	if (n == 1)
	{
		if (a[0] != b[0])
			return -1;
		else
			return 0;
	}
	else
	{
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		for (int i = 0; i < n; i++)
		{
			m1[a[i]]++;
		}
		for (int i = 0; i < n; i++)
		{
			m2[b[i]]++;
		}

		auto j = m1.begin(), i = m2.begin();
		while (j != m1.end() && i != m2.end())
		{
			if (m1[i->first] != m1[j->first])
			{
				c++;
			}
			i++;
			j++;
		}
	}
	return c;
}

int chefinaswaps(int n, vector<ll>&a, vector<ll>&b)
{
	if (n == 1)
	{
		if (a[0] != b[0])
			return -1;
		else
			return 0;
	}
	else
	{
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		for (int i = 0; i < n; i++)
		{
			if (a[i] != b[i])
			{
				return min(a[i], b[i]);
			}
		}
	}
	return 0;
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
		vector <ll> a(n), b(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> b[i];
		}
		cout << chefinaSwaps(n, a, b) << endl;
	}


	return 0;
}

*/
#include<bits/stdc++.h>
#define int      long long int
#define nitro    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define pb       push_back
#define pi       3.1415926535897932384626
#define mod      1000000007
#define endl     '\n'
#define DEBUG    false
#define F        first
#define S        second
#pragma GCC optimize "trapv"

using namespace std;

signed main()
{
	nitro;
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		std::map<int, int> m1, m2, m3, m4, m5;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			m1[a[i]]++;
			m3[a[i]]++;
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
			m2[b[i]]++;
			m3[b[i]]++;
		}
		int f = 0;
		for (auto i : m3)
		{
			if (i.S % 2 != 0)
			{
				f = 1;
				break;
			}
		}
		int t1[n], t2[n];
		for (int i = 0; i < n; i++)
			t1[i] = a[i];
		for (int i = 0; i < n; i++)
			t2[i] = b[i];
		sort(t1, t1 + n);
		sort(t2, t2 + n);
		int p = 0;
		for (int i = 0; i < n; i++)
		{
			if (t1[i] != t2[i])
			{
				p = 1;
				break;
			}
		}
		if (p == 0)
			cout << 0 << endl;
		else if (f == 1)
			cout << -1 << endl;
		else
		{
			int c = 0;
			int m = INT_MAX;
			for (int i = 0; i < n; i++)
				m = min(m, a[i]);
			for (int i = 0; i < n; i++)
				m = min(m, b[i]);
			for (auto i : m1)
			{
				if (i.S > m2[i.F])
					m4[i.F] = (i.S - m2[i.F]) / 2;
			}
			for (auto i : m2)
			{
				if (i.S > m1[i.F])
					m5[i.F] = (i.S - m1[i.F]) / 2;
			}
			std::vector<int> v1, v2;
			for (auto i : m4)
			{
				for (int j = 0; j < i.S; j++)
					v1.pb(i.F);
			}
			for (auto i : m5)
			{
				for (int j = 0; j < i.S; j++)
					v2.pb(i.F);
			}
			sort(v1.begin(), v1.end());
			sort(v2.begin(), v2.end(), greater<int>());
			for (int i = 0; i < v1.size(); i++)
			{
				int k1 = v1[i];
				int k2 = v2[i];
				c += min(2 * m, (min(k1, k2)));
			}
			cout << c << endl;
		}
	}
	return 0;
}