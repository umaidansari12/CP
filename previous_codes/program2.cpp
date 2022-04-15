#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int PairSumBrute(int arr[], int n, int key)
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if ((arr[i] + arr[j]) == key)
				cnt++;
		}
	}
	return cnt;
	// Time Complexity : O(N^2)
}

int PairSumOptimal(int arr[], int n, int key)
{
	int cnt = 0;
	unordered_map<int, int> m;
	for (int i = 0; i < n; i++)
	{
		m[arr[i]]++;//calculating frequency of every element and storing in hashmap
	}
	for (int i = 0; i < n; i++)
	{
		// a + b = target
		// we need to find target sum but we know target and a before hand and we dont know b so we will find b = target - a by checking into hashmap
		if (m.find(key - arr[i]) != m.end())
			cnt += (m[key - arr[i]]);
	}
	// we are returning count by 2 because it counts for every element twice
	return cnt / 2;
	//Time Complexity : O(N) + O(N) two traversals of the array is performed
	//Space Complexity : O(N) using hashmap to count the frequency of elements
}


int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n, key;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		cin >> key;
		cout << PairSumOptimal(a, n, key) << '\n';

	}
	// 0 1 2 3
	// 2 2 4 4



	// 0 3
	// 0 2
	// 1 2
	// 1 3



	// 1 2 2 4 4 5 6 8 9 10 11 15
	// 16 ->

	return 0;
}