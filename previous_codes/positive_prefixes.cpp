/*#include <bits/stdc++.h>

using namespace std;
using ll = long long;

You are given two positive integers N and K, where K≤N. Find a sequence A1,A2,…,AN such that:

for each valid i, Ai is either i or −i
there are exactly K values of i such that 1≤i≤N and A1+A2+…+Ai>0
If there are multiple solutions, you may print any one of them. It can be proved that at least one solution always exists.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains two space-separated integers N and K.
Output
For each test case, print a single line containing N space-separated integers A1,A2,…,AN.

Constraints
1≤T≤1,000
1≤K≤N≤1,000
Subtasks
Subtask #1 (10 points): N≤10
Subtask #2 (90 points): original constraints

Example Input
1
3 3


int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		signed int v[1001];
		for (int i = 0; i < n; i++)
		{
			v[i] = i + 1;
		}
		if (n % 2 == 0)
		{
			for (int i = 0; i < n; i++)
			{
				if (v[i] % 2 == 1)
				{
					v[i] = (-v[i]);
				}
			}
		}
		else if (n % 2 == 1)
		{
			for (int i = 0; i < n; i++)
			{
				if (v[i] % 2 == 1)
				{
					v[i] = (-v[i]);
				}
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if (v[i] > 0)
				cnt++;
		}
		if (k > cnt)
		{
			int dif = k - cnt;
			for (int i = n - 1; i >= 0; i--)
			{
				if (dif > 0 && v[i] < 0)
				{
					v[i] = abs(v[i]);
					dif--;
				}

			}
		}
		else if (cnt > k)
		{
			int dif = cnt - k;
			for (int i = n - 1; i >= 0; i--)
			{
				if (dif > 0 && v[i] > 0)
				{
					v[i] = (-v[i]);
					dif--;
				}

			}
		}
		for (int i = 0; i < n; i++)
			cout << v[i] << " ";
		cout << endl;

	}


	return 0;
}
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n, k;
		cin >> n >> k;
		vector<int> r;
		for (int i = 1; i <= n; i++)
		{
			if (i % 2 == 0)
				r.push_back(i);
			else
				r.push_back(-i);
		}
		int count = (n / 2);
		if (count < k)
		{
			int dif = k - count, i = n - 1;
			while (dif > 0)
			{
				if (r[i] < 0)
				{
					r[i] *= (-1);
					dif--;
				}
				i--;
			}
		}
		else if (count > k)
		{
			int dif = count - k, i = n - 1;
			while (dif > 0)
			{
				if (r[i] > 0)
				{
					r[i] *= (-1);
					dif--;
				}

				i--;
			}
		}
		for (int i = 0; i < n; i++)
			cout << r[i] << " ";
		cout << endl;
	}


	return 0;
}