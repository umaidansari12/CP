#include <bits/stdc++.h>

using namespace std;
using ll = long long;


//O(n^4)
void brute(vector<int> a, int n, int x)
{
	for (int i = 0; i < n - 3; i++)
	{
		for (int j = i + 1; j < n - 2; j++)
		{
			for (int k = j + 1; k < n - 1; k++)
			{
				for (int l = k + 1; l < n; l++)
				{
					if (a[i] + a[j] + a[k] + a[l] == x)
					{
						cout << "1" << endl;
						break;
					}

				}
			}
		}
	}
}

int better(vector<int> &a, int n, int x)
{
	sort(a.begin(), a.end());
	for (int i = 0; i < n - 3; i++)
	{
		for (int j = i + 1; j < n - 2; j++)
		{
			int k = j + 1;
			int l = n - 1;
			while (k < l)
			{
				if (a[i] + a[j] + a[k] + a[l] == x)
					return 1;
				else if (a[i] + a[j] + a[k] + a[l] > x)
					l--;
				else
					k++;
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
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int x;
		cin >> x;

	}



	return 0;
}