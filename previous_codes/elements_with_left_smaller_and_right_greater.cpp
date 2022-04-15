#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int fun()
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
		vector<int> arr(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		int ans = -1;
		vector<int> leftMax(n, 0), rightMin(n, 0);
		leftMax[0] = arr[0];
		for (int i = 1; i < n; i++)
		{
			leftMax[i] = max(leftMax[i - 1], arr[i]);
		}
		rightMin[n - 1] = arr[n - 1];
		for (int i = n - 2; i >= 0 ; i--)
		{
			rightMin[i] = min(rightMin[i + 1], arr[i]);
		}
		for (int i = 1; i < n - 1; i++)
		{
			if (leftMax[i] == rightMin[i])
			{
				ans = arr[i];
				break;
			}

		}
		cout << ans << endl;
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
		vector<int> arr(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		int ans = -1;
		vector<int> leftMax(n, INT_MIN);
		for (int i = 1; i < n; i++)
		{
			leftMax[i] = max(leftMax[i - 1], arr[i - 1]);
		}
		/*for (int i = 0; i < n ; i++)
			cout << leftMax[i] << " ";
		cout << endl;*/
		int rightMin = INT_MAX, prev = -1;
		for (int i = n - 1; i >= 0; i--)
		{
			if (leftMax[i] < arr[i] && rightMin > arr[i])
			{
				prev = ans;
				ans = arr[i];

			}
			//cout << rightMin << " ";
			rightMin = min(rightMin, arr[i]);
		}
		//cout/*rightMin*/ << endl;
		/*for (int i = 0; i < n ; i++)
		{
			int j = 0, k = i + 1;
			for (j = 0; j < i; j++)
			{
				if (arr[j] > arr[i])
					break;
			}
			for (k = i + 1; k < n; k++)
			{
				if (arr[k] < arr[i])
					break;
			}
			if (j == i && k == n && i + 1 != n)
			{
				ans = arr[i];
				break;
			}
			/*if (arr[i - 1] <= arr[i] && arr[i] <= arr[i + 1])
			{
				ans = arr[i];
				break;
			}
		}*/
		if (ans == arr[n - 1] || ans == arr[0])
			cout << prev << endl;
		else
			cout << ans << endl;
	}

	return 0;
}