#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void sort_012(vector<int>& a, int n)
{
	vector<int> count(3);
	for (int i = 0; i < n; i++)
	{
		count[a[i]]++;
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < count[i]; j++)
		{
			cout << i << " ";
		}
	}
	cout << endl;
}
void sort012(vector<int> &a, int n)
{
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void Sort012(vector<int>&a, int n)
{
	for (int i = 0; i < n; i++)
	{
		a[a[i] % n] += n;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < a[i] / n; j++)
		{
			cout << i << " ";
		}
	}
	cout << endl;
}

void sort0(vector<int> &nums, int n)
{
	if (n == 0 || n == 1)
		return;
	int start = 0;
	int end = n - 1;
	int index = 0;
	while (index < n && end < n)
	{
		if (nums[index] == 0)
		{
			nums[index] = nums[start];
			nums[start] = 0;
			start++;
		}
		else if (nums[index] == 2)
		{
			nums[index] = nums[end];
			nums[end] = 2;
			end--;
		}
		else
		{
			index++;
		}

	}
	for (int i = 0; i < n; i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;
}

class Solution {
public:
	void sortColors(vector<int>& nums) {
		int n = nums.size();
		if (n == 0 || n == 1)
			return;
		int start = 0;
		int end = n - 1;
		int index = 0;
		while (index <= end && start < end)
		{
			if (nums[index] == 0)
			{
				nums[index] = nums[start];
				nums[start] = 0;
				start++;
				index++;
			}
			else if (nums[index] == 2)
			{
				nums[index] = nums[end];
				nums[end] = 2;
				//index++;
				end--;
			}
			else
			{
				index++;
			}
		}
	}
};

void dutchNationalFlag(vector <int> &a, int n)
{
	int low = 0, mid = 0, high = n - 1;
	while (mid <= high)
	{
		if (a[mid] == 0)
		{
			swap(a[mid++], a[low++]);
		}
		else if (a[mid] == 1)
		{
			mid++;
		}
		else if (a[mid] == 2)
		{
			swap(a[mid], a[high--]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void segregate01(vector <int> &a, int n)
{
	int i = 0, low = 0;
	while (i < n)
	{
		if (a[i] == 0)
		{
			swap(a[i++], a[low++]);
		}
		else
		{
			mid++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void sort012(int a[], int n)
{
	// coode here
	int low = 0, mid = 0, high = n - 1;
	while (mid <= high)
	{
		if (a[mid] == 0)
			swap(a[mid++], a[low++]);
		else if (a[mid] == 2)
			swap(a[mid], a[high--]);
		else
			mid++;
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
		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		dutchNationalFlag(a, n);
	}


	return 0;
}