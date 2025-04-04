// Back-end complete function Template for C++

class Solution {
public:
  long long solve(vector<int>& bt) {
    // code here
    sort(bt.begin(), bt.end());
    long long start_time = 0, avg_waiting_time = 0, n = bt.size();
    for (int i = 0; i < n; i++)
    {
      avg_waiting_time += start_time;
      start_time += bt[i];
    }
    return avg_waiting_time / n;
  }
};