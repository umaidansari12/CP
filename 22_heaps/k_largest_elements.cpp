#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
vector<int> kLargest(int arr[], int n, int k)
{
    // code here
    vector<int> ans;
    sort(arr, arr + n, greater<int>());
    for (int i = 0; i < k; i++)
        ans.push_back(arr[i]);
    return ans;
}
vector<int> kLargest(int arr[], int n, int k)
{
    // code here
    vector<int> ans;
    sort(arr, arr + n);
    for (int i = n - 1; i >= n - k; i--)
        ans.push_back(arr[i]);
    return ans;
}
vector<int> kLargest(int arr[], int n, int k)
{
    // code here
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < n; i++) {
        q.push(arr[i]);
    }
    vector<int> r;
    int times = n - k;
    while (times--) {
        q.pop();
    }
    while (k--) {
        r.push_back(q.top());
        q.pop();
    }
    reverse(r.begin(), r.end());
    return r;
}
vector<int> kLargest(int arr[], int n, int k)
{
    // code here
    vector<int> r;
    priority_queue<int, vector<int>> p;
    for (int i = 0; i < n; i++)
        p.push(arr[i]);
    while (k--)
    {
        r.push_back(p.top());
        p.pop();
    }
    return r;
}

// { Driver Code Starts.
vector<int> kLargest(int arr[], int n, int k);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        vector<int> result = kLargest(arr, n, k);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

    }
    return 0;
}
// } Driver Code Ends