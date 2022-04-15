#include <bits/stdc++.h>

using namespace std;
using ll = long long;
class Solution {
public:
	vector<int> leastPrimeFactor(int n) {
		// code here
		vector<int> prime(n + 1, 0);
		prime[0] = prime[1] = 1;
		for (int i = 2; i <= n; i++)
		{
			if (prime[i] == 0)
			{
				prime[i] = i;
				for (int j = i * i; j <= n; j += i)
				{
					if (prime[j] == 0)
						prime[j] = i;
				}
			}
		}
		vector<int> r;
		r.push_back(1);
		for (int i = 1; i <= n; i++)
			r.push_back(prime[i]);
		return r;
	}
};

vector<int> leastPrimeFactor(int n) {
	// code here
	vector<bool> prime(1001, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i * i <= 1000; i++)
	{
		if (prime[i])
		{
			for (int j = i * i; j <= 1000; j += i)
			{
				prime[j] = false;
			}
		}
	}
	vector<int> r;
	r.push_back(1);
	for (int i = 2; i <= n; i++)
	{
		for (int j = 2; j <= 1000; j++)
		{
			if (prime[j] && i % j == 0)
			{
				r.push_back(j);
				break;
			}
		}
	}
	return r;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	/*cin.tie(NULL);
	cout.tie(NULL);*/
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		vector<int> r = leastPrimeFactor(n);
		for (auto i : r)
			cout << i << " ";
		cout << endl;
	}


	return 0;
}