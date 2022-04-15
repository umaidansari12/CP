// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int offerings(int N, int arr[]) {
        // code here
        int sum = 0;
        for (int i = 0; i < N; i++) {
            int left = 0, right = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (arr[j] < arr[j + 1])
                    left++;
                else
                    break;
            }
            for (int j = i + 1; j < N; j++) {
                if (arr[j] < arr[j - 1])
                    right++;
                else
                    break;
            }
            sum += max(right, left) + 1;
        }
        return sum;
    }

    int offerings(int N, int arr[]) {
        // code here
        vector<pair<int, int>> chain(N, {0, 0});
        chain[0].first = 1;
        chain[N - 1].second = 1;
        for (int i = 1; i < N; i++) {
            if (arr[i - 1] < arr[i]) {
                chain[i].first = chain[i - 1].first + 1;
            }
            else {
                chain[i].first = 1;
            }
        }

        for (int i = N - 2; i >= 0; i--) {
            if (arr[i + 1] < arr[i]) {
                chain[i].second = chain[i + 1].second + 1;
            }
            else {
                chain[i].second = 1;
            }
        }
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += max(chain[i].first, chain[i].second);
        }
        return sum;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.offerings(N, arr) << "\n";
    }
    return 0;
}  // } Driver Code Ends