class Solution {
public:
    long long count_hours_required_to_eat_k_bananas(vector<int>& piles, int n, int k) {
        long long h = 0;
        for (int i = 0; i < n; i++) {
            h += ceil(piles[i] / double(k));
        }
        return h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;//*min_element(piles.begin(), piles.end()); //*max_element(piles.begin(), piles.end());
        int high = *max_element(piles.begin(), piles.end()); //accumulate(piles.begin(), piles.end(), 0);
        int n = piles.size();

        for (int k = low; k <= high; k++) {
            long long hours = count_hours_required_to_eat_k_bananas(piles, n, k);
            if (hours <= h)
                return k;
        }
        return low;
    }
};

class Solution {
public:
    long long count_hours_required_to_eat_k_bananas(vector<int>& piles, int n, int k) {
        long long h = 0;
        for (int i = 0; i < n; i++) {
            h += ceil(piles[i] / double(k));
        }
        return h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;//*min_element(piles.begin(), piles.end()); //*max_element(piles.begin(), piles.end());
        int high = *max_element(piles.begin(), piles.end()); //accumulate(piles.begin(), piles.end(), 0);
        int n = piles.size();

        while (low <= high) {
            int mid = (low + high) / 2;
            long long hours = count_hours_required_to_eat_k_bananas(piles, n, mid);
            if (hours <= h) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        // for(int k = low; k<=high;k++){
        // }
        return low;
    }
};