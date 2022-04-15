#include<bits/stdc++.h>
using namespace std;

int maxDistance(int arr[], int n);

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		cout << maxDistance(arr, n) << endl;
	}
	return 0;
}// } Driver Code Ends


// your task is to complete this function
int maxDistance(int arr[], int n)
{
	//Code here
	unordered_map<int, int> m;
	int dist = 0;
	for (int i = 0; i < n; i++)
	{
		if (m.find(arr[i]) == m.end())
			m.insert({arr[i], i});
		dist = max(dist, i - m[arr[i]]);
	}
	return dist;
}