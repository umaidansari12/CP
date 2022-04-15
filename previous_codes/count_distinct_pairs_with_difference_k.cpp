#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int fun()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		int arr[n];

		for (int i = 0; i < n; i++)cin >> arr[i];

		int k; cin >> k;

		int fre_count[MAX] = {0};

		for (int i = 0; i < n; i++)
		{
			fre_count[arr[i]]++;
		}

		int count = 0;
		for (int i = 0; i < n; i++)
		{
			int x = arr[i];
			fre_count[x]--;
			if (x - k >= 0 && fre_count[x - k] > 0)
				count++;
			else if (x + k < MAX && fre_count[x + k] > 0)
				count++;
			fre_count[x] = 0;
		}
		cout << count << endl;
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
		int n, k;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cin >> k;
		int count = 0;
		//sort(a.begin(), a.end());
		//auto it = unique(a.begin(), a.end());
		//a.resize(distance(a.begin(), it));
		/*for (int i = 0; i < n - 1; i++)
		{
			if (binary_search(a.begin() + i + 1, a.end(), a[i] + k))
				count++;
		}
		*/
		map<int, int> m;
		for (int i = 0; i < n; i++)
		{
			if (m[a[i]] == 0)
				m[a[i]]++;
		}

		for (int i = 0; i < n; i++)
		{
			if (m.find(k + a[i]) != m.end())
			{
				count++;
				m.erase(k + a[i]);
			}
			if (m.find(a[i] - k) != m.end())
			{
				count++;
				m.erase(a[i] - k);
			}
		}
		/*if (m[a[i]] == 0)
			m[a[i]]++;

		}
		/*for (int i = 0; i < n; i++)
		{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] - a[j] == k || a[j] - a[i] == k)
				count++;
		}
		}
		int low = 0, high = n - 1;
		int low = 0, high = 0;
		while(high<n)
		{
		    if((a[high]-a[low])==k)
		    {
		        count++;
		        high++;
		        low++;
		    }
		    else if(a[high]-a[low]>k)
		    {
		        low++;
		    }
		    else
		    {
		        high++;
		    }
		}*/
		cout << count << endl;
	}


	return 0;
}