class Solution {
public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> &v, long long n, long long x) {

        // Your code here
        int start = 0, mid, end = n - 1, lower_bound = -1;
        while (start <= end) {
            mid = (start + end) / 2;
            if (v[mid] <= x) {
                lower_bound = mid;
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return lower_bound;
    }
};
