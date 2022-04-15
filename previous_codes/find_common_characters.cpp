#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		vector <string> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			//sort(a[i].begin(), a[i].end());
		}
		vector<int> cnt(26, INT_MAX);
		for (int i = 0; i < n; i++)
		{
			int m = a[i].size();
			vector<int> cnt1(26, 0);
			for (int j = 0; j < m; j++)
			{
				cnt1[a[i][j] - 'a']++;
			}
			for (int k = 0; k < 26; k++)
				cnt[k] = min(cnt[k], cnt1[k]);
		}
		vector<string> res;
		for (int i = 0; i < 26; i++)
		{
			for (int j = 0; j < cnt[i]; j++)
				res.push_back(string(1, i + 'a'));
		}
		for (auto i : res)
			cout << i << " ";
		cout << endl;
		/*for (auto i : a)
			cout << i << " ";
		cout << endl;*/
		/*int m = a[0].size();
		for (int k = 0; k < m; k++)
		{
			//bool f1 = false, f = true;
			int count = 0;
			for (int i = 1; i < n; i++)
			{
				//bool f2 = false;
				bool f = false;
				int b = a[i].size();
				for (int j = 0; j < b; j++)
				{
					//cout << a[0][k] << " " << a[i][j] << endl;
					if (a[i][j] == a[0][k])
						f = true;
				}
				if (f)
					count++;
				/*if (f2)
					f1 = true;*/
		//}
		/*if (count == (n - 1))
			cout << a[0][k] << " ";*/
		/*if (!f1)
			f = false;
		if (f)
			cout << a[0][k] << " ";
		}
		cout << endl;*/
	}


	return 0;
}