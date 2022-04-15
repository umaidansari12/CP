/*
Given arrival and departure times of all trains that reach a railway station. Your task is
to find the minimum number of platforms required for the railway station so that no train
waits.

Note: Consider that all the trains arrive on the same day and leave on the same day. Also,
arrival and departure times will not be same for a train, but we can have arrival time of
one train equal to departure of the other. In such cases, we need different platforms,
i.e at any given instance of time, same platform can not be used for both departure of a
train and arrival of another.

Input:
The first line of input contains T, the number of test cases. For each test case, first
line will contain an integer N, the number of trains. Next two lines will consist of N
space separated time intervals denoting arrival and departure times respectively.
Note: Time intervals are in the 24-hour format(hhmm),  of the for HHMM , where the
first two charcters represent hour (between 00 to 23 ) and last two characters represent
minutes (between 00 to 59).

Output:
For each test case, print the minimum number of platforms required for the trains to
arrive and depart safely.

Constraints:
1 <= T <= 100
1 <= N <= 1000
1 <= A[i] < D[i] <= 2359

Example:
Input:
2
6
0900  0940 0950  1100 1500 1800
0910 1200 1120 1130 1900 2000
3
0900 1100 1235
1000 1200 1240

Output:
3
1

Explanation:
Testcase 1: Minimum 3 platforms are required to safely arrive and depart all trains.


1.The idea is to consider all events in sorted order.
Once we have all events in sorted order, we can trace the number of trains
at any time keeping track of trains that have arrived, but not departed.

2.To be more precise it will be useful to make multimap to store
all arrival and departure times in it. The first value of element in
multimap tells the arrival/departure time and second value tells whether
 it’s arrival or departure represented by ‘a’ or ‘d’ respectively.
If its arrival then do increment by 1 otherwise decrease value by 1.

3. Step1: create multimap
    Step2: store all arrival & departure times in it.
    Step3: Traverse map and if second value of map is 'a' then platform required will increment by 1, otherwise decrement by 1.
    Step4: keep update the maximum platform needed after each inc/dec operations.

*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool customsort(const pair<int, char> &a, const pair<int, char> &b)
{
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

//Position this line where user code will be pasted.
// Driver code

int findPlatform(int arr[], int dep[], int n)
{
	// Insert all the times (arr. and dep.)
	// in the vector of pairs.
	vector< pair<int, char> > order;
	for (int i = 0; i < n; i++) {

		// If its arrival then second value
		// of pair is 'a' else 'd'
		order.push_back(make_pair(arr[i], 'a'));
		order.push_back(make_pair(dep[i], 'd'));
	}

	// custom sort order vector, first by time than by
	// arrival or departure
	sort(order.begin(), order.end(), customsort);

	int result = 1;
	int plat_needed = 0;

	vector< pair<int, char> >::iterator it = order.begin();

	// Start iterating the multimap.
	for (; it != order.end(); it++) {
		// If its 'a' then add 1 to plat_needed
		// else minus 1 from plat_needed.
		if ((*it).second == 'a')
			plat_needed++;
		else
			plat_needed--;

		if (plat_needed > result)
			result = plat_needed;
	}
	return result;
}

int findPlatform(int arr[], int dep[], int n)
{
	// Your code here
	sort(arr, arr + n);
	sort(dep, dep + n);
	int i = 1, j = 0, plat = 1, maxi = 1;
	while (i < n && j < n)
	{
		if (arr[i] <= dep[j])
		{
			plat++;
			i++;
		}
		else//else if (arr[i] > dep[j])
		{
			j++;
			plat--;
		}
		maxi = max(plat, maxi);
	}
	return maxi;
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
		vector<int> a(n), d(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < n; i++)
			cin >> d[i];
		sort(a.begin(), a.end());
		sort(d.begin(), d.end());
		int i = 1, j = 0, p = 1, r = 1;
		while (i < n && j < n)
		{
			if (a[i] <= d[j])
			{
				p++;
				i++;
			}
			else if (a[i] > d[j])
			{
				j++;
				p--;
			}
			r = max(p, r);
		}
		cout << r << endl;
	}


	return 0;
}