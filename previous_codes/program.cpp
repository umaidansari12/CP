#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int binarySearch(int arr[], int key, int n)
{
	int low = 0, high = n - 1, mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (arr[mid] == key)
		{
			return mid;
		}
		//left search space
		if (arr[mid] > arr[low] and arr[low] <= key and arr[mid] >= key)
		{
			high = mid - 1;
		}
		//right search space
		else //if (arr[mid] < arr[high] and arr[mid] <= key and arr[high] >= key)
		{
			low = mid + 1;
		}
	}
	return -1;
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
		int arr[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		cin >> key;
		cout << binarySearch(arr, key, n) << "\n";
	}

	return 0;
}

