/*https://leetcode.com/problems/sum-of-subarray-minimums/discuss/170750/JavaC%2B%2BPython-Stack-Solution
https://leetcode.com/problems/sum-of-subarray-minimums/discuss/170750/JavaC%2B%2BPython-Stack-Solution
*/

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size(), mod = 1e9 + 7, sum = 0;
        for (int k = 1; k <= n; k++) {
            for (int i = 0; i < (n - k) + 1; i++) {
                int _min = INT_MAX;
                for (int j = i; j < (i + k); j++) {
                    _min = min(_min, arr[j]);
                }
                sum = (sum + _min) % mod;
            }
        }
        return sum;

    }
};

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size(), mod = 1e9 + 7, sum = 0;
        for (int k = 1; k <= n; k++) {
            deque<int> q(k);
            for (int i = 0; i < k; i++) {
                while (!q.empty() and arr[q.back()] >= arr[i]) {
                    q.pop_back();
                }
                q.push_back(i);
            }
            for (int i = k; i < n; i++) {
                sum = (sum + arr[q.front()]) % mod;
                while (!q.empty() and q.front() <= (i - k)) {
                    q.pop_front();
                }
                while (!q.empty() and arr[q.back()] >= arr[i]) {
                    q.pop_back();
                }
                q.push_back(i);
            }
            sum = (sum + arr[q.front()]) % mod;
        }
        return sum;

    }
};

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int size = arr.size(), mod = 1e9 + 7, sum = 0;
        // left is for the distance to previous less element
        // right is for the distance to next less element
        vector<int> left(size), right(size);
        for (int i = 0; i < size; i++) {
            left[i] = i + 1;
            right[i] = size - i;
        }
        stack<pair<int, int>> p, n;
        for (int i = 0; i < size; i++) {
            while (!p.empty() and p.top().first > arr[i])
                p.pop();
            left[i] = p.empty() ? i + 1 : i - p.top().second;
            p.push({arr[i], i});

            while (!n.empty() and n.top().first > arr[i]) {
                right[n.top().second] = i - n.top().second;
                n.pop();
            }
            n.push({arr[i], i});
        }
        for (int i = 0; i < size; i++) {
            sum = (sum + (long)arr[i] * left[i] * right[i]) % mod;
        }
        return sum;

    }
};