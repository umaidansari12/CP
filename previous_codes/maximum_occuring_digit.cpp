#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//Count frequency of k in every number by dividing it by 10 repeatedly till the number becomes 0.

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n, k, res = -1, ans = -1;
		cin >> n >> k;
		vector<int> a(n, 0);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			int n = a[i], c = 0;
			while (n > 0)
			{
				if (n % 10 == k)
					c++;
				n /= 10;
			}
			if (res < c)
			{
				res = c;
				ans = a[i];
			}
		}
		cout << ans << endl;
	}


	return 0;
}

class Solution
{

public:
	int maxoccourence(int arr[], int n, int k)
	{
		int cnt = 0;
		int num = -1;
		for (int i = 0; i < n; i++)
		{
			int temp = arr[i];
			int tcnt = 0;
			while (temp > 0)
			{
				if (temp % 10 == k)
					tcnt++;
				temp /= 10;
			}
			if (tcnt > cnt)
			{
				cnt = tcnt;
				num = arr[i];
			}
			else if (tcnt == cnt)
			{
				num = min(arr[i], num);
			}



		}
		return num;


	}
};
