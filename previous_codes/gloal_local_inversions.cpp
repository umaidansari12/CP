#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
	int merge(vector<int>&A, vector<int>&temp, int left, int mid, int right)
	{
		int i = left, j = mid, k = left, inv_count = 0;
		while (i <= mid - 1 && j <= right)
		{
			if (A[i] <= A[j])
				temp[k++] = A[i++];
			else
			{
				temp[k++] = A[j++];
				inv_count += (mid - i);
			}
		}
		while (i <= mid - 1)
			temp[k++] = A[i++];
		while (j <= right)
			temp[k++] = A[j++];
		for (int i = left; i <= right; i++)
			A[i] = temp[i];
		return inv_count;
	}
	int mergeSort(vector<int>&A, vector<int>&temp, int left, int right)
	{
		int inv_count = 0;
		if (right > left)
		{
			int mid = (left + right) / 2;
			inv_count += mergeSort(A, temp, left, mid);
			inv_count += mergeSort(A, temp, mid + 1, right);
			inv_count += merge(A, temp, left, mid + 1, right);
		}
		return inv_count;
	}
	bool isIdealPermutation(vector<int>& A) {
		int n = A.size(), local = 0, global = 0;
		for (int i = 0; i < n - 1; i++)
		{
			if (A[i] > A[i + 1])
				local++;
		}
		vector<int> temp(n, 0);
		global = mergeSort(A, temp, 0, n - 1);
		if (local == global)
			return true;
		return false;

	}
};


int merge(vector<int>&A, vector<int>&temp, int left, int mid, int right)
{
	int i = left, j = mid, k = left, inv_count = 0;
	while (i <= mid - 1 && j <= right)
	{
		if (A[i] <= A[j])
			temp[k++] = A[i++];
		else
		{
			temp[k++] = A[j++];
			inv_count += (mid - i);
		}
	}
	while (i <= mid - 1)
		temp[k++] = A[i++];
	while (j <= right)
		temp[k++] = A[j++];
	for (int i = left; i <= right; i++)
		A[i] = temp[i];
	return inv_count;
}
int mergeSort(vector<int>&A, vector<int>&temp, int left, int right)
{
	int inv_count = 0;
	if (right > left)
	{
		int mid = (left + right) / 2;
		inv_count += mergeSort(A, temp, left, mid);
		inv_count += mergeSort(A, temp, mid + 1, right);
		inv_count += merge(A, temp, left, mid + 1, right);
	}
	return inv_count;
}

bool isIdealPermutation(vector<int>& A) {
	int n = A.size(), local = 0, global = 0;
	for (int i = 0; i < n - 1; i++)
	{
		if (A[i] > A[i + 1])
			local++;
	}
	vector<int> temp(n, 0);
	global = mergeSort(A, temp, 0, n - 1);
	if (local == global)
		return true;
	return false;

}

int main()
{
	ios_base :: sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		if (isIdealPermutation(a))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;

	}


	return 0;
}