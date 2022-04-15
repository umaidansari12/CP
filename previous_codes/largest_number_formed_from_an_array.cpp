#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](const int a, const int b) {
            string f = to_string(a) + to_string(b);
            string l = to_string(b) + to_string(a);
            return f > l;
        });
        string s;
        if (nums[0] == 0)
            return "0";
        for (auto i : nums)
            s += to_string(i);
        return s;
    }
};


// } Driver Code Ends
//User function template for C++
class Solution {
public:
    // The main function that returns the arrangement with the largest value as
    // string.
    // The function accepts a vector of strings
    string printLargest(vector<string> &arr) {
        // code here
        sort(arr.begin(), arr.end(), [](string a, string b)
        {
            return a + b > b + a;
        });
        string res;
        for (auto i : arr)
            res += i;
        return res;
    }
    static bool compare(string a, string b)
    {
        return a + b > b + a;
    }
    string printLargest(vector<string> &arr) {
        // code here
        sort(arr.begin(), arr.end(), compare);
        string res;
        for (auto i : arr)
            res += i;
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<string> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printLargest(arr);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends