#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
	int *findTwoElement(int *arr, int n) {
		// code here
		int a[n + 1];
		for (int i = 1; i <= n; i++)
			a[i] = 0;
		for (int i = 0; i < n; i++)
			a[arr[i]]++;
		int *res;
		res = (int*)malloc(2 * sizeof(int));
		for (int i = 0; i <= n; i++)
		{
			if (a[i] >= 2)
				res[0] = i;
			if (a[i] == 0)
				res[1] = i;
		}
		return res;
	}
};

void repeatingMissing(vector <int> &a, int n)
{
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++)
	{
		if (a[i] == a[i + 1])
		{
			cout << a[i] << " ";
			break;
		}

	}
	for (int i = 0; i < n; i++)
	{
		if (a[i + 1] == a[i])
		{
			cout << a[i] - 1 << endl;
			break;
		}
		if (a[i + 1] - a[i] > 1)
		{
			cout << a[i] + 1 << endl;
			break;
		}
	}
}

void repeating_missing(vector <int> &a, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[abs(a[i])] > 0)
			a[abs(a[i])] = -a[abs(a[i])];
		else
		{
			cout << abs(a[i]) << " ";
			break;
		}

	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0)
		{
			cout << (i + 1) << endl;
			break;
		}

	}
}
void repeatingmissing(vector<int> &a, int n)
{
	bool present[n + 1] = {false};
	ll repeating = 0, missing = 0;
	for (int i = 0; i < n; i++)
	{
		if (present[a[i]] == true)
			repeating = a[i];
		present[a[i]] = true;
	}
	for (int i = 1; i < n + 1; i++)
	{
		if (present[i] == false)
			missing = i;
	}
	cout << repeating << " " << missing << endl;
}
void RepeatedMissing(vector<int> &a, int n)
{
	ll s_n = n * (n + 1) / 2, s_sqn = (n * (n + 1) * (2 * n)) / 6;
	for (int i = 0; i < n; i++)
	{
		s_n -= (ll)a[i];
		s_sqn -= ((ll)a[i] * (ll)a[i]);
	}
	ll missing_number = (s_n + s_sqn / s_n) / 2;
	ll repeating = missing_number - s_n;
	cout << repeating << " " << missing_number << endl;
}
int main() {
	//code
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
		RepeatingMissing(a, n);
	}
	return 0;
}

vector<int> Solution::repeatedNumber(const vector<int> &A) {
	long long n = A.size();
	long long sn = ((long long)n * (long long)(n + 1)) / 2;
	long long sqn = ((long long)n * (long long)(n + 1) * ((long long)(2 * n) + 1)) / 6;
	for (long long i = 0; i < n; i++)
	{
		sn -= (long long)A[i];
		sqn -= ((long long)A[i] * (long long)A[i]);
	}
	long long m = (sn + (sqn / sn)) / 2;
	long long r = (m - sn);
	vector<int> res;
	res.push_back(r);
	res.push_back(m);
	return res;
}
