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

vector<pair<int, int>> stockBuySell(vector<int> a, int start, int end)
{
	vector<pair<int, int>> r;
	int i = 0;
	while (i < end - 1)
	{
		while (i < end - 1 && a[i + 1] <= a[i]) //finding the local minima next element less than the current element
			i++;
		if (i == end - 1)
			break;
		int buy = i++;
		while (i < end &&  a[i - 1] <= a[i])
			i++;
		int sell = i - 1;
		r.push_back(make_pair(buy, sell));
	}
	return r;
}


int maxProfit(vector<int> &price, int start, int end)
{
	int maxProfit = 0, buy = -1, sell = -1;
	while (start < end - 1)
	{
		while (start < end - 1 && price[start + 1] <= price[start])
			start++;
		if (start == end - 1)
			break;
		buy = start++;
		while (start < end && price[start - 1] <= price[start])
			start++;
		sell = start - 1;
		maxProfit += (price[sell] - price[buy]);
	}

	return maxProfit;
}

int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	// cin.ignore(); must be there when using getline(cin, s)
	while (T--)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		/*vector<pair<int, int>> r = stockBuySell(a, 0, n);
		if (r.size() == 0)
			cout << "No Profit\n";
		else
		{
			for (auto i : r)
			{
				cout << "(" << i.first << " " << i.second << ") ";
			}
			cout << endl;
		}*/
		cout << "Profit: " << maxProfit(a, 0, n) << endl;
	}
	return 0;
}
