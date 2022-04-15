#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//brute way is to use recursion - exponential time complexity

// dp O(n2) quadratic time complexity

// binary search algorithm reducing the search space O(NlogN) time complexity

// n for checking if it is possible to allocate mid as partition
// and logN was dividing into search space

// bool isPossible(int arr[], int mid, int n, int m)
// {
// 	int cnt = 0, i = 0, sum = 0;
// 	while (i < n)
// 	{
// 		if (sum + arr[i] <= mid)
// 		{
// 			sum += arr[i];
// 			i++;
// 		}
// 		else
// 		{
// 			sum = 0;
// 			cnt++;
// 		}
// 	}
// 	return cnt == m;
// }

bool isPossible1(int arr[], int mid, int n, int m)
{
	int cnt = 1, i = 0, sum = 0;
	while (i < n)
	{
		if (arr[i] > mid)
			return false;
		if (sum + arr[i] <= mid)
		{
			sum += arr[i];
		}
		else
		{
			sum = arr[i];
			cnt++;
		}
		i++;
	}
	if ((cnt > m))
		return false;
	return true;
}


bool isPossibleHelper(int barrier , vector<int>&arr, int n, int m)
{
	int cnt = 1, pages = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > barrier)
			return false;
		if (pages + arr[i] > barrier)
		{
			pages = arr[i];
			cnt++;
		}
		else
			pages += arr[i];
	}
	if (cnt > m)
		return false;
	return true;
}


int books(vector<int> &A, int B) {
	int low = *min_element(A.begin(), A.end()), high = accumulate(A.begin(), A.end(), 0), mid, ans = -1;
	if (B > A.size())
		return -1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (isPossibleHelper(mid, A, A.size(), B))
		{
			ans = mid;
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	return low;
}

bool isPossible(int arr[], int barrier, int n, int m)
{
	int allocatedStudent = 1, pages = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > barrier)
			return false;
		if (pages + arr[i] > barrier) // if pages crosses barrier
		{
			allocatedStudent++;
			pages = arr[i];
		}
		else
		{
			pages += arr[i];
		}
	}
	return allocatedStudent > m ? false : true;
}

int allocateMinimumNumberOfPages(int a[], int n, int m)
{
	int sum = accumulate(a, a + n, 0), min = *min_element(a, a + n), res = -1, low = min, high = sum, mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (isPossible(a, mid, n, m))
		{
			res = mid;
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	//cout << min << ' ' << sum << endl;
	return res;
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
		int n, m;
		cin >> n >> m;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << allocateMinimumNumberOfPages(a, n, m) << '\n';
	}


	return 0;
}