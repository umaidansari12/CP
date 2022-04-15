#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*
Number of possible encoded copies
For an array, another array is considered as a encoded if the difference between consecutive elements is same for both. Given an array of consecutive differnces, lowerbound and upperbound value, return the number of possibile copies such that all the elements lay in range of lowerbound and upperbound(both included). If there is no possibility return 0.

EDIT:
For second question, we will be provided a list of integers (difference between consecutive elements of an array), a lowerbound(int) and an upperbound(int). We have to return number of possible arrays such that all the elements are in the range [lowerbound, upperbound] and having same consecutive element differences as given list.
I can only think of brutal force. The start point from lowerBound to upperBound, and form the list. But if the lowerBound and upperBound are far apart, this would be TLE.
Especiallly we need to think if there is negative numbers in the given list.


An array is said to be analogous to the secret array if all of the following conditions are true:
• The length of the array is equal to the length of the secret array.
• Each integer in the array lies in the interval [lowerBound, upperBound].
• The difference between each pair of consecutive integers of the array must be equal to the difference between the respective pair of consecutive integers in the secret array. In other words, let the secret array be [s[0], s[1],..., s[n-1]] and let the analogous array be [a[0], a[1],..., a[n-1]], then (a[i-1] - a[i]) must be equal to (s[i-1] - s[i]) for each i from 1 to n -1.

Given the value of integers lowerBound and upperBound, inclusive, and the array of differences between each pair of consecutive integers of the secret array, find the number of arrays that are analogous to the secret array. If there is no array analogous to the secret array, return 0.

For example:
consecutiveDifference = [-2, -1, -2, 5]
lowerBound = 3
upperBound = 10

Note that none of the values is out of the bound. All possible analogous arrays are:
[3, 5, 6, 8, 3]
[4, 6, 7, 9, 4]
[5, 7, 8, 10, 5]

Tha answer is 3.
*/

vector<vector<int>> secretArray(int a[], int n, int lowerBound, int upperBound) {
	vector<vector<int>> secretArray;
	for (int start = lowerBound; start <= upperBound; start++) {
		bool f = true;
		vector<int> temp(n + 1, 0);
		temp[0] = start;
		for (int i = 1; i <= n; i++) {
			int sum = temp[i - 1] - a[i - 1];
			if (sum <= upperBound) {
				temp[i] = temp[i - 1] - a[i - 1];
			}
			else {
				f = false;
				break;
			}
		}
		if (f)
			secretArray.push_back(temp);
	}
	return secretArray;
}


int secretArrayOptimal(int a[], int n, int lowerBound, int upperBound) {
	int max_sum = 0, min_sum = 0, sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		max_sum = max(sum, max_sum);
		min_sum = min(min_sum, sum);
	}

	int result = upperBound - lowerBound + (min_sum - max_sum + 1);
	if (result < 0)
		return 0;
	return result;
}


int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// if (lower_bound + sum(differences) > upper_bound) { return 0; }
	// else { return upper_bound - lower_bound - sum(differences) + 1; }

	int t;
	cin >> t;
	while (t--) {
		int n, lowerBound, upperBound;
		cin >> n;
		int a[n] = {0};
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		cin >> lowerBound >> upperBound;

		vector<vector<int>> ans = secretArray(a, n, lowerBound, upperBound);

		cout << secretArrayOptimal(a, n, lowerBound, upperBound) << endl;
		for (int i = 0; i < ans.size(); i++) {
			for (auto j : ans[i])
				cout << j << " ";
			cout << endl;
		}
	}
	return 0;
}