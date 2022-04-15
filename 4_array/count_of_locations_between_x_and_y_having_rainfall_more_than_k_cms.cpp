#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Rainfall {
public:
	int start, end, rain;
};

vector<int> countLocations(vector<Rainfall> &rainfall, int n, vector<pair<int, int> > &queries, int q, int k, int max_ending) {
	vector<int> rains(max_ending + 2, 0);
	for (int i = 0; i < n; i++) {
		rains[rainfall[i].start] += rainfall[i].rain;
		rains[rainfall[i].end + 1] -= rainfall[i].rain;
	}
	for (int i = 1; i <= max_ending; i++) {
		rains[i] += rains[i - 1];
	}

	vector<int> res;
	for (int i = 0; i < q; i++) {
		int count = 0;
		for (int j = queries[i].first; j <= queries[i].second; j++) {
			if (rains[j] >= k)
				count++;
		}
		res.push_back(count);
	}
	return res;
}

// C++ program for above approach
#include <bits/stdc++.h>
using namespace std;

// Comparator function to sort
// the array in specific order
static bool comp(vector<int> a, vector<int> b)
{
	return (a[1] > b[1]);
}

// Function to find number of locatins
// with rainfall  more than K cms
vector<int> count(vector<int> arr,
                  vector<vector<int> > Q,
                  int q, int k)
{

	// Prefix sum array,
	// of count of locations having
	// rainfall greater than k cms
	int n = arr.size();
	vector<int> arrPre(n);

	if (arr[0] >= k)
		arrPre[0] = 1;
	else
		arrPre[0] = 0;

	for (int i = 1; i < n; i++) {

		if (arr[i] >= k)
			arrPre[i] = arrPre[i - 1] + 1;

		else
			arrPre[i] = arrPre[i - 1];
	}

	// evaluating the queries
	vector<int> ans;
	for (int i = 0; i < q; i++) {
		ans.push_back(
		    arrPre[Q[i][1]]
		    - arrPre[Q[i][0] - 1]);
	}
	return ans;
}

// Function to find aggregate array
vector<int> aggregateArray(
    vector<vector<int> > N, int n)
{
	// To store the maximum location
	int m = 0;
	for (int i = 0; i < n; i++)
		m = max(m, N[i][1]);

	// Array to store rainfall
	// of m locations sorting
	// input array based on end time,
	// in descending order
	vector<int> arr(m + 1);
	sort(N.begin(), N.end(), comp);

	// To store start locn and
	// rainfall corresponding to it
	unordered_map<int, int> start;
	int overlap = 0;

	for (int i = 0; i < n; i++) {
		// If two inputs have same end time,
		// we need to reposition them
		if (m < N[i][1])
			m++;
		else
			// Fill m with overlap,
			// till we reach current end location,
			// and keep checking if we've crossed
			// start time of previously recorded data
			// and decreament overlap(map)
			while (m > 0 && m != N[i][1])
				overlap -= start[m],
				           arr[m--] = overlap;

		// To check if start time is crossed
		// of previously recorded data
		// and decreament overlap(map)
		overlap -= start[m];

		// Input data + previous recorded data
		arr[m] = overlap + N[i][2];

		// updating overlap with current data
		overlap += N[i][2];

		// storing start location with
		// corresponding rainfall data
		start[N[i][0] - 1] = N[i][2];

		// update m
		m--;
	}
	while (m >= N[n - 1][0])

		// fill out the left out indexes
		overlap -= start[m],
		           arr[m--] = overlap;
	return arr;
}

/*
The given problem can be solved by using the Weighted job scheduling approach and with Prefix Sum. This problem can be solved in two parts, forming aggregated array and then apply prefix sum for answering queries efficiently. Follow the steps below to solve the given problem.

Sort arr[][] on the basis of end location.
Use map data structure to store the start location and overlap count.
For each end location, update the aggregate array, by doing rainfall data + overlap.
Use Hashmaps for decrementing overlap, after the start location is crossed.
For each triplet update the Hashmap with the start time.
Traverse and fill overlap in the array until the end location of the next triplet is reached.
Once the aggregate array is found, use prefix sum to find the answer to each query.
*/

// Time Complexity: O(max(NlogN, M)).
// Auxiliary Space: O(M).
// Where N is number of inputs and M is maximum location.

// Driver Code
int main()
{
	int N = 4;
	vector<vector<int> > arr = {
		{ 1, 3, 5 }, { 2, 8, 3 },
		{ 5, 8, 2 }, { 7, 9, 6 }
	};
	vector<int> agg = aggregateArray(arr, N);

	int Q = 4;

	vector<vector<int> > queries
	= { { 1, 5 }, { 5, 9 },
		{ 2, 9 }, { 1, 9 }
	};
	int K = 5;
	vector<int> ans = count(agg, queries, Q, K);

	// Printing answer to each query
	for (int i = 0; i < N; i++) {
		cout << ans[i] << endl;
	}
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, q, k, max_ending = 0;
		cin >> n >> q >> k;
		vector<Rainfall> rainfall(n);
		for (int i = 0; i < n; i++) {
			cin >> rainfall[i].start >> rainfall[i].end >> rainfall[i].rain;
			cout << rainfall[i].start << ", " << rainfall[i].end << ", " << rainfall[i].rain << endl;
			max_ending = max(max_ending, rainfall[i].end);
		}
		vector<pair<int, int>> queries(q);
		for (int i = 0; i < q; i++) {
			cin >> queries[i].first >> queries[i].second;
		}
		vector<int> result = countLocations(rainfall, n, queries, q, k, max_ending);
		for (auto i : result) {
			cout << i << " ";
		}
		cout << endl;
	}


	return 0;
}