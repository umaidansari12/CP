#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*
You are given an array of ratings for n days. Find the number of groups that can be formed consisting of 1 or more consecutive days such that the ratings continously decreases over the days.
The rating is consecutively decreasing if it has the form r, r - 1, r - 2 ... and so on, where r is the rating on the first day of the group. Two groups are considered different if they contain the ratings of different consecutive days.
Example
ratings = [4,3,5,4,3] answer = 9
there are 9 periods in which the rating is consecutively decreasing
5 one day periods: [4],[3],[5],[4],[3]
3 two day periods: [4,3], [5,4], [4, 3]
1 three day period: [5, 4, 3]

ratings = [2, 1, 3] answer = 4
groups are [2],[1], [3], [2, 1]

ratings = [4,2,3,1] answer = 4
groups are [4], [2], [3], [1] are the only groups

Q1. We can iterate over array and maintain two pointers which will denote the start and end of decreasing sequence. Then we have n = r - l; and add count += n(n+1)/2 to it. So complexity will O(n) and space complexity O(1). For example in above array we start from 4 then move forward, pattern breaks at index 2 i.e 5. At this time l = 0 and r = 2, so n = 2, and we add 2 * 3 / 2 = 3 to count then make l = r and loop again this time we reach end of array i.e r = size of array. Again n = 5 - 2 = 3 and we add 3*4/2 = 6 so count = 3 + 6 = 9
*/


int consecutivelyDecreasingRating(int a[], int n) {
	int answer = 0;
	for (int k = 1; k <= n; k++) {
		for (int start = 0; start < (n - k) + 1; start++) {
			bool f = true;
			for (int end = start; end < (start + k) - 1; end++) {
				if ((a[end] - 1) != a[end + 1]) {
					f = false;
					break;
				}
			}
			if (f)
				answer++;
		}
	}
	return answer;
}


int consecutiveDecreasing(int arr[], int n) {
	if (n == 0)
		return 0;

	int left, right, total = 0;

	for (int i = 0; i < n; i++) {
		left = i, right = i;
		while (i < n - 1 && arr[i] - arr[i + 1] == 1) {
			i++;
			right = i;
		}
		int sequenceSize = right - left + 1;
		total += (sequenceSize * (sequenceSize + 1)) / 2;
	}
	return total;
}

int getTriangleNumber(int n) {
	int sum = 0;
	while (n != 0) {
		sum += n;
		n--;
	}
	return sum;
}

int countSequences(int ratings[], int n) {
	int count = 0;
	int current = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0 || ratings[i - 1] - ratings[i] == 1) {
			current++;
		}
		else {
			count += getTriangleNumber(current);
			current = 1;
		}
	}

	count += getTriangleNumber(current);
	return count;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		int a[n] = {0};
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		cout << consecutiveDecreasing(a, n) << endl;
		cout << consecutivelyDecreasingRating(a, n) << endl;
	}


	return 0;
}