#include <bits/stdc++.h>

using namespace std;
using ll = long long;

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
		vector<long> a(n), prefixSum(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (i == 0)
			{
				/*if(a[i]==-1)
				a[i]=0;*/
				prefixSum[i] = a[i];
			}

			else
			{
				if (a[i] == -1)
				{
					a[i] = prefixSum[i - 1] / (i);
				}
				prefixSum[i] = prefixSum[i - 1] + a[i];
			}
		}
		for (int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << endl;
	}


	return 0;
}