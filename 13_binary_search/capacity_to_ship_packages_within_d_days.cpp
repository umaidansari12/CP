class Solution {
public:
    int number_of_days_to_ship_m_weight(vector<int> weights, int max_weight) {
        int days = 1, sum = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (sum + weights[i] > max_weight) {
                sum = 0;
                days++;
            }
            sum += weights[i];
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int min_weight = 0, max_weight = 0, mid = 0;

        for (int i = 0; i < weights.size(); i++) {
            max_weight += weights[i];
            min_weight = max(min_weight, weights[i]);
        }

        while (min_weight < max_weight) {
            mid = (min_weight + max_weight) / 2;
            int no_of_days = number_of_days_to_ship_m_weight(weights, mid);

            if (no_of_days <= days) {
                max_weight = mid;
            }
            else {
                min_weight = mid + 1;
            }
        }
        return min_weight;
    }
};