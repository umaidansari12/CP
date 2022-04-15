#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
public:
	//Function to return the minimum cost of connecting the ropes.
	long long minCost(long long arr[], long long n, long long k) {
		// Your code here
		long long cost = 0;
		priority_queue<long long, vector<long long>, greater<long long>> min_heap(arr, arr + n);
		while (min_heap.size() >= k)
		{
			long long curr_cost = 0;
			for (int i = 0; i < k; i++)
			{
				curr_cost += min_heap.top();
				min_heap.pop();
			}

			cost += (curr_cost);
			min_heap.push(curr_cost);
		}
		return cost;
	}
};


// { Driver Code Starts.
long long minCost(long long arr[], long long n);
int main() {
	long long t;
	cin >> t;
	while (t--) {
		long long n, k;
		cin >> n >> k;
		long long i, a[n];
		for (i = 0; i < n; i++) {
			cin >> a[i];
		}
		Solution ob;
		cout << ob.minCost(a, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends