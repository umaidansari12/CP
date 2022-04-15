/*
Given a set of N jobs where each job i has a deadline and profit associated to it.
Each job takes 1 unit of time to complete and only one job can be scheduled at a time.
We earn the profit if and only if the job is completed by its deadline.
The task is to find the maximum profit and the number of jobs done.

Input:
The first line of input contains an integer T denoting the number of test cases.
In each test case, first line consists of an integer N denoting the number of jobs.
Second line will be of the format A1, B1, C1, A2, B2, C2..... AN, BN, CN,
where Ai, Bi and Ci denote the ID, deadline and profit from the ith job respectively.

Output:
Output the number of jobs done and the maximum profit seperated by a space in a different
line for each test case.

Constraints:
1 <= T <= 100
1 <= N <= 100
1 <= Deadline <= 100
1 <= Profit <= 500

Example:
Input:
2
4
1 4 20 2 1 10 3 1 40 4 1 30
5
1 2 100 2 1 19 3 2 27 4 1 25 5 1 15

Output:
2 60
2 127

Explanation:
Test Case 1: You can do job 3 followed by the job 1. The overall profit = 40 + 20 = 60
Test Case 2: You can do job 1 followed by the job 3. The overall profit = 100 + 27 = 127*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
	static bool comp(Job a, Job b)
	{
		return (a.profit > b.profit);
	}
	vector<int> JobScheduling(Job arr[], int n)
	{
		// your code here
		sort(arr, arr + n, comp);
		int profit = 0, count = 0, m = 0;
		for (int i = 0; i < n; i++)
			m = max(m, arr[i].dead);
		vector<int> job_sequence(m + 1, -1);
		for (int i = 0; i < n; i++)
		{
			for (int j = arr[i].dead; j > 0; j--)
			{
				if (job_sequence[j] == -1)
				{
					job_sequence[j] = arr[i].id;
					count++;
					profit += arr[i].profit;
					break;
				}
			}
		}
		vector<int> res;
		res.push_back(count);
		res.push_back(profit);
		return res;

	}
};

bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.second > b.second;
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
		bool slot[n] = {false};
		vector<pair<int, int>> a;
		for (int i = 0; i < n; i++)
		{
			int id, dead, pro;
			cin >> id >> dead >> pro;
			a.push_back(make_pair(dead, pro));
		}
		sort(a.begin(), a.end(), cmp);
		/*for (int i = 0; i < n; i++)
			cout << a[i].first << " " << a[i].second << endl;
		cout << "Done\n";*/
		int profit = 0, size = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = min(n, a[i].first) - 1; j >= 0; j--)
			{
				if (slot[j] == false)
				{
					slot[j] = true;
					size++;
					profit += a[i].second;
					break;
				}
			}
		}
		cout << size << " " << profit << endl;

	}


	return 0;
}