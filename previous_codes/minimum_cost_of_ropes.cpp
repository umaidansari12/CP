#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        long long cost = 0;
        priority_queue<long long, vector<long long>, greater<long long>> min_heap(arr, arr + n);
        while (min_heap.size() > 1)
        {
            long long A = min_heap.top();
            min_heap.pop();
            long long B = min_heap.top();
            min_heap.pop();
            cost += (A + B);
            min_heap.push((A + B));
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
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends