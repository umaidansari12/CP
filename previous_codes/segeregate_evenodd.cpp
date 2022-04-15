#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void segeregateEvenodd(vector<int> a, int n)
{
	int i = 0, low = 0;
	while (i < n)
	{
		if (a[i] % 2 == 0)
		{
			swap(a[i], a[low]);
			i++;
			low++;
		}
		else
			i++;
	}
	sort(a.begin(), a.begin() + low);
	sort(a.begin() + low, a.end());
	for (int j = 0; j < n; j++)
	{
		cout << a[j] << " ";
	}
	cout << endl;
}

void binSort(int A[], int N)
{
	//Your code here



	/**************
	 * No need to print the array
	 * ************/
	int left = 0, right = N - 1;
	while (left < right)
	{
		if (A[left] == 0)
			left++;
		else
		{
			int temp = A[left];
			A[left] = A[right];
			A[right] = temp;
			right--;
		}
		//swap(a[left],a[right--]);
	}
}

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector <int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		segeregateEvenodd(a, n);
	}

	return 0;
}