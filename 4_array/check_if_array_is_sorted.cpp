// brute

class Solution {
public:
    bool arraySortedOrNot(int arr[], int n) {
        // code here
        // create a sorted copy of arr and check one by one if elements of all index are same or not
        // TC - o(n) + o(nlogn) + o(N)
        // SC - O(N)
        vector<int> a(arr, arr + n);
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) {
            if (arr[i] != a[i])
                return false;
        }
        return true;
    }
};

// optimal

// User function template for C++

class Solution {
public:
    bool arraySortedOrNot(int arr[], int n) {
        // code here
        // check if prev element is lesser than or equal to current element, if not then not sorted
        // tc - o(n)
        // sc - o(1)
        for (int i = 1; i < n; i++) {
            if (arr[i] < arr[i - 1])
                return false;
        }
        return true;
    }
};