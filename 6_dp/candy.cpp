class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum = 0, n = ratings.size();
        for (int i = 0; i < n; i++) {
            int left = 0, right = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (ratings[j] < ratings[j + 1])
                    left++;
                else
                    break;
            }
            for (int j = i + 1; j < n; j++) {
                if (ratings[j] < ratings[j - 1])
                    right++;
                else
                    break;
            }
            sum += max(left, right) + 1;
        }
        return sum;

    }
};

class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum = 0, n = ratings.size();
        vector<pair<int, int>> chain(n, {0, 0});
        chain[0].first = 1;
        chain[n - 1].second = 1;
        for (int i = 1; i < n; i++) {
            if (ratings[i - 1] < ratings[i]) {
                chain[i].first = chain[i - 1].first + 1;
            }
            else {
                chain[i].first = 1;
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i + 1] < ratings[i]) {
                chain[i].second = chain[i + 1].second + 1;
            }
            else {
                chain[i].second = 1;
            }
        }
        for (int i = 0; i < n; i++)
            sum += max(chain[i].first, chain[i].second);
        return sum;

    }
};