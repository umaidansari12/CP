/*#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second

using namespace std;

bool compare(string a, string b)
{
	return a + b < b + a;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	// cin.ignore(); must be there when using getline(cin, s)
	while (T--)
	{
		string s, p;
		cin >> s;
		//cin.ignore();
		cin >> p;
		int n = s.size(), m = p.size();
		map<char, int> ma;
		for (int i = 0; i < n; i++)
		{
			ma[s[i]]++;
		}
		for (int i = 0; i < m; i++)
		{
			ma[p[i]]--;
		}
		auto i = ma.begin();
		vector<string> final_string;
		while (i != ma.end())
		{
			string s;
			for (int j = 0; j < i->second; j++)
			{
				s += i->first;
			}
			final_string.push_back(s);
			i++;
		}
		final_string.push_back(p);
		sort(final_string.begin(), final_string.end(), compare);
		for (int i = 0; i < final_string.size(); i++)
		{
			cout << final_string[i];
		}
		cout << endl;
	}
	return 0;
}
*/
#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second

using namespace std;

bool compare(string a, string b)
{
	return (a + b < b + a);
}
int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	// cin.ignore(); must be there when using getline(cin, s)
	while (T--)
	{
		string s, p;
		cin >> s;
		//cin.ignore();
		cin >> p;
		map<char, int> ma;
		map<char, int> mb;
		for (int i = 0; i < s.size(); i++)
		{
			ma[s[i]]++;
		}
		for (int i = 0; i < p.size(); i++)
		{
			mb[p[i]]++;
		}
		auto i = ma.begin();
		string final_string;
		while (i != ma.end())
		{
			int size;
			if (mb.find(i->first) != mb.end())
			{
				size = ma[i->first] - mb[i->first];
			}
			else
			{
				size = ma[i->first];
			}
			for (int j = 0; j < size; j++)
			{
				final_string += i->first;
			}
			i++;
		}
		vector <string> se;
		for (int i = 0; i < final_string.size(); i++)
		{
			string n(1, final_string[i]);
			se.push_back(n);
		}
		se.push_back(p);
		sort(se.begin(), se.end(), compare);
		for (int i = 0; i < se.size(); i++)
		{
			cout << se[i];
		}
		cout << endl;
	}
	return 0;
}
