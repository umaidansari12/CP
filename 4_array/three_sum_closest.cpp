
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution {
public:
    int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
        int closest_diff = INT_MAX, ans = 0;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            int left = i + 1, right = n - 1;
            int element = arr[i];
            while (left < right)
            {
                int sum = arr[left] + arr[right];
                int diff = abs((sum + element) - target);
                if (diff < closest_diff)
                {
                    closest_diff = diff;
                    ans = sum + element;
                }
                else if (diff == closest_diff)
                {
                    ans = max(ans, sum + element);
                }
                if ((sum + element) == target)
                {
                    return (sum + element);
                }
                else if ((sum + element) < target)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
        return ans;
    }
};



// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int n, target;
        cin >> n >> target;

        vector<int> vec(n);

        for (int i = 0 ; i < n ; ++ i )
            cin >> vec[i];
        Solution obj;
        cout << obj.threeSumClosest(vec, target) << "\n";
    }
}

//Position this line where user code will be pasted.
// } Driver Code Ends