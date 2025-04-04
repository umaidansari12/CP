class Solution {
public:
    long long countTrips(vector<int> &time, long long int second) {
        long long trips_count = 0;
        for (auto x : time) {
            long long int val = x;
            trips_count += (second / val);
        }
        return trips_count;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long int min_time = 1, max_time = (long long int) * max_element(time.begin(), time.end()) * totalTrips;
        while (min_time < max_time) {
            long long int mid_time = min_time + (max_time - min_time) / 2;
            if (countTrips(time, mid_time) >= totalTrips) {
                max_time = mid_time;
            }
            else {
                min_time = mid_time + 1;
            }

        }
        return min_time;
    }
};